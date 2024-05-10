#include <iostream>
#include <string>
using namespace std;

int main(){
    string str[5];
    string lower;
    for(int i=0;i<5;++i){
        getline(cin,str[i]);
    }
    lower = str[0];
    for(int i=1;i<5;++i){
        if (lower<str[i])
            lower = str[i];
    }
    cout << "사전에서 가장 뒤에 나오는 문자열은 " + lower << endl;
}