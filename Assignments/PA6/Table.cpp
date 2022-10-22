#include <fstream>
#include "Table.h"
#include "String.h"

using namespace std;

Table::Table(const String &name) { 
    primaryKey = nullptr;
    fieldHead = nullptr;
    numRows = 0;
    numCols = 0;
    tableSize = 100;
    this->name = name;
}

Table::Table(ifstream &ifs, const String &name){
    primaryKey = nullptr;
    fieldHead = nullptr;
    numRows = 0;
    numCols = 0;
    tableSize = 100;
    this->name = name;

    int col, row;
    String temp, fn; 
    char type;
    ifs >> col >> row;
    for (int i = 0; i < col; i++) {
        if (i == col - 1) {
            getline(ifs, temp, '\n');
        }
        else { 
            getline(ifs, temp, ','); 
        }  
        type = temp[temp.length()-1];

        if (temp[0] == '*') {
            fn = temp.substr(1, temp.length() - 3);
            setPrimaryKey(fn);
            if(type == '0'){
                addField(i, fn, INT);
            }
            else{
                addField(i, fn, STRING);
            }
        } 
        else {
            fn = temp.substr(0, temp.length() - 2);
            if(type == '0'){
                addField(i, fn, INT);
            }
            else{
                addField(i, fn, STRING);
            }
        }
    }

    for (int i = 0; i < row; i++) {
        String* f = new String[col];
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                getline(ifs, f[j], '\n');
            }
            else { 
                getline(ifs, f[j], ','); 
            }  
        }
        addRecord(i, f);
        delete [] f;
    }
}

Table::~Table() {
    Field* f = fieldHead;
    if(f != nullptr){
        Field* nf;
        for (int c = 0; c < numCols; c++) {
            nf = f->next;
            delete [] f->column;
            delete f;
            f = nf;
            // iter thru
        }
    }
}

void Table::addRecord(int index, String *record) { 
    if (record == nullptr) {
        cout << "Record is empty.\n";
        return;
    }
    if (index < 0 || index > numRows) { 
        cout << "Table row index is out of bounds.\n";
        return;
    }
    bool primaryKeyError = false;
    bool typeMismatchError = false;
    int col = 0;
    for (Field* f = fieldHead; ; f = f->next) {
        if (primaryKey == f) {
            for (int i = 0; i < numRows; ++i) { 
                if (record[col] == f->column[i]) { 
                    primaryKeyError = true;
                    break;
                }
            }
            if (record[col] == "") {   
                primaryKeyError = true;
                break;
            }
        } 
        if ((f->type == INT) && (isInteger(record[col]) == false)) {   
            typeMismatchError = true;
            break;
        }
        ++col;
    }
    if (primaryKeyError || record->length() == 0) {
        cout << "Empty or duplicate primary key.\n";
        return;
    } 
    
    if (typeMismatchError) {
        cout << "Cannot insert non-integer in integer field.\n";
        return;
    } 
    // procedure
    else {
        if (numRows == tableSize) {
            tableSize += 100; 
            for (Field* f = fieldHead; f; f = f->next) { 
                String* new_col = new String[tableSize];
                for (int i = 0; i < numRows; i++) { 
                    new_col[i] = f->column[i];
                } 

                delete [] f->column;
                f->column = new_col;
            }
        }
        int col = 0;
        for (Field* f = fieldHead; ;f = f->next) {
            for (int i = numRows; i > index; i--) {
                f->column[i] = f->column[i-1];
            }
            f->column[index] = record[col];
            ++col;
        }
        ++numRows;
    }

}

void Table::addField(int index, const String &name, TYPE type) { 
    if (index > numCols || index < 0) { 
        cout << "Table column index is out of bounds.\n";
        return;
    }
    Field* f = fieldHead;
    while(f != nullptr && f->name != name){
        f = f->next;
    }
    if (f != nullptr) {
        cout << "Field with given name already exists in table.\n";
        return;
    }
    Field* nf = new Field;
    if (index == 0) {
        nf->next = fieldHead;
        fieldHead = nf;
    } 
    else {
        f = fieldHead;
        int i = 0;
        while(i < index - 1){
            f = f->next;
            ++i;
        }
        nf->next = f->next;
        f->next = nf;
    }
    nf->name = name;
    nf->type = type;
    nf->column = new String[tableSize];
    if (type == INT) {
        for (int i = 0; i < tableSize; i++) {
            nf->column[i] = "0";
        }  
    } 
    else if (type == STRING) {
        for (int i = 0; i < tableSize; i++) {
            nf->column[i] = "";
        }
    }
    if (numCols == 0) {
        primaryKey = nf;
    }
    ++numCols;
}

void Table::deleteRecord(int row) {
    if (row < 0 || row >= numRows) {
        cout << "Table row index is out of bounds.\n";
        return;
    }
    for (Field* f = fieldHead; f != nullptr ; f = f->next) {
        for (int i = row; i < numRows-1; ++i) {
            f->column[i] = f->column[i+1];
        }
        if(f->type == INT){
            f->column[numRows-1] = "0";
        }
        else if(f->type == STRING){
            f->column[numRows-1] = "";
        }
    }
    --numRows;
}

