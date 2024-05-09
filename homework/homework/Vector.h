#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

template <class T> class Vector {
  T *_memory;   // �������� ������ T Ÿ���� �迭�� ����ų ������
  unsigned _capacity; // �������� �Ҵ�� �޸��� ũ��
  unsigned _size;     // �迭�� ����� ����� ��

public:
  Vector(unsigned capacity = 5) {
    this->_capacity = capacity;
    _memory = (T*)calloc(capacity,sizeof(T));
    _size = 0;
    // _memory�� ũ�⸦ �Ű����� capacity ũ��� �������� �Ҵ��ϰ�
    // �������� �Ҵ�� �迭�� ��Ҵ� ������ �ʱ�ȭ�ϴ� �����ڸ� ���⿡ ����
  }

  Vector(unsigned size, const T &element) {
    this->_size = size;
    this->_capacity = size*2;
    _memory = (T*)malloc(sizeof(T)*size);
    for(int i=0;i<size;++i){
      _memory[i] = element;
    }
    // �޸��� ũ��� ����� ������ size ��ŭ �����ϰ� �޸𸮸� �����ϰ�
    // ���� �޸��� �� ����� ���� element�� �ʱ�ȭ�ϴ� �ڵ带 ���⿡ ����
  }

  unsigned size() const {
    return _size;
    // ���� �迭�� ����� ����� ������ ����
  }

  unsigned capacity() const {
    return _capacity;
    // ���� �迭�� ũ�⸦ ����
  }

  const T &at(unsigned index) const {
    if(index>=0 && index<=_size){
      return _memory[index];
    }
    // printf("over the capacity!\n");
    // ���� �迭�� index ��ġ�� ����� ��Ҹ� ����
    // �迭�� ũ�⸦ �Ѵ� �ε����z ������� �ʾƵ� ��
  }

  void set(unsigned index, const T &element) {
    if(index>=_capacity){
      // printf("over the capacity!\n");
      return;
    }
    _memory[index] = element;
    // index�� ��ȿ�� ��츸 ���� �迭�� index ��ġ�� ��Ҹ� element�� ����
    // index ��Ұ� ��ȿ�ϴٴ� �ǹ̴� �迭�� ����� ������ ���� �ʴ� ������ �ε������ �ǹ�
  }

  bool empty() const {
    if(_size==0){return true;}
    else {return false;}
    // �迭�� ����� ��Ұ� ���� ��� true, �׷��� �ʴٸ� false�� ����
  }

  void push_back(const T &element) {
    // �迭�� ���� element�� �߰�
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
    // �迭�� ������ ��Ҹ� ����
    // ���̻� ������ ��Ұ� ���ٸ� ����
  }

  void erase(unsigned index) {
    if(empty()){return;}
    if(!(index>=0 && index<_size)){return;}
    for(int i=index;i+1<_size;++i){_memory[i] = _memory[i+1];}
    _size -= 1;
    // index�� ��ȿ�� ���, �迭�� index ��ġ�� ��Ҹ� ����
    // ��ȿ���� ���� ���� �ƹ� �ϵ� �Ͼ�� ����
  }

  void insert(unsigned index, const T &element) {
    if(!(index>=0 && index<_size)){return;}
    _size += 1;
    for(int i=_size-1;i>=index;--i){
      _memory[i] = _memory[i-1];
    }
    _memory[index] = element;
    // index ��ġ�� ��ȿ�� ���(�迭�� ����� ���� ���� �ʴ� ��ġ)
    // index ��ġ�� element�� ����
  }
};

#endif