#include <iostream>
using namespace std;

// todo: change main back to original



// some constraints for board
const int MAX_ROW = 15, MAX_COL = 15;
const int MAX_CONSTRAINT_NUM = 15;  // constraint cannot exceed MAX_ROW/MAX_COL

// board and its size
int num_rows = 0, num_cols = 0;
char board[MAX_ROW][MAX_COL] = {{0}};

// constraints and their sizes
int num_row_constraints[MAX_ROW] = {0}, num_col_constraints[MAX_COL] = {0};
int row_constraints[MAX_ROW][MAX_CONSTRAINT_NUM] = {{0}};
int col_constraints[MAX_COL][MAX_CONSTRAINT_NUM] = {{0}};

/**********************************
 * Part 1: Initialize the board   *
 **********************************/

/**
 **********  Task 1  **********
 * 
 * This function reads the board size and constraints from user input,
 * store the information in global variables and init the board.
 * 
 * Don't forget to check whether row/column constraints are valid.
 * Please refer to webpage for a detailed description.
 *
 * For simplicity, we assume the user's other inputs are always valid.
 */
void get_input_board() {
    // START YOUR CODES HERE
    cout << "Enter the number of rows: ";
    cin >> num_rows;
    cout << "Enter the number of columns: ";
    cin >> num_cols;
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            board[i][j] = '.';
        }
    }
    bool valid = 1;
    int constraints;
    for(int i = 0; i < num_rows; i++){
        int row_cnt = 0;
        int valid_sum = 0;
        num_row_constraints[i] = 0;
        cout << "Enter the number of constraints for row " << i << " (end with -1): ";
        while(cin >> constraints && constraints != -1){
            row_constraints[i][row_cnt] = constraints;
            num_row_constraints[i]++;
            valid_sum += constraints; 
            row_cnt++;
        }
        valid_sum = valid_sum + num_row_constraints[i] - 1;
        if(valid_sum > num_cols){
            cout << "Invalid row constraint, please try again." << endl;
            i--;
        }
    }
    for(int i = 0; i < num_cols; i++){
        int col_cnt = 0;
        int valid_sum = 0;
        num_col_constraints[i] = 0;
        cout << "Enter the number of constraints for column " << i << " (end with -1): ";
        while(cin >> constraints && constraints != -1){
            col_constraints[i][col_cnt] = constraints;
            num_col_constraints[i]++;
            valid_sum += constraints; 
            col_cnt++;
        }
        valid_sum = valid_sum + num_col_constraints[i] - 1;
        if(valid_sum > num_rows){
            cout << "Invalid column constraint, please try again." << endl;
            i--;
        }
    }
    // END YOUR CODES HERE
}


/**
 **********  Task 2  **********
 *
 * This function prints the board and the constraints for each row and column.
 * Constraints should be printed on the bottom of each column and on the left of each row.
 *
 * You may find an example in webpage.
 */
