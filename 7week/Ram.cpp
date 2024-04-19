#include "Ram.h"
#include <iostream>

using namespace std;

Ram::Ram(){
    for(int i=0;i<MEM_SIZE;++i){
        mem[i] = 0;
    }
    this->size = MEM_SIZE;
}

Ram::~Ram(){
    cout<<"메모리에서 제거됨"<<endl;
}

char Ram::read(int addr){
    if(isValidAddr(addr))
        return mem[addr];
    else
    return -1;
}

void Ram::write(int addr, char value){
    if(isValidAddr(addr))
    mem[addr] = value;
    else
    return;
}

bool Ram::isValidAddr(int addr){
    if(addr<0 || addr>=MEM_SIZE){
        cout<<"주소의 범위를 벗어남"<<endl;
        return false;
    }
    else return true;
}


