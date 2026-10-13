// 과제 3 · Array 클래스 완성 — 복사 대입, == / !=, >> 입력, explicit와 static_cast
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "task3_array_operators.h"
using namespace std;

const size_t Array::sizeDefault;

Array::Array( int arraySize )
   : size( arraySize < 0 ? 0 : arraySize ),
     ptr( size > 0 ? new int[ size ]() : nullptr )
{
}

Array::Array( const Array &arrayToCopy )
   : size( arrayToCopy.size ),
     ptr( size > 0 ? new int[ size ] : nullptr )
{
   for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = arrayToCopy.ptr[ i ];
}

Array::~Array()
{
   delete[] ptr;   // new[] 와 짝
}

size_t Array::getSize() const { return size; }

// 복사 대입 연산자 — 깊은 복사
const Array &Array::operator=( const Array &right )
{
   if ( &right != this )   // 자기 대입 검사: 없으면 자기 메모리를 먼저 지워 버린다
   {
      if ( size != right.size )
      {
         delete[] ptr;                       // 기존 메모리 해제 (없으면 누수)
         size = right.size;
         ptr = size > 0 ? new int[ size ] : nullptr; // 새 크기로 할당
      }
      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = right.ptr[ i ];
   }
   return *this;   // 연쇄 대입을 위해 자기 참조 반환
}

bool Array::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false;   // 원소 개수가 다르면 다르다
   for ( size_t i = 0; i < size; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false;
   return true;
}

bool Array::operator!=( const Array &right ) const
{
   return !( *this == right );
}

int &Array::operator[]( int subscript )
{
   if ( subscript < 0 || subscript >= static_cast< int >( size ) )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ];
}

int Array::operator[]( int subscript ) const
{
   if ( subscript < 0 || subscript >= static_cast< int >( size ) )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ];
}

// 배열 전체를 4개씩 한 줄로 출력
ostream &operator<<( ostream &output, const Array &a )
{
   for ( size_t i = 0; i < a.size; ++i )
   {
      output << setw( 12 ) << a.ptr[ i ];
      if ( ( i + 1 ) % 4 == 0 )
         output << endl;
   }
   if ( a.size % 4 != 0 )
      output << endl;
   return output;
}

// 배열 전체를 입력받음
istream &operator>>( istream &input, Array &a )
{
   for ( size_t i = 0; i < a.size; ++i )
      input >> a.ptr[ i ];
   return input;
}

// const Array & 를 받는 함수 — explicit 때문에 int 로는 호출할 수 없다
void outputArray( const Array &arrayToOutput )
{
   cout << "함수가 받은 Array의 크기: " << arrayToOutput.getSize()
        << "\n내용:\n" << arrayToOutput;
}

int main()
{
   cout << "--- 1. 생성과 입력 ---\n";
   Array integers1( 7 );
   Array integers2;          // 기본 크기 10
   cout << "integers1의 크기: " << integers1.getSize() << endl;
   cout << "integers2의 크기: " << integers2.getSize() << endl;

   cout << "\nintegers1과 integers2에 17개의 정수를 입력하세요: ";
   cin >> integers1 >> integers2;
   cout << "\n입력 후:\nintegers1:\n" << integers1
        << "integers2:\n" << integers2;

   cout << "\n--- 2. != 연산자 ---\n";
   if ( integers1 != integers2 )
      cout << "integers1과 integers2는 다릅니다." << endl;

   cout << "\n--- 3. 복사 생성 (integers1으로 integers3 초기화) ---\n";
   Array integers3( integers1 );
   cout << "integers3의 크기: " << integers3.getSize() << "\n내용:\n" << integers3;

   cout << "\n--- 4. 대입 연산 (크기가 다른 경우) ---\n";
   cout << "integers2를 integers1에 대입합니다." << endl;
   integers1 = integers2;
   cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

   cout << "\n--- 5. 자기 대입 ---\n";
   integers1 = integers1;
   cout << "자기 대입 후 integers1:\n" << integers1;

   cout << "\n--- 6. 연쇄 대입 (integers3 = integers1 = integers2) ---\n";
   integers3 = integers1 = integers2;
   cout << "integers3:\n" << integers3;

   cout << "\n--- 7. == 연산자 ---\n";
   if ( integers1 == integers2 )
      cout << "integers1과 integers2는 같습니다." << endl;
   integers2[ 5 ] = 1000;
   if ( integers1 != integers2 )
      cout << "integers2[5]를 1000으로 바꾼 뒤 두 Array는 다릅니다." << endl;
   cout << "integers1[5] = " << integers1[ 5 ] << " (영향 없음 — 깊은 복사)" << endl;

   cout << "\n--- 8. explicit 생성자와 static_cast ---\n";
   outputArray( integers1 );
   // outputArray( 3 );               // 컴파일 오류: explicit 생성자는 암시적 변환에 쓰이지 않는다
   outputArray( static_cast< Array >( 3 ) ); // 명시적 변환은 허용된다

   cout << "\n--- 9. 범위를 벗어난 첨자 ---\n";
   try
   {
      integers1[ 100 ] = 1;
   }
   catch ( out_of_range &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }
}
