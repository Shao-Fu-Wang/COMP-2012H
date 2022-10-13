#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

const int MAX_STRLEN = 1000;
const int NUM_CHARS_PER_LINE = 50;
const int MAX_LINES = 15;
int tar_lineiter = 0;

int countCharacters(const char str[]);
int countWords(const char str[]);
int countNumOccurences(const char str[], const char target[]);

void swapString(char str[], const char target[], const char to[]);
void encryptText(char str[], int shift);

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE]);
void printRightJustified(const char str[]);
void printLeftJustified(const char str[]);

void convertStrToPigLatin(char word[]);
void printPigLatin(const char str[]);

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes start here. Please do not modify codes above
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++

int countCharacters(const char str[])
{
    int sum = 0;
    for(int i = 0; ; i++){
        if(str[i] != '\0'){
            sum++;
        }
        else{
            break;
        }
    }
    return sum; // Replace this line with your implementation
}

int countWords(const char str[])
{
    int sum = 0;
    if((str[0] == 45) || ((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122))){   //starts with letter
        sum = 1;
    }
    else{
        sum = 0;
    }
    for(int i = 1; ; i++){
        if(str[i] == '\0'){
            break;
        }
        else if((str[i-1] != 45) && (str[i-1]<65 || str[i-1]>90) && (str[i-1]<97 || str[i-1]>122)  && ((str[i] == 45) || ((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)))){
            sum++;
        }
    }
    return sum; // Replace this line with your implementation
}

void swapString(char str[], const char target[], const char to[])
{
    int smark = 0;
    int tmark = 0;
    int headloc[MAX_STRLEN] = {};
    int headloc_iter = 0;
    int tailloc[MAX_STRLEN] = {};
    for(int i = 0; i < MAX_STRLEN; i++){
        headloc[i] = MAX_STRLEN+1;
        tailloc[i] = MAX_STRLEN+1;
    }
    int tailloc_iter =  0;
    int loc_recorded = 0;
    while(str[smark] != '\0'){
        while(target[tmark] == str[smark] && target[tmark] != '\0' &&str[smark] != '\0'){
            if(loc_recorded == 0){
                headloc[headloc_iter] = smark;
                loc_recorded = 1;
            }
            tmark++;
            smark++;
        }
        if(target[tmark] == '\0'){   // found
            tailloc[tailloc_iter] = smark - 1;
            headloc_iter++;
            tailloc_iter++;
            smark--;
        }
        loc_recorded = 0;
        tmark = 0;
        smark++;
    }
    for(int i = 0; i < MAX_STRLEN; i++){
        if(tailloc[i] == MAX_STRLEN+1 && headloc[i] != MAX_STRLEN+1){
            headloc[i] = MAX_STRLEN+1;
        }
    }
    // cout<<"headloc: "<<headloc<<endl;
    // cout<<"tailloc: "<<tailloc<<endl;
    char temp[MAX_STRLEN];
    for(int i = 0, j = 0, z = 0, positer = 0; str[i]!='\0'; i++, z++){   //i for str; j for to; z for temp
        if(z < headloc[0]){
            temp[z] = str[i];
        }
        else if(i >= headloc[positer]){
            while(to[j] != '\0'){
                temp[z] = to[j];
                j++;
                z++;
            }
            if(to[j] == '\0'){
                i = tailloc[positer];
                z--;
                j = 0;
                positer++;
            }
        }
        else{
            if(str[i] != '\0'){
                temp[z] = str[i];
            }
            else{
                temp[z] = '\0';
                break;
            }
        }
    }
    for(int i = 0; ; i++){
        if(temp[i] == '\0'){
            str[i] = '\0';
            break;
        }
        else{
            str[i] = temp[i];
        }
    }
    // for(int i = 0; i < 9; i++){
    //     cout<<headloc[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 0; i < 9; i++){
    //     cout<<tailloc[i]<<" ";
    // }
    // cout<<endl;
    // cout<<temp<<endl;
}

void encryptText(char str[], int shift)
{
    int realshift = (shift%26+26)%26;
    // cout<<realshift<<endl;
    for(int i = 0; ; i++){
        if(str[i] != '\0'){  
            if(str[i]>=65 && str[i]<=90){
                str[i] -=26;
                str[i] += realshift;
                if(str[i] > 'Z'-26){
                    str[i] -= 26;
                }
                str[i] += 26;
            }
            else if(str[i]>=97 && str[i]<=122){
                str[i] -=26;
                str[i] += realshift;
                if(str[i] > 'z'-26){
                    str[i] -= 26;
                }
                str[i] += 26;
            }
        }

        else{
            break;
        }
    }
}

