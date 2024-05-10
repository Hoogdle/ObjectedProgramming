#include "Book.h"
#include <iostream>

// 코드 아직 완성 안 됨!
using namespace std;

int main() {
    Book cpp("C++", 10000);
    Book java = cpp;
    cpp.show();
    java.show();
    java.set("Java", 12000);
    cpp.show();
    java.show();
}