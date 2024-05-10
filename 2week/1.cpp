#include <iostream>

int sum(int,int);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    int n = 0;
    cout << "끝 수를 입력하세요. >>";
    cin >> n;
    if(n<=0){
        cout << "양수를 입력하세요!\n";
        return 0;
    }
    int result = sum(1,n);
    cout<<"1에서 "<<n<<"까지의 합은 "<<result<<"입니다.\n";
    return 0;
}

int sum(int a, int b){
    int res=0;

    for(int k=a;k<=b;++k){
        res+=k;
    }

    return res;
}