int countNumOccurences(const char str[], const char target[])
{
    int sum = 0;
    int smark = 0;
    while(str[smark] != '\0'){
        int tmark = 0;
        while(str[smark] == target[tmark] || target[tmark] == '\0'){
            if(target[tmark] == '\0'){
                sum++;
                break;
            }
            smark++;
            tmark++;
        }
        smark++;
    }
    return sum; // Replace this line with your implementation
}

bool isvowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    else{
        return false;
    }
}

bool isalphabet(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-'){
        return true;
    }
    else{
        return false;
    }
}

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE])
{
    int space_pos[MAX_STRLEN] = {};
    int space_iter = 0;
    int strlen = 0;
    for(int i = 0; ; i++){
        if(str[i] == '\0'){
            break;
        }
        else if(str[i] == ' '){
            space_pos[space_iter] = i;
            space_iter++;
        }
        strlen++;
    }
    int smark = 0;
    int endpoint = 0;
    int tar_chariter = 0;
    while(str[smark] != '\0'){
        while(str[smark] == ' '){
            smark++;
        }
        endpoint = smark + NUM_CHARS_PER_LINE-2;
        if(endpoint >= strlen-1){
            endpoint = strlen-1;
        }
        while(endpoint != strlen-1 && isalphabet(str[endpoint]) && isalphabet(str[endpoint+1])){   // find the first non-character
            endpoint--;
        }
        while(endpoint != strlen-1 && str[endpoint] == ' '){  // find the last character
            endpoint--;
        }
        // cout<<"smark: "<<smark<<" "<<str[smark]<<endl;
        // cout<<"endpoint: "<<endpoint<<" "<<str[endpoint]<<endl;
        for(; smark <= endpoint; smark++, tar_chariter++){
            lines[tar_lineiter][tar_chariter] = str[smark];
        }
        lines[tar_lineiter][tar_chariter] = '\0';
        tar_chariter = 0;
        tar_lineiter++;
    }
    // cout << tar_lineiter <<endl;
    // cout << strlen <<endl;
    // for(int i = 0; i < 21; i++){
    //     cout << space_pos[i] << " ";
    // }
    // cout << endl; 
}

void printLeftJustified(const char str[])
{
    char lines[MAX_LINES][NUM_CHARS_PER_LINE] = {};
    convertIntoLines(str, lines);
    for(int i = 0; i < tar_lineiter; i++){
        cout<<lines[i]<<endl;
    }
}

void printRightJustified(const char str[])
{
    char lines[MAX_LINES][NUM_CHARS_PER_LINE] = {};
    convertIntoLines(str, lines);
    int length[MAX_LINES] = {0};
    for(int i = 0; i < tar_lineiter; i++){
        for(int j = 0; ; j++){
            if(lines[i][j] != '\0'){
                length[i]++;
            }
            else{
                break;
            }
        }
    }
    for(int i = 0; i < tar_lineiter; i++){
        for(int j = 0; j < NUM_CHARS_PER_LINE-length[i]-1; j++){
            cout<<" ";
        }
        cout<<lines[i]<<endl;
    }
    
}

void printJustified(const char str[])
{
    char lines[MAX_LINES][NUM_CHARS_PER_LINE] = {};
    int add[MAX_LINES] = {};
    int spaces[MAX_LINES] = {};
    int length[MAX_LINES] = {};
    convertIntoLines(str, lines);
    for(int i = 0; i < tar_lineiter; i++){
        for(int j = 0; ; j++){
            while(lines[i][j] != '\0'){
                length[i]++;
                if(lines[i][j] == ' '){
                    spaces[i]++;
                    while(lines[i][j] == ' '){
                        j++;
                        length[i]++;
                    }
                }
                j++;
            }
            if(lines[i][j] == '\0'){
                add[i] = NUM_CHARS_PER_LINE - length[i] - 1;
                break;
            }
        }
    }
    for(int i = 0; i < tar_lineiter; i++){
        int added = 0;
        int extra_counter = 0;
        int normal_counter = add[i];
        if(spaces[i] != 0){
            extra_counter = add[i]%spaces[i];
            normal_counter = add[i]/spaces[i];
        }
        for(int j = 0; ; j++){
            if(lines[i][j] == '\0'){
                break;
            }
            else{
                if(lines[i][j] != ' ' && i!=tar_lineiter-1){
                    added = 0;
                }
                if(lines[i][j] == ' ' && added == 0 && i!=tar_lineiter-1){
                    if(extra_counter != 0){
                        cout<<" ";
                        extra_counter--;
                    }
                    for(int k = 0; k < normal_counter; k++){
                        cout<<" ";
                    }
                    added = 1;
                }
                cout<<lines[i][j];
            }
        }
        cout<<endl;
        // cout<<extra_counter<<" "<<normal_counter<<endl;
    }
    // for(int i = 0; i < tar_lineiter; i++){
    //     cout<<lines[i]<<"\t"<<spaces[i]<<"\t"<<add[i]<<endl;
    // }
}

