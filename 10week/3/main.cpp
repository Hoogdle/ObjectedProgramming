#include "Accumulator.h"
#include <iostream>

using namespace std;

int main() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
    cout << acc.get() << endl; // 28 출력
}