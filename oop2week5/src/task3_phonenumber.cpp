// 과제 3 · 스트림 삽입·추출 연산자 오버로딩 + 입력 형식 검사 (교재 그림 10.3~10.5 기반)
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class PhoneNumber
{
   friend ostream &operator<<( ostream &, const PhoneNumber & );
   friend istream &operator>>( istream &, PhoneNumber & );
private:
   string areaCode; // 3자리 지역 번호
   string exchange; // 3자리 국번
   string line;     // 4자리 번호
};

// 모든 문자가 숫자이고 길이가 len인지 검사
bool isDigits( const string &s, size_t len )
{
   if ( s.size() != len )
      return false;
   for ( char c : s )
      if ( !isdigit( static_cast<unsigned char>( c ) ) )
         return false;
   return true;
}

ostream &operator<<( ostream &output, const PhoneNumber &number )
{
   output << "(" << number.areaCode << ") "
      << number.exchange << "-" << number.line;
   return output; // cout << a << b << c; 연쇄를 가능하게 함
}

istream &operator>>( istream &input, PhoneNumber &number )
{
   PhoneNumber temp; // 검사를 모두 통과했을 때만 number에 반영

   input >> ws;                                   // 앞쪽 공백 건너뜀
   if ( input.get() != '(' )                      // '(' 확인
   {
      input.setstate( ios::failbit );
      return input;
   }
   input >> setw( 3 ) >> temp.areaCode;           // 지역 번호
   if ( input.get() != ')' || input.get() != ' ' ) // ") " 확인
   {
      input.setstate( ios::failbit );
      return input;
   }
   input >> setw( 3 ) >> temp.exchange;           // 국번
   if ( input.get() != '-' )                      // '-' 확인
   {
      input.setstate( ios::failbit );
      return input;
   }
   input >> setw( 4 ) >> temp.line;               // 번호

   if ( !isDigits( temp.areaCode, 3 ) || !isDigits( temp.exchange, 3 )
        || !isDigits( temp.line, 4 ) )
   {
      input.setstate( ios::failbit );
      return input;
   }

   number = temp;
   return input; // cin >> a >> b >> c; 연쇄를 가능하게 함
}

int main()
{
   PhoneNumber phone;

   cout << "Enter phone number in the form (123) 456-7890:" << endl;

   if ( cin >> phone ) // operator>>( cin, phone ) 호출 후 스트림 상태 검사
      cout << "The phone number entered was: " << phone << endl;
   else
      cout << "형식이 올바르지 않습니다." << endl;
}
