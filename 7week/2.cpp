#include <iostream>
using namespace std;
class Int {
    int value;
    public:
    Int(int a=0);
    void set(int a);
    int get() const;
};

Int::Int(int a){
    this->value = a;
}

void Int::set(int a){
    this->value = a;
}

int Int::get() const{
    return this->value;
}

// 여기에 Int 클래스 멤버함수 정의
int main() {
    Int i1 = 20;
    const Int i2 = i1;
    i1.set(10);
    cout << i1.get() << ", " << i2.get() << endl;
}