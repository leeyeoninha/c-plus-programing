// 과제 1 · this 포인터와 연쇄 멤버 함수 호출 (교재 그림 9.24~9.26 기반)
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time
{
public:
   explicit Time( int = 0, int = 0, int = 0 ); // 기본 생성자

   // set 함수 — Time &를 반환해 연쇄 호출을 가능하게 한다
   Time &setTime( int, int, int );
   Time &setHour( int );
   Time &setMinute( int );
   Time &setSecond( int );

   unsigned int getHour() const;
   unsigned int getMinute() const;
   unsigned int getSecond() const;

   void printUniversal() const; // HH:MM:SS
   void printStandard() const;  // HH:MM:SS AM/PM
private:
   unsigned int hour = 0;   // 0 - 23
   unsigned int minute = 0; // 0 - 59
   unsigned int second = 0; // 0 - 59
};

Time::Time( int hr, int min, int sec )
{
   setTime( hr, min, sec );
}

Time &Time::setTime( int h, int m, int s )
{
   setHour( h );
   setMinute( m );
   setSecond( s );
   return *this; // 연쇄 호출을 가능하게 함
}

Time &Time::setHour( int h )
{
   if ( h >= 0 && h < 24 )
      hour = h;
   else
      throw invalid_argument( "hour must be 0-23" );
   return *this;
}

Time &Time::setMinute( int m )
{
   if ( m >= 0 && m < 60 )
      minute = m;
   else
      throw invalid_argument( "minute must be 0-59" );
   return *this;
}

Time &Time::setSecond( int s )
{
   if ( s >= 0 && s < 60 )
      second = s;
   else
      throw invalid_argument( "second must be 0-59" );
   return *this;
}

unsigned int Time::getHour() const { return hour; }
unsigned int Time::getMinute() const { return minute; }
unsigned int Time::getSecond() const { return second; }

void Time::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << hour << ":"
      << setw( 2 ) << minute << ":" << setw( 2 ) << second;
}

void Time::printStandard() const
{
   cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << minute
      << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
}

int main()
{
   Time t;

   // 연쇄 호출: 한 문장에서 세 set 함수를 이어서 호출
   t.setHour( 18 ).setMinute( 30 ).setSecond( 22 );

   cout << "Universal time: ";
   t.printUniversal();
   cout << "\nStandard time: ";
   t.printStandard();

   int h, m, s;
   cout << "\n\n시, 분, 초를 입력하세요: ";
   if ( !( cin >> h >> m >> s ) )
   {
      cout << "숫자를 입력해야 합니다." << endl;
      return 1;
   }

   try
   {
      t.setHour( h ).setMinute( m ).setSecond( s ); // 입력값도 연쇄 호출로 설정
   }
   catch ( invalid_argument &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }

   cout << "현재 객체 상태 -> ";
   t.printUniversal();
   cout << " / ";
   t.printStandard();
   cout << endl;
}
