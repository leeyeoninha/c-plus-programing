// 과제 1 · 전위·후위 ++ / -- 와 += 오버로딩 — Time 클래스 (교재 그림 9.24 Time + 10.7 기반)
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time
{
   friend ostream &operator<<( ostream &, const Time & );
public:
   explicit Time( int = 0, int = 0, int = 0 );
   Time &setTime( int, int, int );

   Time &operator++();          // 전위 ++ : 1초 증가
   Time operator++( int );      // 후위 ++
   Time &operator--();          // 전위 -- : 1초 감소
   Time operator--( int );      // 후위 --
   Time &operator+=( unsigned int ); // 지정한 초만큼 증가
private:
   unsigned int hour = 0;   // 0 - 23
   unsigned int minute = 0; // 0 - 59
   unsigned int second = 0; // 0 - 59
   void tick();     // 1초 증가 (23:59:59 → 00:00:00)
   void untick();   // 1초 감소 (00:00:00 → 23:59:59)
};

Time::Time( int h, int m, int s )
{
   setTime( h, m, s );
}

Time &Time::setTime( int h, int m, int s )
{
   if ( h < 0 || h > 23 )
      throw invalid_argument( "hour must be 0-23" );
   if ( m < 0 || m > 59 )
      throw invalid_argument( "minute must be 0-59" );
   if ( s < 0 || s > 59 )
      throw invalid_argument( "second must be 0-59" );
   hour = h;
   minute = m;
   second = s;
   return *this;
}

void Time::tick()
{
   if ( second < 59 )
      ++second;
   else
   {
      second = 0;
      if ( minute < 59 )
         ++minute;
      else
      {
         minute = 0;
         hour = ( hour < 23 ) ? hour + 1 : 0;
      }
   }
}

void Time::untick()
{
   if ( second > 0 )
      --second;
   else
   {
      second = 59;
      if ( minute > 0 )
         --minute;
      else
      {
         minute = 59;
         hour = ( hour > 0 ) ? hour - 1 : 23;
      }
   }
}

Time &Time::operator++()
{
   tick();
   return *this;      // 증가된 자기 자신을 참조로 반환
}

Time Time::operator++( int )
{
   Time temp = *this; // 증가 전 상태 저장
   tick();
   return temp;       // 증가 전 값을 값으로 반환
}

Time &Time::operator--()
{
   untick();
   return *this;
}

Time Time::operator--( int )
{
   Time temp = *this;
   untick();
   return temp;
}

Time &Time::operator+=( unsigned int seconds )
{
   for ( unsigned int i = 0; i < seconds; ++i )
      tick();
   return *this;      // 연쇄를 위해 참조 반환
}

ostream &operator<<( ostream &output, const Time &t )
{
   output << setfill( '0' ) << setw( 2 ) << t.hour << ":"
      << setw( 2 ) << t.minute << ":" << setw( 2 ) << t.second << setfill( ' ' );
   return output;
}

int main()
{
   Time t1( 23, 59, 58 );
   cout << "t1 = " << t1 << endl;
   cout << "++t1 = " << ++t1 << endl;
   cout << "t1++ = " << t1++ << endl;
   cout << "t1 = " << t1 << "\n\n";

   Time t2;
   cout << "t2 = " << t2 << endl;
   cout << "--t2 = " << --t2 << endl;
   cout << "t2-- = " << t2-- << endl;
   cout << "t2 = " << t2 << "\n\n";

   Time t3( 10, 58, 30 );
   cout << "t3 = " << t3 << endl;
   cout << "t3 += 95 -> " << ( t3 += 95 ) << endl;
   cout << "(t3 += 30) += 30 -> " << ( ( t3 += 30 ) += 30 ) << "\n\n";

   int h, m, s, add;
   cout << "시, 분, 초와 더할 초를 입력하세요: ";
   if ( !( cin >> h >> m >> s >> add ) )
   {
      cout << "숫자를 입력해야 합니다." << endl;
      return 1;
   }
   if ( add < 0 )
   {
      cout << "더할 초는 0 이상이어야 합니다." << endl;
      return 1;
   }
   try
   {
      Time t4( h, m, s );
      cout << "입력 시각: " << t4 << endl;
      cout << add << "초 후: " << ( t4 += static_cast< unsigned int >( add ) ) << endl;
   }
   catch ( invalid_argument &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }
}
