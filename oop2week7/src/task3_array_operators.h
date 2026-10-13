// 과제 3 · Array 클래스 정의 (교재 그림 10.10 기반 + explicit)
#pragma once
#include <iostream>

class Array
{
   friend std::ostream &operator<<( std::ostream &, const Array & );
   friend std::istream &operator>>( std::istream &, Array & );

public:
   static const std::size_t sizeDefault = 10;

   explicit Array( int = sizeDefault );  // 단일 인수 생성자 → explicit
   Array( const Array & );               // 복사 생성자 (깊은 복사)
   ~Array();                             // 소멸자

   std::size_t getSize() const;

   const Array &operator=( const Array & ); // 복사 대입 연산자
   bool operator==( const Array & ) const;  // 상등
   bool operator!=( const Array & ) const;  // 부등

   int &operator[]( int );       // 비const
   int operator[]( int ) const;  // const

private:
   std::size_t size;
   int *ptr;
};
