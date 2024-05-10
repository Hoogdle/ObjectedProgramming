#include <iostream>

using namespace std;


class Circle {
    int radius;
    public:
    Circle(int radius = 1): radius(radius) {}
    void setRadius(int radius) { this->radius = radius; }
    double getArea() const { return 3.14*radius*radius; }
};

void readRadius(Circle &a);



int main() {
    Circle donut;
    readRadius(donut);
    cout << "donut의 면적 = " <<donut.getArea() << endl;
}

void readRadius(Circle &a){
    int data;
    cin >> data;
    a.setRadius(data);
}
