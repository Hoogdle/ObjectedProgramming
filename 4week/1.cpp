#include <iostream>
using namespace std;

void f(char c=' ', int line=1);



int main(){
    f('%',5);
}

void f(char c, int line){
    if(line==1){
        for (int i=0;i<10;++i){
            cout << c ;
        }
        cout << endl;
    }
    else{
        for (int i=0;i<line;++i){
            cout << c ;
        }
        cout << endl;
    }
}