void Table::modifyRecord(int row, int column, const String &newVal) {
    if (row >= numRows || row < 0) {
        cout << "Table row index is out of bounds.\n";
        return;
    }
    if (column >= numCols || column < 0) {
        cout << "Table column index is out of bounds.\n";
        return;
    }
    Field* f = fieldHead;
    int c = 0;
    while(c < column){
        f = f->next;
        ++c;
    }
    if (f == primaryKey) {
        if (newVal == "") {
            cout << "Empty or duplicate primary key.\n";
            return;
        }
        else{
            for (int i = 0; i < numRows; ++i) {
                if (f->column[i] == newVal) {
                    cout << "Empty or duplicate primary key.\n";
                    return;
                }
            }
        }
    } 
    if ((f->type == INT) && (isInteger(newVal) == false)) {
        cout << "Cannot insert non-integer in integer field.\n";
        return;
    }
    f->column[row] = newVal;
}

void Table::setPrimaryKey(const String &name) {
    Field* f = fieldHead;
    while(f != nullptr){
        if(f->name == name){
            break;
        }
        f = f->next;
    }
    if (f != nullptr) {
        String* temp = new String[numRows];
        for (int i = 0; i < numRows; ++i) { // copy to tempCol
            temp[i] = f->column[i];
            if (temp[i] == "") {
                cout << "Cannot set field with empty data as primary key.\n";
                delete [] temp;
                return;
                break;
            }
        }
        // sort(temp, temp + (numRows-1)); // sort the array


        for (int r = 0; r < numRows - 1; r++) {
            if (temp[r] == temp[r+1]) { // contains duplicates
                cout << "Cannot set field with duplicate elements as primary key.\n";
                delete [] temp;
                return;
            }
        }
        delete [] temp;
        primaryKey = f;        
    } 
    else {
        cout << "No such field with provided name exists.\n";
        return;
    }
}

void Table::setColumnIndex(int index, const String &target) {
    Field* pf = nullptr;
    Field* f = fieldHead;
    while(f != nullptr && f->name != target){
        pf = f;
        f = f->next;
    }
    if (f != nullptr) {
        if (index < 0 || index >= numCols) {
            cout << "Table column index is out of bounds.\n";
            return;
        }
        if (pf != nullptr) {
            pf->next = f->next;
        } 
        else {
            fieldHead = f->next;
        }
        if (index == 0) {
            f->next = fieldHead;
            fieldHead = f;
        } else {
            Field* pn = fieldHead;
            int i = 0;
            while(i < index - 1){
                pn = pn->next;
                i++; 
            }
            f->next = pn->next;
            pn->next = f;
        }
    } 
    else {
        cout << "No such field with provided name exists.\n";
        return;
    }
}

void Table::deleteField(const String &name) {
    Field* pf = nullptr;
    Field* f = fieldHead;
    Field* tf = findField(name);
    if (tf == nullptr) {
        return;
    }
    while(f != nullptr && f->name != name){
        pf = f;
        f = f->next;
    }
    if (f != nullptr) {
        if (primaryKey == f) {
            cout << "Cannot delete primary key field.\n";
            return;
        }
        else if (pf) {
            pf->next = f->next;
        }
        else {
            fieldHead = f->next;
        }
        delete [] f->column;
        delete f;
        --numCols;
    } 
    else {
        cout << "No such field with provided name exists.\n";
        return;
    }
}

Field* Table::findField(const String& name) const {
    Field* f = fieldHead;
    while (f != nullptr) {
        if (f->name == name) {
            return f;
        }
        f = f->next;
    }
    cout << "No such field with provided name exists.\n";
    return nullptr;
}


void Table::sortTable(Field* field) {
    if (field == nullptr) {
        cout << "Invalid field provided.\n";
        return;
    }
    if (findField(field->name) == nullptr) {
        return;
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            if (field->type == INT) {
                if (stoi(field->column[j]) > stoi(field->column[j+1])) {
                     // do the swapping
                    String* tempa = new String[numCols];
                    String* tempb = new String[numCols];
                    Field* cf = fieldHead;
                    for (int k = 0; k < numCols; k++) {
                        tempa[k] = cf->column[j];
                        tempb[k] = cf->column[j+1];
                        cf = cf->next;
                    }

                    deleteRecord(j);
                    deleteRecord(j);
                    addRecord(j, tempb);
                    addRecord(j + 1, tempa);

                    delete[] tempa;
                    delete[] tempb;
                }
            } 
            else if (field->type == STRING) {
                if (field->column[j] > field->column[j+1]) {
                    // do the swapping
                    String* tempa = new String[numCols];
                    String* tempb = new String[numCols];
                    Field* cf = fieldHead;
                    for (int k = 0; k < numCols; k++) {
                        tempa[k] = cf->column[j];
                        tempb[k] = cf->column[j+1];
                        cf = cf->next;
                    }

                    deleteRecord(j);
                    deleteRecord(j);
                    addRecord(j, tempb);
                    addRecord(j + 1, tempa);

                    delete[] tempa;
                    delete[] tempb;
                }
            }
        }
    }
}

//------------------------------------------skeleton code------------------------------
bool isInteger(const String &test)
{
    if (!test.length())
        return false;

    if (test[0] != '-' && !isdigit(test[0]))
        return false;

    for (int i = 1; i < test.length(); ++i)
    {
        if (!isdigit(test[i]))
            return false;
    }
    return true;
}

String *Table::operator[](int index) const
{

    if (index >= numCols || index < 0)
    {
        cout << "Table column index is out of bounds." << endl;
        return nullptr;
    }

    Field *cur = fieldHead;
    for (int count = 0; count < index; cur = cur->next, ++count)
        ;
    return cur->column;
}