void convertStrToPigLatin(char str[])
{
    int head = 0;               // for str          
    int iterator = 0;           // for result
    char result[999] = {};
    int strLen = countCharacters(str);
    for(int i = 0; i<=strLen ; i++){
        if(!isalphabet(str[i]) || i==strLen){
            if(isvowel(str[head])){
                for(; head < i; head++, iterator++){
                    result[iterator] = str[head];
                }
                result[iterator] = 'y';
                result[iterator+1] = 'a';
                result[iterator+2] = 'y';
                iterator+=3;
            }
            else if(!isvowel(str[head])){
                char temp_char = str[head];
                int olditer = iterator;
                int oldhead = head;
                //---------------------first---------------------
                for(; head < i-1; head++, iterator++){
                    result[iterator] = str[head+1];
                }
                result[iterator] = temp_char;
                int newiter = iterator;
                int newhead = head;
                while(!isvowel(result[olditer])){
                    iterator = olditer;
                    head = oldhead;
                    temp_char = result[olditer];
                    for(; head < i-1; head++, iterator++){
                        result[iterator] = result[iterator+1];
                    }
                    result[iterator] = temp_char;
                }
                iterator = newiter;
                head = newhead;
                result[iterator+1] = 'a';
                result[iterator+2] = 'y';
                iterator+=3;
            }
            while(!isalphabet(str[i])){
                result[iterator] = str[i];
                iterator++;
                i++;
            }
            head = i;
        }
    }
    for(int i = 0; result[i] != '\0'; i++){
        str[i] = result[i];
    }
    str[countCharacters(result)] = '\0';
    // cout<<result<<endl;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes end here. Please do not modify codes below
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

void printPigLatin(const char str[])
{
    char pigLatin[MAX_STRLEN];
    for (int i = 0; i < MAX_STRLEN; ++i)
    {
        pigLatin[i] = str[i];
    }
    convertStrToPigLatin(pigLatin);
    int strLen = countCharacters(pigLatin);
    for (int i = 0; i < strLen; ++i)
    {
        if (pigLatin[i] >= 'A' && pigLatin[i] <= 'Z')
        {
            pigLatin[i] = 'a' + pigLatin[i] - 'A';
        }
    }
    cout << pigLatin << endl;
}

void printMainDisplay(const char str[])
{
    cout << str << endl
         << "===================================\n"
         << "1. Character Count\n"
         << "2. Word Count\n"
         << "3. Encrypt (Caeser Cipher)\n"
         << "4. Find and Replace String Globally\n"
         << "5. Find Frequency of String\n"
         << "6. Print Left Align Text\n"
         << "7. Print Right Align Text\n"
         << "8. Print Left-Right Align Text\n"
         << "9. Print Pig Latin\n"
         << "Please make your choice: ";
}

int main()
{
    int choice = 0;
    char str[MAX_STRLEN];

    cout << "Enter text: ";
    cin.getline(str, MAX_STRLEN, '\n');

    do
    {
        printMainDisplay(str);
        cin >> choice;
    } while (choice < 1 || choice > 9);

    if (choice == 1)
    {
        cout << "Total character count: " << countCharacters(str) << endl;
    }
    else if (choice == 2)
    {
        cout << "Total word count: " << countWords(str) << endl;
    }
    else if (choice == 3)
    {
        cout << "Enter the shift amount for the caeser cipher encryption (rotation encryption): ";
        int shift;
        cin >> shift;
        encryptText(str, shift);
        cout << str << endl;
    }
    else if (choice == 4)
    {
        cout << "Enter the string to find and replace: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << "Enter the string to replace it with: ";
        char to[MAX_STRLEN];
        cin.getline(to, MAX_STRLEN, '\n');

        swapString(str, target, to);
        cout << str << endl;
    }
    else if (choice == 5)
    {
        cout << "Enter the string to count the occurences of: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << '"' << target << '"' << " appears in the text " << countNumOccurences(str, target) << " time(s).\n";
    }
    else if (choice == 6)
    {
        printLeftJustified(str);
    }
    else if (choice == 7)
    {
        printRightJustified(str);
    }
    else if (choice == 8)
    {
        printJustified(str);
    }
    else if (choice == 9)
    {
        printPigLatin(str);
    }
}
