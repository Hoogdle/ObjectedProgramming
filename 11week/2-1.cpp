#include <iostream>
#include <string>

// 추가 구현 하기!!!
using namespace std;


class Book {
    string title;
    int price;
    int pages;
    public:
    Book(const string &title=string(), int price=0, int pages=0) {
    this->title = title;
    this->price = price;
    this->pages = pages;
    }
    void show() const {
    cout << title << ' ' << price << "원 " <<pages << " 페이지" << endl;
    }
    const string &getTitle() const {
    return title;
    }

    bool operator==(int price);
    bool operator==(string title);
    bool operator==(Book temp);
};

bool Book::operator==(int price){
    if(this->price == price){return true;}
    return false;
}
bool Book::operator==(string title){
    if(this->title.compare(title)==0){return true;}
    return false;
}

bool Book::operator==(Book temp){
    if((this->title.compare(title)==0)&&(this->price == price)&&(this->pages==pages))
}

int main() {
    Book a("명품 C++", 30000, 500), b("고품격 C++", 30000, 500);
    // price 비교
    if(a == 30000) cout << "정가 30000원" << endl;
    // 책 title 비교
    if(a == "명품 C++") cout << "명품 C++ 입니다." << endl;
    // title, price, pages 모두 비교
    if(a == b) cout << "두 책이 같은 책입니다." << endl;
}