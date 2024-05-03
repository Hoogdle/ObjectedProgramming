#include <string>
#include "Person.h"
#include <iostream>

#ifndef FAMILY_H
#define FAMILY_H


class Family {
    std::string name;
    Person* p; // Person 배열 포인터
    int size; // Person 배열의 크기. 가족 구성원 수
    public:
    Family(const std::string &name, int size); // size 개수만큼 Person 배열 동적 생성
    ~Family(); // 동적 배열 메모리 해제
    // p가 가리키는 동적 배열의 index 위치의 Person 객체의 이름을 변경
    void setName(int index, const std::string &name);
    void show() const; // 모든 가족 구성원 출력
};

#endif 
