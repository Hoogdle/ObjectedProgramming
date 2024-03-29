#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;


char& find(char a[], char c, bool& success){
    char *b = NULL;
    b = strchr(a,c);
    char &temp = *b;
    
    if (b==NULL)
        success = false;
    else
        success = true;
    return temp;

    
}

int main() {
    char s[] = "Mike";
    bool b = false;
    char& loc = find(s, 'M', b);
    if(b == false) {
    cout << "M을 발견할 수 없다" << endl;
    return 0;
    }
    loc = 'm'; // 'M' 위치에 'm' 기록
    cout << s << endl; // "mike"가 출력됨
}