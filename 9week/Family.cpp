#include "Person.h"
#include "Family.h"

#include <iostream>

using namespace std;

Family::Family(const string &name, int size){
    this->name = name;
    this->size = size;
    p = new Person[size];
} // size 개수만큼 Person 배열 동적 생성
void Family::setName(int index, const string &name){
    (p+index)->setName(name);
}
void Family::show() const{
    cout << name << "가족은 다음과 같이 " << size <<"명 입니다." << endl;
    for(int i=0;i<size;++i){
        cout<<(p+i)->getName();
        cout<< ' ';
    }
}// 모든 가족 구성원 출력

Family::~Family(){
    delete[] p;
}// 동적 배열 메모리 해제