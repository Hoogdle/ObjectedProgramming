#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main(){
    vector<string> v(5);
    string temp;
    cout << "이름을 5개 입력하라" <<endl;
    for (int i=0;i<5;++i){
        cout << i+1 << ">>";
        getline(cin,temp);
        v.push_back(temp);
    }

    string lower = v[0];
    for(int i=1;i<5;++i){
        if (lower<v[i])
            lower = v[i];
    }
    cout << "사전에서 가장 뒤에 나오는 문자열은 " + lower << endl;
}