#include <iostream>

int main(){
    using std::cout;
    for(int i=0;i<4;++i){
        for(int j=0;j<i+1;++j)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}