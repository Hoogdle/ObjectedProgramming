#include <iostream>
using namespace std;

int main(){
    char password1[100], password2[100];
    cout << "새 암호를 입력하세요 >>";
    cin.getline(password1,100,'\n');
    cout << "새 암호를 다시 한번 입력하세요 >>";
    cin.getline(password2,100,'\n');
    for(int i=0;i<100;++i){
        if (password1[i] != password2[i]){
            cout << "같지 않습니다." << endl;
            return 0;
        }
    }
    cout << "같습니다." <<endl;
}