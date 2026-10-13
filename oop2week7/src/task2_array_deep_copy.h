// 과제 2 · Array 클래스 정의 (교재 그림 10.10 기반)
#pragma once
#include <iostream>

class Array
{
   friend std::ostream &operator<<( std::ostream &, const Array & );

public:
   static const std::size_t sizeDefault = 10;

   explicit Array( int = sizeDefault ); // 기본 생성자 (크기 지정)
   Array( const Array & );              // 복사 생성자 — 깊은 복사
   ~Array();                            // 소멸자 — delete[]

   std::size_t getSize() const;

   int &operator[]( int );              // 비const: 수정 가능한 참조 반환
   int operator[]( int ) const;         // const: 값 반환

private:
   std::size_t size; // 원소 개수
   int *ptr;         // 동적 할당 배열을 가리키는 포인터
};
