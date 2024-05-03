#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    void setRadius(int radius);
    double getArea() const;
};

void Circle::setRadius(int radius){
    this->radius = radius;
}

double Circle::getArea() const{
    return 3.14*radius*radius;
}


int main(){
    Circle array[3];
    int count=0;
    for(int i=0;i<3;++i){
        int data;
        cout << "Circle" <<i+1<<" Radius: ";
        cin >> data;
        array[i].setRadius(data);
        if(array[i].getArea()>100){++count;}
        
    }
    cout << "Over 100's count = " << count << endl;
    
}