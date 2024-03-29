#include <iostream>
using std::cout;
using std::endl;
using std::cin;

bool bigger(int a,int b, int &big){
    if(a>b)
        big = a;
    else if(a<b)
        big = b;
    else
        return true;
    return false;
}


int main() {
    int x, y, big;
    bool b;
    cout << "두 정수를 입력하세요>> ";
    cin >> x >> y;
    b = bigger(x, y, big);
    if(b)
    cout << "same" << endl;
    else
    cout << "큰 수는 " << big << endl;
}