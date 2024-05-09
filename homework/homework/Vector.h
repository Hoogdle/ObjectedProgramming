#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

template <class T> class Vector {
  T *_memory;   // 동적으로 생성한 T 타입의 배열을 가리킬 포인터
  unsigned _capacity; // 동적으로 할당된 메모리의 크기
  unsigned _size;     // 배열에 저장된 요소의 수

public:
  Vector(unsigned capacity = 5) { // 어떤 size 매개변수도 받지 못한 경우, default 매개변수를 5로 설정
    this->_capacity = capacity; // 매개변수로 받은 만큼 capacity를 설정
    _memory = (T*)calloc(capacity,sizeof(T)); // 설정한 capacity만큼 빈 동적 메모리 할당
    _size = 0; // 빈 벡터이므로 size를 0으로 설정
    // _memory의 크기를 매개변수 capacity 크기로 동적으로 할당하고
    // 동적으로 할당된 배열의 요소는 없도록 초기화하는 생성자를 여기에 구현
  }

  Vector(unsigned size, const T &element) { // 사이즈와 element를 매개변수로 받은 경우
    this->_size = size; // size를 매개변수로 받은 size로 변경
    this->_capacity = size*2; // capacity를 받은 size 만큼 초기화
    _memory = (T*)malloc(sizeof(T)*size); // 할당된 size만큼을 담을 수 있는 동적메모리 할당
    for(int i=0;i<size;++i){
      _memory[i] = element; // 반복문을 활용해서 동적메모리에 element를 size만큼 넣어준다.
    }
    // 메모리의 크기와 요소의 개수를 size 만큼 설정하고 메모리를 생성하고
    // 동적 메모리의 각 요소의 값은 element로 초기화하는 코드를 여기에 구현
  }

  unsigned size() const {
    return _size; // 동적메모리의 요소만큼 return
    // 동적 배열에 저장된 요소의 갯수를 리턴
  }

  unsigned capacity() const {
    return _capacity; // 동적메모리의 capacity만큼 return
    // 동적 배열의 크기를 리턴
  }

  const T &at(unsigned index) const {
    if(index>=0 && index<_size){ // index가 유효한 경우, 즉 index가 0~(size-1)인 경우
      return _memory[index]; // 해당 인덱스의 벡터 요소를 반환
    }
    // 동적 배열의 index 위치에 저장된 요소를 리턴
    // 배열의 크기를 넘는 인덱스틑 고려하지 않아도 됨
  }

  void set(unsigned index, const T &element) {
    if(index>=_capacity){ // index가 유효하지 않은 경우 == index가 capacity의 이상인 경우
      return;
    }
    _memory[index] = element; // memory의 index에 element를 저장
    // index가 유효할 경우만 동적 배열의 index 위치의 요소를 element로 변경
    // index 요소가 유효하다는 의미는 배열의 요소의 갯수를 넘지 않는 범위의 인덱스라는 의미
  }

  bool empty() const {
    if(_size==0){return true;} // empty인 경우는 설정된 size가 0인 경우와 동치. 따라서 size가 0인 경우 true를 리턴
    else {return false;} // size가 0이 아닌 경우 false 리턴
    // 배열에 저장된 요소가 없을 경우 true, 그렇지 않다면 false를 리턴
  }

  void push_back(const T &element) {
    // 배열의 끝에 element를 추가
    if(_size==_capacity){ // size와 capacity가 같은 경우 새로운 요소가 추가 될 수 있게 capacity를 늘려줘야 합니다.
      _capacity *= 2; // 위 if문을 만족하면 capacity를 2배로 늘려줍니다.
      _memory = (T*)realloc(_memory,sizeof(T)*_capacity); // 늘려준 capacity을 적용하기 위해 memory를 realloc 해줍니다.
    }
    ++_size; // element가 추가되므로 size를 하나 증가시켜준다.
    _memory[_size-1] = element; // 가장 뒤 index에 element를 추가해준다.
  }

  void pop_back() {
    if(empty()){return;} // empty가 true를 리턴하면 즉, 공백 벡터라면 함수 종료
    _size -= 1; // 벡터가 공백이 아니라면 size를 하나 줄여준다.
    // 배열의 마지막 요소를 제거
    // 더이상 제거할 요소가 없다면 무시
  }

  void erase(unsigned index) {
    if(empty()){return;} // 공백 벡터라면 지울 데이터가 없으므로 함수를 종료합니다.
    if(!(index>=0 && index<_size)){return;} // index가 유효하지 않으면(index가 0~(size-1)이 아니라면) 함수 종료
    for(int i=index;i+1<_size;++i){_memory[i] = _memory[i+1];} // 지워야할 index를 기준으로 데이터를 앞으로 하나씩 당겨줍니다. 이렇게 하면 데이터가 한 칸씩 이동하며 덮어씌워지면서 지우는 것과 동일한 결과가 나옵니다.
    // 데이터가 없는 것을 가리키면 안 되므로 반복문을 i<size가 아닌 i+1<size 만큼 반복합니다. 
    _size -= 1; // 데이터가 하나 지워졌으므로 size를 하나 감소시킵니다.
    // index가 유효한 경우, 배열의 index 위치의 요소를 삭제
    // 유효하지 않은 경우는 아무 일도 일어나지 않음
  }

  void insert(unsigned index, const T &element) {
    if(!(index>=0 && index<_size)){return;} // index가 유효하지 않으면(index가 0~(size-1)이 아니라면) 함수 종료
    _size += 1; // 데이터가 추가되므로 size를 하나 추가시켜준다.
    for(int i=_size-1;i>=index;--i){ // size-1 즉 size의 max index 부터 데이터를 삽입할 index까지 i의 값을 하나씩 줄여가며 반복문을 진행합니다.
      _memory[i] = _memory[i-1]; // 삽입될 인덱스를 기준으로 데이터를 하나씩 뒤로 밀어줍니다.
    }
    _memory[index] = element; // 삽입될 인덱스에 삽입할 데이터를 넣어줍니다.
    // index 위치가 유효한 경우(배열의 요소의 수를 넘지 않는 위치)
    // index 위치에 element를 삽입
  }
};

#endif