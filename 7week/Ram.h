#ifndef RAM_H
#define RAM_H

const int MEM_SIZE = 100 * 1024;

class Ram {
    char mem[MEM_SIZE];
    int size;
    public:
    Ram(); // mem의 모든 값을 0으로 초기화하고 size를MEM_SIZE로 초기화
    ~Ram(); // "메모리 제거됨" 문자열 출력
    // read와 write 멤버 함수 모두 addr이 주소의 범위르 넘으면
    // "주소 범위를 벚어남"이라는 에러 메시지 출력
    // read 함수의 경우 주소 범위를 벚어날 경우 -1 리턴
    char read(int addr); // addr 주소의 메모리를 읽어 리턴
    void write(int addr, char value); // addr 주소에 value 저장
    private:
    bool isValidAddr(int addr);
};

#endif 