#include <fstream>
#include <iomanip>
#include <iostream>
#include "Database.h"
#include "String.h"
#include "Table.h"

using namespace std;

Database::Database(const String &name, int numTables) {
    currentTable = nullptr;
    this->numTables = numTables;
    this->name = name;
    Table* nt = nullptr;
    char size[69] = "Table_";
    for (int n = numTables; n > 0; --n) {   // from back to front
        Table* table = new Table(size);
        // shifting 6 "table"
        snprintf(size + 6, 10, "%d", n);

        table->next = nt;
        nt = table;
    }
    tableHead = nt;
}

Database::Database(const String &filename) {
    ifstream ifs(filename.getStr());    // get file name
    int tnumber;
    ifs >> tnumber;
    getline(ifs, name, '\n');
    numTables = 0;
    tableHead = nullptr;

    String tname;
    for (int i = 0; i < tnumber; i++) {
        getline(ifs, tname, '\n'); 
        Table* newtable = new Table(ifs,  tname);
        addTable(newtable);
    }
    ifs.clear();
    ifs.close();
}

Database::~Database() {
    Table* t = tableHead;
    if (t == nullptr) {
        return;
    }
    else{
        Table* nt = t->next;
        for (int i = 0; i < numTables; ++i) { 
            delete t;
            t = nt;
            if (t == nullptr) {
                return;
            }
            else{
                nt = t->next;
            }
        }
    }
    
}

bool Database::addTable(Table *table) {
    if (table == nullptr) {
        cout << "Table is a null pointer.\n";
        return false;
    }
    if (findTable(table->getName())) {
        cout << "Table with given name already exists in the database.\n";
        return false;
    }
    else if (numTables == 0) {
        tableHead = table;
    }
    else if(numTables > 0){
        Table* lt = tableHead;
        while (lt->next != nullptr) {
            lt = lt->next;
        }
        lt->next = table;
    }
    ++numTables;
    return true;
}

void Database::addTable(const String &name) {
    Table* nt = new Table(name);
    if(addTable(nt) == true){
        // do nothing, success
    }
    else{
        delete nt;
    }
}

Table* Database::findTable(const String &name) const {
    Table* t = tableHead;
    while (t != nullptr) {
        if (t->getName() == name) {
            return t;
            break;
        }
        else{
            t = t->next;
        }
    }
    return nullptr;
}

void Database::listTables() const {
    Table* t = tableHead; 
    if(t == nullptr){
        return;
    }
    cout << "The tables currently existing in the database are:\n";
    while (t != nullptr) {
        cout << t->getName() << "\n";
        t = t->next;
    }
}

void Database::deleteTable(const String &name) {
    Table* pt = nullptr;
    Table* t = tableHead;
    while (t != nullptr) {
        if(t->getName() == name){
            break;
        }
        else{
            pt = t;
            t = t->next;
        }
    }
    if(t != nullptr && pt == nullptr){
        tableHead = t->next;
        delete t;
        numTables--;
    }
    else if(t != nullptr && pt != nullptr){
        pt->next = t->next;
        delete t;
        numTables--;
    }
    else {
        cout << "No such table exists in the database.\n";
    }
}

void Database::setCurrentTable(const String &name) {
    currentTable = findTable(name);
    if (currentTable == nullptr){
        cout << "No such table exists in the database.\n";
    }
}

void Database::saveDatabase(const String &filename) const {
    ofstream ofs(filename.getStr());
    Table* t = tableHead;
    Field* f;
    ofs << name << endl;
    ofs << numTables << endl;
    while(t != nullptr){
        int rows = t->getNumRows();
        int cols = t->getNumCols();
        ofs << t->getName() << endl;
        ofs << cols << endl;
        ofs << rows << endl;
        f = t->getFieldHead();
        for (int i = 0; i < cols; ++i) {
            if (f == t->getPrimaryKey()) {
                ofs << "*";
            }
            if(f->type == INT){
                ofs << f->name << " " << 0 ;
            }
            else if(f->type == STRING){
                 ofs << f->name << " " << 1 ;
            }
            if (i == cols - 1) {
                ofs << endl;
            } 
            else {
                ofs << ", ";
            }
            f = f->next;
        }
        for (int i = 0; i < rows; ++i) {
            f = t->getFieldHead();
            for (int j = 0; j < cols; ++j) {
                ofs << f->column[i];
                if (j == cols-1){
                    ofs << endl;
                }
                else {
                    ofs << ", ";
                }
                f = f->next;
            }
        }
        t = t->next;
    }
    ofs.close();
    ofs.clear();
}

//------------------------------------------skeleton code------------------------------
void Database::printTable(Table *table) const
{
    if (table == nullptr)
    {
        cout << "No such table exists in the database." << endl;
        return;
    }

    for (Field *cur = table->getFieldHead(); cur != nullptr; cur = cur->next)
    {
        cout << setw(15) << left;
        String curPrintName = (cur == table->getPrimaryKey() ? "*" : "") + cur->name + ' ' + (cur->type == INT ? "0" : "1");
        cout << curPrintName;
    }
    cout << endl;
    for (int i = 0; i < table->getNumRows(); ++i)
    {
        for (int j = 0; j < table->getNumCols(); ++j)
        {
            cout << setw(15) << left;
            cout << (*table)[j][i];
        }
        cout << endl;
    }

    return;
}

void Database::innerJoin(Table *table1, Table *table2){

}