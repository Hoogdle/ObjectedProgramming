// 여기에 정의되지 않은 String 클래스의 멤버 함수들을 구현

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "String.h"

  // 생성자
  String::String(){
    this->capacity = 10;
    this->memory = (char*)calloc(10,sizeof(char));
  } // 메모리의 크기(capacity)가 10인 동적 메모리를 할당하고, 이 메모리에 빈 문자열을 저장

  String::String(const char *str){
    this->capacity = strlen(str);
    this->memory = (char*)malloc(this->capacity*sizeof(char));
    strcpy(memory,str);
  }    // str 문자열을 저장할 메모리 공간을 동적으로 생성하고, 이 문자열을 memory에 저장

  String::String(const String &str){
    this->capacity = str.capacity;
    this->memory = (char*)malloc(this->capacity*sizeof(char));
    strcpy(memory,str.memory);
  }  // 복사 생성자: str에 저장된 문자열을 memory에 저장

  // 소멸자
  String::~String(){
    delete memory;
  }  // memory가 가리키는 동적 메모리를 해제


  // memory의 문자열을 str로 변경
  void String::set(const char *str){
    strcpy(memory,str);
  }  

  void String::set(const String &str){
    strcpy(memory,str.memory);
  }

  // 문자열을 리턴하는 (인라인) 함수
  // const char *get() const { return memory; };
  
  // index 위치의 문자를 반환
  // char at(unsigned index) const { return memory[index]; };
  
  // 빈문자열이면 true, 아니면 false를 리턴
  // bool empty() const { return length() == 0; };

  // length(), size() 모두 문자열의 길이를 반환
  unsigned String::length() const{
    return this->capacity;
  }
  unsigned String::size() const{
    return this->capacity;
  }


  // 위치(인덱스)가 position인 위치부터 길이가 length인 부분 문자열을 String 객체로 리턴
  String String::substr(unsigned position, unsigned length) const{
      char *addr = memory+position;
      strncpy(addr,addr,length);
      String temp = addr;
      return temp;
  }
  
  // memory의 position 위치에 str 을 삽입
  void String::insert(unsigned position, const char *str){
      char *temp = memory + position;
      strncpy(memory,memory,position);
      strcat(memory,str);
      strcat(memory,temp);
  }

  void String::insert(unsigned position, const String &str){
      char *temp = memory + position;
      strncpy(memory,memory,position);
      strcat(memory,str.memory);
      strcat(memory,temp);
  }
  
  // memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 삭제
  void String::erase(unsigned position, unsigned length){
      char* temp = memory + position + length;
      strcpy(memory+position,temp);
  }
  
  // memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 str로 치환
  void String::replace(unsigned position, unsigned length, const char *str){
      erase(position,length);
      insert(position,str);
  }
  void String::replace(unsigned position, unsigned length, const String &str){
      erase(position,length);
      insert(position,str.memory);
  }

  
  // memory에 저장된 문자열의 position 위치부터 str 문자열을 찾으며,
  // position 뒤의 위치에서 가장 처음 str이 나타나는 위치의 인덱스를 반환
  // 찾지 못할 경우 npos를 리턴
  unsigned String::find(const char *str, unsigned position) const{
      char* temp = memory + position;
      unsigned index = -1;
      if(strstr(temp,str)==NULL){return npos;}
      index = strstr(temp,str) - temp;
      return index;
  }    
  unsigned String::find(const String &str, unsigned position) const{
      char* temp = memory + position;
      unsigned index = -1;
      if(strstr(temp,str.memory)==NULL){return npos;}
      index = strstr(temp,str.memory) - temp;
      return index;
  }