// 과제 2 · Array 클래스 — 동적 할당과 깊은 복사
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "task2_array_deep_copy.h"
using namespace std;

const size_t Array::sizeDefault;

// 기본 생성자: size개의 원소를 0으로 초기화해 동적 할당
Array::Array( int arraySize )
   : size( arraySize < 0 ? 0 : arraySize ),
     ptr( size > 0 ? new int[ size ]() : nullptr )  // () 로 값 초기화 → 0
{
   // new int[ size ]() 가 모든 원소를 0으로 초기화하므로 따로 반복할 필요가 없다
   cout << "  [Array 생성자] size=" << size << endl;
}

// 복사 생성자: 새 메모리를 할당하고 원소를 하나씩 복사한다 (깊은 복사)
//   반드시 참조로 받아야 한다. 값으로 받으면 복사본을 만들기 위해 복사 생성자를
//   다시 호출하게 되어 무한 재귀가 된다.
Array::Array( const Array &arrayToCopy )
   : size( arrayToCopy.size ),
     ptr( size > 0 ? new int[ size ] : nullptr )
{
   for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = arrayToCopy.ptr[ i ];
   cout << "  [Array 복사 생성자] size=" << size << " (깊은 복사)" << endl;
}

// 소멸자: new[] 로 할당했으므로 delete[] 로 해제
Array::~Array()
{
   cout << "  [Array 소멸자] size=" << size << " 메모리 해제" << endl;
   delete[] ptr;
}

size_t Array::getSize() const { return size; }

// 비const 객체용: 참조를 반환하므로 array[i] = 값; 이 가능
int &Array::operator[]( int subscript )
{
   if ( subscript < 0 || subscript >= static_cast< int >( size ) )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ];
}

// const 객체용: 값을 반환하므로 읽기만 가능
int Array::operator[]( int subscript ) const
{
   if ( subscript < 0 || subscript >= static_cast< int >( size ) )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ];
}

ostream &operator<<( ostream &output, const Array &a )
{
   for ( size_t i = 0; i < a.size; ++i )
   {
      output << setw( 8 ) << a.ptr[ i ];
      if ( ( i + 1 ) % 4 == 0 )
         output << endl;
   }
   if ( a.size % 4 != 0 )
      output << endl;
   return output;
}

// 값으로 받아 복사 생성자가 호출되는지 확인하는 함수
void printByValue( Array a )
{
   cout << "printByValue 안에서 (값 전달):\n" << a;
}

// 값으로 반환해 복사 생성자가 호출되는지 확인하는 함수
Array makeFilled( size_t n, int value )
{
   Array temp( static_cast< int >( n ) );
   for ( size_t i = 0; i < n; ++i )
      temp[ static_cast< int >( i ) ] = value + static_cast< int >( i );
   return temp;
}

int main()
{
   cout << "--- 1. 기본 생성 ---\n";
   Array a( 5 );

   cout << "\n--- 2. operator[] 로 값 채우기 ---\n";
   for ( int i = 0; i < 5; ++i )
      a[ i ] = ( i + 1 ) * 10;
   cout << a;

   cout << "\n--- 3. 복사 생성 (선언과 함께 = 를 쓴 경우) ---\n";
   Array b = a;              // 대입이 아니라 복사 생성자 호출
   b[ 0 ] = 999;
   cout << "a:\n" << a;
   cout << "b (b[0]만 바꿈):\n" << b;

   cout << "\n--- 4. 함수에 값으로 전달 ---\n";
   printByValue( a );

   cout << "\n--- 5. 함수에서 값으로 반환 ---\n";
   Array c = makeFilled( 4, 100 );
   cout << "반환받은 c:\n" << c;

   cout << "\n--- 6. 범위를 벗어난 첨자 ---\n";
   try
   {
      cout << "a[ 10 ] 을 실행합니다." << endl;
      a[ 10 ] = 1;
   }
   catch ( out_of_range &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }

   cout << "\n--- 7. main 종료 (소멸 순서 확인) ---\n";
}
