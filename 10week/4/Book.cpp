#include "Book.h"
#include <iostream>
#include <cstring>
#include <string>


Book::Book(const char* title, int price){
    char* temp = new char[strlen(title)];
    for(int i=0;i<strlen(title);++i){
        temp[i] = title[i];
    }
    this->title = temp;
    this->price = price;
}

Book::~Book(){
    free(title);
}

Book::Book(Book &c,int price){
    char* temp = new char[strlen(c.title)];
    for(int i=0;i<strlen(c.title);++i){
        temp[i] = c.title[i];
    }
    this->title = temp;
    this->price = price;
}


void Book::set(const char* title, int price){
    char* temp = new char[strlen(title)];
    delete this->title;
    for(int i=0;i<strlen(title);++i){
        temp[i] = title[i];
    }
    this->title = temp;
    this->price = price;

}