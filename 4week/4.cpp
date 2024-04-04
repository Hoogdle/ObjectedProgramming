#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
void reverse(T a[],int b){
   int temp = int(b/2);
   int index = b-1;
   for(int i=0;i<temp;++i){
    int temp2 = a[index-i];
    a[index-i] = a[i];
    a[i] = temp2;
   }
}

int main(){
    int x[] = {1,10,100,5,4};
    reverse(x,5);
    for(int i=0;i<5;++i){
        cout << x[i] << ' ';
    cout<<endl;
    }
}