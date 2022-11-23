#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <random>

#include "dataset.h"
using namespace std;


const char* PATH_TRAIN_LABELS = "train-labels-idx1-ubyte";
const char* PATH_TRAIN_IMAGES = "train-images-idx3-ubyte";
const char* PATH_TEST_LABELS = "t10k-labels-idx1-ubyte";
const char* PATH_TEST_IMAGES = "t10k-images-idx3-ubyte";


dataset::dataset(){;}


dataset::~dataset(){;}


void dataset::load_dataset() {
	ifstream fin;
	uint32_t MN, N, A, B;

	/*---------------------*\
	\*---------------------*/

	fin = ifstream(PATH_TRAIN_LABELS, ios_base::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	N = __builtin_bswap32(N)/3;
	
	if (MN != 0x01080000) {
		cerr << "Invalid database" << endl;
		exit(1);
	}

	train_labels.resize(N);
	fin.read((char*)train_labels.data(), N * sizeof(uint8_t));

	/*---------------------*\
	\*---------------------*/

	fin = ifstream(PATH_TRAIN_IMAGES, ios_base::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	fin.read((char*)&A, sizeof(A));
	fin.read((char*)&B, sizeof(B));

	N = __builtin_bswap32(N)/3;
	A = __builtin_bswap32(A);
	B = __builtin_bswap32(B);

	if (MN != 0x03080000 || A != COLS || B != ROWS) {
		cerr << "invalid database" << endl;
		exit(1);
	}

	train_images.resize(N);
	fin.read((char*)train_images.data(), N * sizeof(array<uint8_t, PIXELS>));

	/*---------------------*\
	\*---------------------*/

	fin = ifstream(PATH_TEST_LABELS, ios_base::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	N = __builtin_bswap32(N)/3;

	if (MN != 0x01080000) {
		cerr << "Invalid database" << endl;
		exit(1);
	}

	test_labels.resize(N);
	fin.read((char*)test_labels.data(), N * sizeof(uint8_t));

	/*---------------------*\
	\*---------------------*/

	fin = ifstream(PATH_TEST_IMAGES, ios_base::binary);
	fin.read((char*)&MN, sizeof(MN));
	fin.read((char*)&N, sizeof(N));
	fin.read((char*)&A, sizeof(A));
	fin.read((char*)&B, sizeof(B));

	N = __builtin_bswap32(N)/3;
	A = __builtin_bswap32(A);
	B = __builtin_bswap32(B);

	if (MN != 0x03080000 || A != COLS || B != ROWS) {
		cerr << "invalid database" << endl;
		exit(1);
	}

	test_images.resize(N);
	fin.read((char*)test_images.data(), N * sizeof(array<uint8_t, PIXELS>));
}


void dataset::remove_some_train_data(const uint8_t digit, const size_t size){
	// START OF YOUR IMPLEMENTATION
	size_t size_count = size;
	// record ending points
	vector<uint8_t>::iterator label_iter = train_labels.end();	
	vector<array<uint8_t, PIXELS>>::iterator image_iter = train_images.end();

	while (size_count != 0) {
		label_iter--;
		image_iter--;

		if (*label_iter == digit) {
			size_count--;
			label_iter = train_labels.erase(label_iter);
			image_iter = train_images.erase(image_iter);
		}
	}
	// END OF YOUR IMPLEMENTATION
}


void dataset::append_some_augmented_train_data(const uint8_t digit, const size_t size){
    vector<size_t> indices;
	unsigned int counter = 0;

    for (vector<uint8_t>::iterator it = train_labels.begin(); it != train_labels.end(); it++) {
        if (*it == digit){
			indices.push_back(distance(train_labels.begin(), it));
		}
    }

	vector<size_t>::iterator it2 = indices.begin();
	while(counter<size){	
		++counter;

		train_images.push_back(this->compound_augment_image(train_images[*it2]));
		train_labels.push_back(digit);
		
		it2++;
		if(it2 == indices.end())
			it2 = indices.begin();
	}
}


array<uint8_t, PIXELS> dataset::compound_augment_image(array<uint8_t, PIXELS>& img_ar){
	img_dt img = convert_image_dt(img_ar);
	size_t rand_num = rand()% 8;
	this->shift_image(img, shift_type(rand_num), rand()% 4);

	rand_num = rand()% 9 + ROWS - 4;
	this->resize_image(img, rand_num, rand_num);
	if(rand_num>ROWS){
		this->crop_image(img, (rand_num-ROWS)/2, (rand_num-COLS)/2, ROWS, COLS);
	}
	else{
		this->padding_image(img, (ROWS-rand_num)/2, ROWS-(ROWS-rand_num)/2-rand_num, (COLS-rand_num)/2, COLS-(COLS-rand_num)/2-rand_num);
	}

	array<uint8_t, PIXELS> img_ar_out = convert_image_dt(img);

	return img_ar_out;
}


void dataset::shift_image(img_dt& img, const enum shift_type dir, const size_t p, const uint8_t value){
	// START OF YOUR IMPLEMENTATION
	int r = img.size();
	int c = img.at(0).size();

	if(dir == UP){
		crop_image(img, p, 0, r-p, c);
		padding_image(img, 0, p, 0, 0, value);
	}
	else if(dir == DOWN){
		crop_image(img, 0, 0, r-p, c);
		padding_image(img, p, 0, 0, 0, value);
	}
	else if(dir == LEFT){
		crop_image(img, 0, p, r, c-p);
		padding_image(img, 0, 0, 0, p, value);
	}
	else if(dir == RIGHT){
		crop_image(img, 0, 0, r, c-p);
		padding_image(img, 0, 0, p, 0, value);
	}
	if(dir == UPLEFT){
		shift_image(img, LEFT, p, value);
		shift_image(img, UP, p, value);
	}
	else if(dir == DOWNLEFT){
		shift_image(img, LEFT, p, value);
		shift_image(img, DOWN, p, value);
	}
	else if(dir == UPRIGHT){
		shift_image(img, RIGHT, p, value);
		shift_image(img, UP, p, value);
	}
	else if(dir == DOWNRIGHT){
		shift_image(img, RIGHT, p, value);
		shift_image(img, DOWN, p, value);
	}
	// END OF YOUR IMPLEMENTATION
}


void dataset::resize_image(img_dt& img, const size_t new_rows, const size_t new_cols){
	// START OF YOUR IMPLEMENTATION
	int r = img.size();
	int c = img.at(0).size();
	
	img_dt target_size(new_rows, deque<uint8_t>(new_cols, 0));
	for (int i = 0; i < new_rows; ++i) {
		for (int j = 0; j < new_cols; ++j) {
			target_size[i][j] = img[(int) ((double) (i+0.5)/new_rows*r)][(int) ((double)(j + 0.5)/new_cols*c)];	// big brain formula
		}
	}
	img = target_size;	
	// END OF YOUR IMPLEMENTATION
}


void dataset::crop_image(img_dt& img, const size_t y0, const size_t x0, const size_t new_rows, const size_t new_cols){
	// START OF YOUR IMPLEMENTATION
	img.erase(img.begin(), img.begin() + y0);
	img.erase(img.begin() + new_rows, img.end());

	for (img_dt::iterator iter = img.begin(); iter != img.end(); ++iter) {
		iter->erase(iter->begin(), iter->begin() + x0);
		iter->erase(iter->begin() + new_cols, iter->end());
	}
	// END OF YOUR IMPLEMENTATION
}


void dataset::padding_image(img_dt& img, const size_t top, const size_t down, const size_t left, const size_t right, const uint8_t value){
	// START OF YOUR IMPLEMENTATION
	int new_size = 0;
	new_size = img.at(0).size() + left + right;

	for (img_dt::iterator iter = img.begin(); iter != img.end(); ++iter) {	// padding
		iter->insert(iter->begin(), left, value);
		iter->insert(iter->end(), right, value);
	}

	deque<uint8_t> temp(new_size, value);
	img.insert(img.begin(), top, temp);
	img.insert(img.end(), down, temp);
	// END OF YOUR IMPLEMENTATION
}


uint8_t	dataset::get_a_label(const data_type mode, const size_t index) const{
	switch(mode){
		case TRAIN_LABEL: 
			return train_labels[index];		break;
		case TEST_LABEL: 
			return test_labels[index];		break;
		default:
			throw invalid_argument( "Invalid mode!");
	}
}


img_dt dataset::convert_image_dt(const array<uint8_t, PIXELS>& img) const {
	// START OF YOUR IMPLEMENTATION
	img_dt value;
	value.resize(ROWS);
	for (int i = 0; i < ROWS; ++i) {
		value.at(i).resize(COLS);
	}
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			value[i][j] = img[j + i*ROWS];
		}
	}	
	return value;	
	// END OF YOUR IMPLEMENTATION
}


array<uint8_t, PIXELS>  dataset::convert_image_dt(const img_dt& img) const {
	// START OF YOUR IMPLEMENTATION
	array<uint8_t, PIXELS> value;

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			value[j + i * ROWS] = img[i][j];
		}
	}	
	return value;
	// END OF YOUR IMPLEMENTATION
}