void print_board() {
    // START YOUR CODES HERE
    int max_row_constraint = 0;
    int max_col_constraint = 0;
    for(int i = 0; i < num_rows; i++){  // calculate max row constraints length
        if(num_row_constraints[i] > max_row_constraint){
            max_row_constraint = num_row_constraints[i];
        }
    }
    for(int i = 0; i < num_cols; i++){  // calculate max row constraints length
        if(num_col_constraints[i] > max_col_constraint){
            max_col_constraint = num_col_constraints[i];
        }
    }
    for(int i = 0; i < max_row_constraint*2 + 4; i++){
        cout << " ";
    }
    for(int i = 0; i < num_cols; i++){
        cout << " " << char(i+65);
    }
    cout << endl;
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < (max_row_constraint - num_row_constraints[i])*2; j++){
            cout << " ";
        }
        for(int j = 0; j < num_row_constraints[i]; j++){
            cout << row_constraints[i][j] << " ";
        }
        cout << "|";
        for(int j = 0; (i > 9)? j < 1: j < 2; j++){
            cout << " ";
        }
        cout << i;
        for(int j = 0; j < num_cols; j++){
            cout << " " << board[i][j];
        }
        cout << endl;
    }  
    for(int i = 0; i < max_col_constraint; i++){
        for(int j = 0; j < max_row_constraint*2 + 4; j++){
            cout << " ";
        }
        for(int j = 0; j < num_cols; j++){
            if(i < num_col_constraints[j]){
                cout << " " << col_constraints[j][i];
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    // END YOUR CODES HERE
}


/********************************
 * Part 2: User play on board   *
 ********************************/

/**
 **********  Task 3  **********
 *
 * This function will be called when user choose to set/unset a cell. 
 *
 * You need to:
 * 1. Ask user to input which cell he/she wants to modify
 * 2. Check if the user input is a valid cell(i.e., it is within the board)
 *    If invalid, keep asking the user to input.
 * 3. Set/unset the cell
 * 4. Print the new board
 */
void user_operate_board() {
    // START YOUR CODES HERE
    char charcol;
    int row, col;
    // some code snippets that you can directly copy and paste.
    cout << "Enter the cell you want to modify (e.g. A 2): ";
    while(cin >> charcol && cin >> row){
        col = charcol - 65;
        if(row < num_rows && col < num_cols){
            if(board[row][col] == '.'){
                board[row][col] = 'X';
            }
            else{
                board[row][col] = '.';
            }
            break;
        }
        else{
            cout << "Invalid row or column. Try again." << endl; 
            cout << "Enter the cell you want to modify (e.g. A 2): ";
        }
    }
    // END YOUR CODES HERE
}


/**
 **********  Task 4  **********
 *
 * This function will be called after user finish filling the whole board.
 * You need to check whether his/her solution is correct, 
 * i.e., follow all constraints.
 *
 * Return true if his/her solution is correct; false otherwise.
 */
bool check_whole_board_valid() {
    // START YOUR CODES HERE
    for(int i = 0; i < num_rows; i++){
        int row_check_iter = 0;
        for(int j = 0; j < num_cols; j++){
            int cnt = 0;
            while(board[i][j] == 'X'){
                cnt++;
                j++;
            }
            if(cnt != 0 && cnt != row_constraints[i][row_check_iter]){
                // cout << "row: " << i << " row_check_iter: " << row_check_iter << endl;
                return false;
            }
            else if(cnt != 0 && cnt == row_constraints[i][row_check_iter]){
                row_check_iter++;
            }
        }
        if(row_check_iter != num_row_constraints[i]){
            return false;
        }
    }
    for(int i = 0; i < num_cols; i++){
        int col_check_iter = 0;
        for(int j = 0; j < num_rows; j++){
            int cnt = 0;
            while(board[j][i] == 'X'){
                cnt++;
                j++;
            }
            if(cnt != 0 && cnt != col_constraints[i][col_check_iter]){
                // cout << "col: " << i << " col_check_iter: " << col_check_iter << endl;
                return false;
            }
            else if(cnt != 0 && cnt == col_constraints[i][col_check_iter]){
                col_check_iter++;
            }
        }
        if(col_check_iter != num_col_constraints[i]){
            return false;
        }
    }
    return true;
    // END YOUR CODES HERE
}


/*******************************
 * Part 3: A nonogram solver   *
 *******************************/

/**
 **********  Task 5  **********
 *
 * This function coverts a position vector of a row into a real row.
 * 
 * For example, if num_col = 8, position vector = {0, 3, 5}, 
 * row_constraint for this row is {2, 1, 1}, then the row should be:
 * [X X . X . X . .]
 * It will store the result row in variable 'result_row[]'
 *
 * You may assume the parameters given are always valid.
 */
void positions_to_row(int row_idx, const int positions[], int num_pos, char result_row[]) {
    // START YOUR CODES HERE
    int iter = 0;   // iter throught the constraints and position vector
    for(int i = 0; i < num_cols; i++){
        if(i >= positions[iter] && i < positions[iter] + row_constraints[row_idx][iter]){
            result_row[i] = 'X';
            if(i == positions[iter] + row_constraints[row_idx][iter] - 1 && iter < num_row_constraints[row_idx]){
                iter++;
            }
        }
        else{
            result_row[i] = '.';
        }
    }
    // END YOUR CODES HERE
}


/**
 **********  Task 6  **********
 * 
 * This function checks if the given block on given row can be shifted right
 * for one cell. 
 * For example, if the position vector is {0, 4, 6}, num_col = 8
 * then the row is: [X X . . X . X .], and there are 3 blocks
 * then block_can_shift(row_idx, 0, {0, 4, 6}) = true, 
 *      block_can_shift(row_idx, 1, {0, 4, 6}) = false, since it will hit 2nd block after shift
 *      block_can_shift(row_idx, 2, {0, 4, 6}) = true.
 * 
 * More details can be found on webpage.
 */
bool block_can_shift(int row_idx, int block_idx, const int positions[], int num_pos) {
    // START YOUR CODES HERE
    if(block_idx+1 >= num_row_constraints[row_idx]){    // prevent array out of bound
        if(positions[block_idx] + row_constraints[row_idx][block_idx] >= num_cols){
            return false;
        }
    }
    else if(positions[block_idx] + row_constraints[row_idx][block_idx]+1 >= positions[block_idx+1]){
        return false;
    }
    else{
        return true;    // added to pass compilation
    }
    // END YOUR CODES HERE
}

// this array stores all valid permutations for each row
// it's expected that num of permutations for each row should not exceed 2^(num_cols)
const int MAX_PERM = 1 << MAX_COL;     // A way to calculate 2^(num_cols)
char row_perms[MAX_ROW][MAX_PERM][MAX_COL];
// this array stores num of permutations for each row
int num_row_perms[MAX_ROW] = {0};


/**
 **********  Task 7  **********
 * 
 * This function gets all valid permutations for a row, 
 * and store all results in global variables 'row_perms' and 'num_row_perms'.
 * 
 * Hint: You may use recursion to do that, with the help of helper functions
 * 'block_can_shift()', etc.
 * 
 */


int positions[MAX_CONSTRAINT_NUM] = {};
int init = 0;
void get_row_perms(int row_idx, int block_idx) {
    // START YOUR CODES HERE
    if(init == 0){
        positions[0] = 0;
        for(int i = 1; i < num_row_constraints[row_idx]; i++){
            positions[i] = positions[i-1] + row_constraints[row_idx][i-1] + 1;
        }
        init = 1;
    }
    for(int i = block_idx; i >= 0; i--){
        if(block_can_shift(row_idx, i , positions, -1)){
            positions[i]++;
            get_row_perms(row_idx, i);
            positions[i]--;
        }
    }
    positions_to_row(row_idx, positions, -1, row_perms[row_idx][num_row_perms[row_idx]++]);
    // END YOUR CODES HERE
}

void get_row_perms(int row_idx){
    init = 0;
    get_row_perms(row_idx,  num_row_constraints[row_idx]-1);
}


/**
 **********  Task 8  **********
 * 
 * This function checks if current state is valid, after 
 * we finish filling 'num_complete_rows' rows.
 *
 * For example, if num_complete_rows = 2, it will only check
 * if the first two rows (with index 0 and 1) do not 
 * break column constraints.
 *
 * Note that this function is different from 'check_whole_board_valid()'
 * in 2 ways:
 * 1. We don't check whole board here, only check the first 'num_complete_rows' rows.
 * 2. We don't (need to) check row_constraints here, only check column_constraints.
 *    This is because this function will only be called during solver, 
 *    so the rows are generated in permutation process, which must be valid.
 */
bool check_rows_valid(int num_complete_rows) {
    // START YOUR CODES HERE
    for(int i = 0; i < num_cols; i++){
        int col_check_iter = 0;
        for(int j = 0; j <= num_complete_rows; j++){
            int cnt = 0;
            if(board[j][i] == 'X'){
                while(board[j][i] == 'X'){
                    cnt++;
                    j++;
                }
            }
            if(cnt != 0 && cnt > col_constraints[i][col_check_iter]){
                // cout <<"num complete row: "<< num_complete_rows<< " col: " << i << " row: "<< j << " col_check_iter: " << col_check_iter <<" cnt: "<<cnt<< endl;
                return false;
            }
            if(cnt != 0 && cnt < col_constraints[i][col_check_iter] && j >= 1 && j <= num_complete_rows && board[j][i] == '.' && board[j-1][i] == 'X'){
                // cout <<"num complete row: "<< num_complete_rows<< " col: " << i << " row: "<< j << " col_check_iter: " << col_check_iter <<" cnt: "<<cnt<< endl;
                return false;
            }
            int left_constraints = 0;
            for(int k = col_check_iter+1; k < num_col_constraints[i]; k++){
                left_constraints += col_constraints[i][k];
            }
            if(num_rows - cnt < left_constraints){
                return false;
            }
            else if(cnt != 0 && cnt == col_constraints[i][col_check_iter]){
                col_check_iter++;
            }
        }
    }
    return true;    // added to pass compilation
    // END YOUR CODES HERE
}




/**
 **********  Task 9  **********
 * 
 * This function will solve the board, and store the solution
 * into board[][] directly.
 * 
 * Hint: You may use recursion to do that, with the help of helper functions
 * 'get_row_perms()', �焝heck_rows_valid()��, etc.
 */

void toboard(char target[], const char source[]){
    for(int i = 0; i < num_cols; i++){
        target[i] = source[i];
    }
}

int iter2 = 0;
void solve(int row) {
    // START YOUR CODES HERE
    // cout<<iter2<<" hi"<<endl;
    for(int i = 0; i < num_row_perms[iter2]; i++){
        if(check_whole_board_valid()){
            // cout << "ur a stupid asshole" << endl;
            break;
        }
        toboard(board[iter2], row_perms[iter2][i]);
        if(check_rows_valid(iter2)){
            //--------------------------------------
            // cout<< row <<" is correct now as ";
            // for(int j = 0; j < num_cols; j++){
            //     cout<<board[iter2][j];
            // }
            // cout<<endl;
            //---------------------------------------
            if(iter2+1 < num_rows){
                iter2++;
            }
            solve(iter2);
            iter2--;
        }
        else{
            //-------------------------------------
            // cout<< row <<" failed as ";
            // for(int j = 0; j < num_cols; j++){
            //     cout<<board[iter2][j];
            // }
            // cout<<endl;
             //--------------------------------------
            for(int j = 0; j < num_cols; j++){
                board[iter2][j] = '.';
            }
        }
    }
    // END YOUR CODES HERE
}

int solveall = 0;
void solve(){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            board[i][j] = '.';
        }
    }
    if(solveall == 0){
        for(int i = 0; i < num_rows; i++){
            init = 0;
            get_row_perms(i);
        }
        solveall = 1;
    }
    iter2 = 0;
    solve(0);
}

