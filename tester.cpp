#include <bits/stdc++.h>

using namespace std;


int * c_i(int value){
    int x = value;
    int *p = &x;
    return p;
}
int main(){
    int *ip = c_i(10);
    cout << *ip << endl;
}