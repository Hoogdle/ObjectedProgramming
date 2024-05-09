#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

template <class T> class Vector {
  T *_memory;   // 동적으로 생성한 T 타입의 배열을 가리킬 포인터
  unsigned _capacity; // 동적으로 할당된 메모리의 크기
  unsigned _size;     // 배열에 저장된 요소의 수

public:
  Vector(unsigned capacity = 5) {
    this->_capacity = capacity;
    _memory = (T*)calloc(capacity,sizeof(T));
    _size = 0;
    // _memory의 크기를 매개변수 capacity 크기로 동적으로 할당하고
    // 동적으로 할당된 배열의 요소는 없도록 초기화하는 생성자를 여기에 구현
  }

  Vector(unsigned size, const T &element) {
    this->_size = size;
    this->_capacity = size*2;
    _memory = (T*)malloc(sizeof(T)*size);
    for(int i=0;i<size;++i){
      _memory[i] = element;
    }
    // 메모리의 크기와 요소의 개수를 size 만큼 설정하고 메모리를 생성하고
    // 동적 메모리의 각 요소의 값은 element로 초기화하는 코드를 여기에 구현
  }

  unsigned size() const {
    return _size;
    // 동적 배열에 저장된 요소의 갯수를 리턴
  }

  unsigned capacity() const {
    return _capacity;
    // 동적 배열의 크기를 리턴
  }

  const T &at(unsigned index) const {
    if(index>=0 && index<=_size){
      return _memory[index];
    }
    // printf("over the capacity!\n");
    // 동적 배열의 index 위치에 저장된 요소를 리턴
    // 배열의 크기를 넘는 인덱스틑 고려하지 않아도 됨
  }

  void set(unsigned index, const T &element) {
    if(index>=_capacity){
      // printf("over the capacity!\n");
      return;
    }
    _memory[index] = element;
    // index가 유효할 경우만 동적 배열의 index 위치의 요소를 element로 변경
    // index 요소가 유효하다는 의미는 배열의 요소의 갯수를 넘지 않는 범위의 인덱스라는 의미
  }

  bool empty() const {
    if(_size==0){return true;}
    else {return false;}
    // 배열에 저장된 요소가 없을 경우 true, 그렇지 않다면 false를 리턴
  }

  void push_back(const T &element) {
    // 배열의 끝에 element를 추가
    if(_size==_capacity){
      _capacity *= 2;
      _memory = (T*)realloc(_memory,sizeof(T)*_capacity);
    }
    ++_size;
    _memory[_size-1] = element;
  }

  void pop_back() {
    if(empty()){return;}
    _size -= 1;
    // 배열의 마지막 요소를 제거
    // 더이상 제거할 요소가 없다면 무시
  }

  void erase(unsigned index) {
    if(empty()){return;}
    if(!(index>=0 && index<_size)){return;}
    for(int i=index;i+1<_size;++i){_memory[i] = _memory[i+1];}
    _size -= 1;
    // index가 유효한 경우, 배열의 index 위치의 요소를 삭제
    // 유효하지 않은 경우는 아무 일도 일어나지 않음
  }

  void insert(unsigned index, const T &element) {
    if(!(index>=0 && index<_size)){return;}
    _size += 1;
    for(int i=_size-1;i>=index;--i){
      _memory[i] = _memory[i-1];
    }
    _memory[index] = element;
    // index 위치가 유효한 경우(배열의 요소의 수를 넘지 않는 위치)
    // index 위치에 element를 삽입
  }
};

#endif