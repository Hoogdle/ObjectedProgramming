#include <iostream>

int main()
{
    using std::cout;
    int sum = 0;
    for (int i=1;i<=10;++i)
    {
        sum += i;
    }
    cout<<"1에서 10까지 더한 결과는"<<sum<<"입니다\n"; //변수,문자열 출력
    char c = '#';
    cout<<c<<5.5<<'-'<<"Hi"; // 변수,숫자,문자,문자열 출력

    return 0;
}