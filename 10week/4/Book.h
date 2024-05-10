#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book {
    char *title; // 제목 문자열
    int price; // 가격
    public:
    Book(Book &c,int price);
    // 여기에는 복사 생성자의 선언이 없음(복사 생성자도 선언해야 함)
    Book(const char* title, int price);
    ~Book();
    void set(const char* title, int price);
    void show() const { std::cout << title << ' ' << price << "won" << std::endl; }
};


#endif