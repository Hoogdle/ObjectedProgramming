#include "Accumulator.h"
#include <iostream>

using namespace std;

Accumulator::Accumulator(int value)
{
    this->value = value;
} // 매개변수 value로 멤버 value를 초기화한다.

Accumulator& Accumulator::add(int n){
    value = value+n;
    return *this;

} // value에 n을 더해 값을 누적한다.

int Accumulator::get() const{
    return value;
} // 누