#include <iostream>

using namespace std;

class Rectangle{
    public:
    int width;
    int height;
    Rectangle();
    Rectangle(int a);
    Rectangle(int a, int b);
    bool isSquare();
};

Rectangle::Rectangle(){
    width = 1;
    height = 1;
}

Rectangle::Rectangle(int a){
    width = a;
    height = a;
}

Rectangle::Rectangle(int a, int b){
    width = a;
    width = b;
}

bool Rectangle::isSquare(){
    if(height==width)
        return 1;
    else
        return 0;
}

int main(){
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
    if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;

}