array<uint8_t, PIXELS>	dataset::get_an_image(const enum data_type mode, const size_t index) const{
	switch(mode){
		case TRAIN_IMAGE:
			return train_images[index];		break;
		case TEST_IMAGE: 
			return test_images[index];		break;
		default:
			throw invalid_argument( "Invalid mode!");
	}
}


vector<float>	dataset::get_a_normalized_image(const enum data_type mode, const size_t index) const{
	const array<uint8_t, PIXELS>& img = this->get_an_image(mode, index);
	vector<float> img_normalized(PIXELS);

	transform(img.begin(), img.end(), img_normalized.begin(), normalize(255.0f));
	return img_normalized;
}


size_t	dataset::get_data_size(const enum data_type mode) const{
	switch(mode){
		case TRAIN_LABEL: 
			return train_labels.size();		break;
		case TEST_LABEL:
			return test_labels.size();		break;
		case TRAIN_IMAGE: 
			return train_images.size();		break;
		case TEST_IMAGE: 
			return test_images.size();		break;
		default:
			throw invalid_argument( "Invalid mode!");
	}
}


void dataset::print_image(const array<uint8_t, PIXELS>& img_ar) const {
	// START OF YOUR IMPLEMENTATION
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			printf("%4d", img_ar[j + COLS * i]);
		}
		cout << endl;
	}
	// END OF YOUR IMPLEMENTATION
}


void dataset::print_image(const img_dt& img) const {
	// START OF YOUR IMPLEMENTATION
	int r = img.size();
	int c = img.at(0).size();

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%4d", img[i][j]);
		}
		cout << endl;
	}
	// END OF YOUR IMPLEMENTATION
}


void dataset::print_statistic(const enum data_type mode) const{
	// START OF YOUR IMPLEMENTATION
	int statistics[10] = {0};

	if(mode == TRAIN_IMAGE){
		for (vector<uint8_t>::const_iterator iter = train_labels.begin(); iter != train_labels.end(); ++iter) {
			statistics[*iter]++;
		}
		for (int i = 0; i <= 9; ++i) {
			cout << "Number of train images for digit " << i << ": " << statistics[i] << endl;
		}
	}
	else if(mode == TEST_IMAGE){
		for (vector<uint8_t>::const_iterator iter = test_labels.begin(); iter != test_labels.end(); ++iter) {
			statistics[*iter]++;
		}
		for (int i = 0; i <= 9; ++i) {
			cout << "Number of test images for digit " << i << ": " << statistics[i] << endl;
		}
	}
	// END OF YOUR IMPLEMENTATION
}
