// 여기에 정의되지 않은 String 클래스의 멤버 함수들을 구현

#include <iostream>
#include <stdio.h>
#include <cstring>
#include "String.h"


  const unsigned String::npos = 0xffffffff; // static 변수인 npos 를 usigned int 중 가장 큰 '65535'로 초기화
  // 생성자
  String::String(){
    this->capacity = 10; // 객체의 용량을 10으로 초기화
    this->memory = new char[10]; // calloc으로 빈 문자열 생성
    for(int i=0;i<10;++i){
      memory[i] = '\0';
    }
  } // 메모리의 크기(capacity)가 10인 동적 메모리를 할당하고, 이 메모리에 빈 문자열을 저장

  String::String(const char *str){
    this->capacity = strlen(str)+1; // 입력받은 문자열 + 1(for NULL) 만큼 객체의 용량을 설정
    this->memory = new char[capacity]; // 위에 설정한 객체의 capacity만큼 동적메모리 할당
    strcpy(memory,str); // cstring의 strcpy로 str의 문자열을 memory로 copy
  }    // str 문자열을 저장할 메모리 공간을 동적으로 생성하고, 이 문자열을 memory에 저장

  String::String(const String &str){
    this->capacity = strlen(str.memory)+1; // str객체의 capacity만큼 현재 객체의 capacity를 초기화
    this->memory = new char[capacity]; // 위에 설정한 객체의 capacity만큼 동적메모리 할당
    strcpy(memory,str.memory); // str 객체의 메모리가 가지고 있는 문자열을 현재 객체의 memory에 복사
  }  // 복사 생성자: str에 저장된 문자열을 memory에 저장

  // 소멸자
  String::~String(){
    delete [] memory; // 동적메모리 할당된 memory를 메모리 해제
  }  // memory가 가리키는 동적 메모리를 해제


  // memory의 문자열을 str로 변경
  void String::set(const char *str){
    this->capacity = strlen(str)+1; // 객체의 capacity를 매개변수로 들어온 str의 길이만큼으로 변경
    delete [] memory; // 기존 메모리 해지
    this->memory = new char[capacity]; // 객체의 memory의 크기를 realloc으로 변경(새롭게 정의된 capacity 만큼)
    strcpy(memory,str); // cstring의 strcpy로 str의 문자열을 memory로 copy
  }  

  void String::set(const String &str){
    this->capacity = strlen(str.memory)+1; // 객체의 capacity를 매개변수로 들어온 객체 str의 memory의 길이만큼으로 변경
    delete [] memory; // 기존 메모리 해지
    this->memory = new char[capacity]; // 객체의 memory의 크기를 realloc으로 변경(새롭게 정의된 capacity 만큼)
    strcpy(memory,str.memory); // cstring의 strcpy로 객체 str의 memory 문자열을 현재 객체 memory로 copy
  }

  // 문자열을 리턴하는 (인라인) 함수
  // const char *get() const { return memory; };
  
  // index 위치의 문자를 반환
  // char at(unsigned index) const { return memory[index]; };
  
  // 빈문자열이면 true, 아니면 false를 리턴
  // bool empty() const { return length() == 0; };

  // length(), size() 모두 문자열의 길이를 반환
  unsigned String::length() const{
    return strlen(memory); // strlen으로 memory 문자열의 길이를 반환
  }
  unsigned String::size() const{
    return strlen(memory); // strlen으로 memory 문자열의 길이를 반환
  }


  // 위치(인덱스)가 position인 위치부터 길이가 length인 부분 문자열을 String 객체로 리턴
  String String::substr(unsigned position, unsigned length) const{
    String temp; // 반환할 String 객체 temp 선언
    temp.capacity = length+1; // temp의 용량을 length+1로 초기화
    delete [] temp.memory;
    temp.memory = new char[temp.capacity]; // temp를 length 만큼 동적 메모리할당
    strncpy(temp.memory,memory+position,length); // 원하는 위치인 position에서 부터의 복사를 위해 memory + position 이후 위에 선언된 temp 객체의 메모리에 length 만큼 copy
    return temp; // temp 객체를 반환해준다
  }
  
  // memory의 position 위치에 str 을 삽입
  void String::insert(unsigned position, const char *str){
    capacity = capacity + strlen(str); // 새로운 문자열 str이 삽입 되므로 용량을 str의 길이만큼 늘려준다.
    char* temp = memory+position; // memory의 position 위치를 기억할 포인터 변수 temp 선언 및 초기화
    char* str1 = new char[capacity]; // str1을 capacity 크기 만큼 동적 메모리할당하여 빈 문자열을 생성
    char* str2 = new char[capacity]; // str2을 capacity 크기 만큼 동적 메모리할당하여 빈 문자열을 생성 
    char* str3 = new char[capacity]; // str3을 capacity 크기 만큼 동적 메모리할당하여 빈 문자열을 생성
    for(int i=0;i<capacity;++i){
      str1[i] = '\0';
      str2[i] = '\0';
      str3[i] = '\0';
    } // 빈 문자열을 생성하기 위한 구문
    // 기존 문자열을 분해해서 하나하나 cat으로 연결하며 원하는 위치에 str을 cat하는 방식으로 insert를 구현했습니다.
    strncpy(str1,memory,position); // 할당된 str1에 기존 memory의 position 만큼의 문자열을 복사
    strcpy(str2,str); // 할당된 str2에 삽입될 str 문자열을 복사
    strcpy(str3,temp); // 할당된 str3에 삽입 이후의 문자열 temp를 복사
    strcat(str1,str2); // str1과 str2를 연결
    strcat(str1,str3); // 를 거치면 결과적으로 str1,str2,str3이 연결됩니다. (str2는 삽입할 문자열)
    delete [] memory; // 기존 memory를 메모리 해제
    memory = new char[capacity];
    memory = str1; // memory가 새로운 동적 메모리 str1을 가리키도록 합니다.
    delete [] str2; // str2를 메모리 해지
    delete [] str3; // str3을 메모리 해지
  }

  void String::insert(unsigned position, const String &str){
    capacity = capacity + strlen(str.memory); // 새로운 문자열 str이 삽입 되므로 용량을 객체 str의 memory 길이만큼 늘려준다.
    char* temp = memory+position; // memory의 position 위치를 기억할 포인터 변수 temp 선언 및 초기화
    char* str1 = new char[capacity]; // str1을 capacity 크기 만큼 동적 메모리할당하여 빈 문자열을 생성
    char* str2 = new char[capacity]; // str2을 capacity 크기 만큼 동적 메모리할당하여 빈 문자열을 생성 
    char* str3 = new char[capacity]; // str3을 capacity 크기 만큼 동적 메모리할당하여 빈 문자열을 생성
    for(int i=0;i<capacity;++i){
      str1[i] = '\0';
      str2[i] = '\0';
      str3[i] = '\0';
    } // 빈 문자열을 생성하기 위한 구문
    // 기존 문자열을 분해해서 하나하나 cat으로 연결하며 원하는 위치에 str을 cat하는 방식으로 insert를 구현했습니다.
    strncpy(str1,memory,position); // 할당된 str1에 기존 memory의 position 만큼의 문자열을 복사
    strcpy(str2,str.memory); // 할당된 str2에 삽입될 객체 str의 memory 문자열을 복사
    strcpy(str3,temp); // 할당된 str3에 삽입 이후의 문자열 temp를 복사
    strcat(str1,str2); // str1과 str2를 연결
    strcat(str1,str3); // 를 거치면 결과적으로 str1,str2,str3이 연결됩니다. (str2는 삽입할 문자열)
    delete [] memory; // 기존 memory를 메모리 해제
    memory = new char[capacity];
    memory = str1; // memory가 새로운 동적 메모리 str1을 가리키도록 합니다.
    delete [] str2; // str2를 메모리 해지
    delete [] str3; // str3을 메모리 해지
  }
  
  // memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 삭제
  void String::erase(unsigned position, unsigned length){
      capacity = capacity - length; // 문자열이 지워지므로 지워지는 만큼(length) 용량을 조절해준다.
      if(position+length>=strlen(memory)){ // (원하는 위치) + (length) 가 문자열 memory의 크기보다 크다면 문자열의 길이를 초과해서 지우는 오류가 발생합니다.
        length = length - (position+length-strlen(memory)) ; // 따라서 위 오류의 조건을 만족시킨다면 지우는 길이(length)를 문자열의 마지막 까지만 지우게 조정해줍니다.
      } // (position+length-strlen(memory) 은 초과한 길이를 의미하며 원래 지우려는 (length) - (초과한 길이) 를 하여 문자열을 초과하여 지우는 오류가 발생하지 않게 조정해 준 것입니다.
      char* temp = memory + position + length; // 문자열 포인터 temp에 지워지는 부분 문자열 바로 다음 문자 주소를 저장합니다. 위의 length를 조절하지 않으면 문자열 memory가 할당된
      // 메모리 범위를 벗어나는 주소가 temp에 초기화 될 수 있으므로 조절해준 것입니다.
      strcpy(memory+position,temp); // memory+position 즉 지움을 당하는 주소 부터 temp를 복사 해줍니다. 이렇게 하면 문자열이 덮어 씌우지면서 지워지는 것과 같은 결과가 됩니다.
      
      char* sup = new char[capacity];
      for(int i=0;i<capacity;++i){
        sup[i] = '\0';
      }
      strcpy(sup,memory);
      delete [] memory;
      memory = sup;   
  }
  
  // memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 str로 치환
  void String::replace(unsigned position, unsigned length, const char *str){
      erase(position,length); // replace는 'erase -> insert'의 과정을 거치는 것과 동일한 과정입니다.
      insert(position,str); // 각각의 함수에 맞게 인자들을 설정해줍니다.
  }
  void String::replace(unsigned position, unsigned length, const String &str){
      erase(position,length); // replace는 'erase -> insert'의 과정을 거치는 것과 동일한 과정입니다.
      insert(position,str); // 각각의 함수에 맞게 인자들을 설정해줍니다.
  }

  
  // memory에 저장된 문자열의 position 위치부터 str 문자열을 찾으며,
  // position 뒤의 위치에서 가장 처음 str이 나타나는 위치의 인덱스를 반환
  // 찾지 못할 경우 npos를 리턴
  unsigned String::find(const char *str, unsigned position) const{
      char* temp = memory + position; // position 위치부터 탐색을 해야하므로 문자열 포인터 temp의 값을 (객체의 문자열) + (position)의 주소로 초기화 해줍니다.
      unsigned index; // 리턴할 index 변수 선언
      if(strstr(temp,str)==NULL){return npos;} // temp 즉, position의 위치부터 시작하여 str문자열을 찾아 해당 주소를 리턴해주는 strstr 함수를 사용합니다.
      // 문자열 str을 찾지 못하면 NULL 을 반환하므로 NULL 이라면 npos를 반환합니다. 
      index = strstr(temp,str) - memory; // char은 1byte이고 메모리 주소 1개당 1byte 이므로 strstr의 반환 값인 '주소'에 memory의 '시작주소'를 빼면 index와 동일합니다.
      return index; // index를 리턴해줍니다.
  } 
  // 위 find 함수의 방법과 동일합니다.   
  unsigned String::find(const String &str, unsigned position) const{
      char* temp = memory + position; // position 위치부터 탐색을 해야하므로 문자열 포인터 temp의 값을 (객체의 문자열) + (position)의 주소로 초기화 해줍니다.
      unsigned index; // 리턴할 index 변수 선언
      if(strstr(temp,str.memory)==NULL){return npos;} // temp 즉, position의 위치부터 시작하여 객체 str의 memory 문자열을 찾아 해당 주소를 리턴해주는 strstr 함수를 사용합니다.
      // 문자열 str을 찾지 못하면 NULL 을 반환하므로 NULL 이라면 npos를 반환합니다.
      index = strstr(temp,str.memory) - memory; // char은 1byte이고 메모리 주소 1개당 1byte 이므로 strstr의 반환 값인 '주소'에 memory의 '시작주소'를 빼면 index와 동일합니다.
      return index; // index를 리턴해줍니다.
  }