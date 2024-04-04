#include <iostream>
using namespace std;

template <class T>
T sum(T a[],int b){
    T temp = 0;
    for(int i=0;i<b;++i)
        temp += a[i];
    return temp;
}

int main(){
    int x[] = {1,2,3,4,5};
    double d[] = {1.2,2.3,3.4,4.5,5.6,6.7};

    cout << "sum of x[] = " << sum(x,5) << endl;
    cout << "sum of d[] = " << sum(d,6) << endl;
}