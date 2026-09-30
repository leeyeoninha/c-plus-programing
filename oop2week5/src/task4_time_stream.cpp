// 도전 과제 · Time 클래스에 << >> 오버로딩 (9장 Time + 10.5 종합)
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time
{
   friend ostream &operator<<( ostream &, const Time & );
   friend istream &operator>>( istream &, Time & );
public:
   explicit Time( int = 0, int = 0, int = 0 );
   Time &setTime( int, int, int );
   Time &setHour( int );
   Time &setMinute( int );
   Time &setSecond( int );
private:
   unsigned int hour = 0;
   unsigned int minute = 0;
   unsigned int second = 0;
};

Time::Time( int h, int m, int s ) { setTime( h, m, s ); }

Time &Time::setTime( int h, int m, int s )
{
   setHour( h );
   setMinute( m );
   setSecond( s );
   return *this;
}

Time &Time::setHour( int h )
{
   if ( h < 0 || h > 23 )
      throw invalid_argument( "hour must be 0-23" );
   hour = h;
   return *this;
}

Time &Time::setMinute( int m )
{
   if ( m < 0 || m > 59 )
      throw invalid_argument( "minute must be 0-59" );
   minute = m;
   return *this;
}

Time &Time::setSecond( int s )
{
   if ( s < 0 || s > 59 )
      throw invalid_argument( "second must be 0-59" );
   second = s;
   return *this;
}

// HH:MM:SS 형식으로 출력
ostream &operator<<( ostream &output, const Time &t )
{
   output << setfill( '0' ) << setw( 2 ) << t.hour << ":"
      << setw( 2 ) << t.minute << ":" << setw( 2 ) << t.second
      << setfill( ' ' ); // 채움 문자를 원래대로 되돌림
   return output;
}

// HH:MM:SS 형식으로 입력
//  - 형식 오류(구분자가 ':'이 아님, 숫자가 아님) → failbit
//  - 값 오류(범위 밖) → set 함수가 던진 invalid_argument가 그대로 전파
istream &operator>>( istream &input, Time &t )
{
   int h, m, s;
   char c1, c2;

   if ( input >> h >> c1 >> m >> c2 >> s && c1 == ':' && c2 == ':' )
      t.setTime( h, m, s );
   else
      input.setstate( ios::failbit );

   return input;
}

int main()
{
   Time start, end;

   cout << "시작 시각과 종료 시각을 입력하세요 (HH:MM:SS HH:MM:SS): ";

   try
   {
      if ( cin >> start >> end ) // 연쇄 입력
         cout << "start = " << start << ", end = " << end << endl;
      else
         cout << "형식이 올바르지 않습니다." << endl;
   }
   catch ( invalid_argument &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }
}