int main() {
    get_input_board();
    print_board();

    while (true) {
        cout << "===== Welcome to Nonogram Game =====" << endl;
        cout << "Please enter your choice:" << endl;
        cout << "Enter 'p' to print the current board." << endl;
        cout << "Enter 'm' to modify a cell." << endl;
        cout << "Enter 'c' to check your solution." << endl;
        cout << "Enter 's' to invoke solver." << endl;
        cout << "Enter 'q' to quit." << endl;
        cout << "Your choice: ";
        char input;
        cin >> input;
        if (input == 'p') {
            // solve();
            // for(int i = 0; i < num_rows; i++){
            //     for(int j = 0; j < num_row_perms[i]; j++){
            //         for(int k = 0; k < 10; k++){
            //             cout << row_perms[i][j][k] << " ";
            //         }
            //         cout<<endl;
            //     }
            //     cout<<endl;
            // }
            print_board();
        } else if (input == 'm') {
            user_operate_board();
        } else if (input == 'c') {
            if (check_whole_board_valid()) {
                cout << "Congratulations! Your solution is correct!" << endl;
            } else {
                cout << "Ahh, your solution is incorrect, try again." << endl;
            }
        } else if (input == 's') {
            cout << "Generating solution:" << endl;
            solve();
            print_board();
        } else if (input == 'q') {
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }
    return 0;
}