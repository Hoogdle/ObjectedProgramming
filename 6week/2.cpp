#include <iostream>

using namespace std;

class Oval{
    public:
    int width,height;
    Oval(int w,int h);
    Oval(); // 1로 초기화
    ~Oval();
    int getWidth();
    int getHeight();
    void set(int w,int h);
    void show();
};

Oval::Oval(int w,int h){
    width = w;
    height = h;
}

Oval::Oval(){
    width = 1;
    height = 1;
}

Oval::~Oval(){
    cout << "소멸자 호출됨" << endl;
    cout << width << ' ' << height << endl;
}

int Oval::getWidth(){
    return width;
}

int Oval::getHeight(){
    return height;
}

void Oval::set(int w,int h){
    width = w;
    height = h;
}

void Oval::show(){
    cout << width << ' ' << height << endl;
}


int main(){
    Oval a,b(3,4);
    a.set(10,20);
    a.show();
    cout << b.getWidth() << ' ' << b.getHeight() << endl;


}