// 과제 2 · 전위·후위 -- 와 관계 연산자 6개 오버로딩 — Date 클래스 확장 (교재 그림 10.6~10.8 기반)
#include <array>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Date
{
   friend ostream &operator<<( ostream &, const Date & );
public:
   Date( int m = 1, int d = 1, int y = 1900 );
   void setDate( int, int, int );
   Date &operator++();
   Date operator++( int );
   Date &operator+=( unsigned int );

   // ---- 이번 과제에서 추가 ----
   Date &operator--();          // 전위 --
   Date operator--( int );      // 후위 --
   bool operator==( const Date & ) const;
   bool operator!=( const Date & ) const;
   bool operator<( const Date & ) const;
   bool operator>( const Date & ) const;
   bool operator<=( const Date & ) const;
   bool operator>=( const Date & ) const;

   static bool leapYear( int );
   bool endOfMonth( int ) const;
private:
   unsigned int month;
   unsigned int day;
   unsigned int year;

   static const array< unsigned int, 13 > days;
   void helpIncrement();
   void helpDecrement();                    // 추가
   unsigned int lastDay( unsigned int ) const; // 추가: 해당 월의 마지막 날
};

const array< unsigned int, 13 > Date::days =
   { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date( int month, int day, int year )
{
   setDate( month, day, year );
}

void Date::setDate( int mm, int dd, int yy )
{
   if ( mm >= 1 && mm <= 12 )
      month = mm;
   else
      throw invalid_argument( "Month must be 1-12" );

   if ( yy >= 1900 && yy <= 2100 )
      year = yy;
   else
      throw invalid_argument( "Year must be >= 1900 and <= 2100" );

   if ( ( month == 2 && leapYear( year ) && dd >= 1 && dd <= 29 ) ||
        ( dd >= 1 && dd <= static_cast< int >( days[ month ] ) ) )
      day = dd;
   else
      throw invalid_argument( "Day is out of range for current month and year" );
}

Date &Date::operator++()
{
   helpIncrement();
   return *this;
}

Date Date::operator++( int )
{
   Date temp = *this;
   helpIncrement();
   return temp;
}

Date &Date::operator+=( unsigned int additionalDays )
{
   for ( unsigned int i = 0; i < additionalDays; ++i )
      helpIncrement();
   return *this;
}

Date &Date::operator--()
{
   helpDecrement();
   return *this;
}

Date Date::operator--( int )
{
   Date temp = *this;
   helpDecrement();
   return temp;
}

// 연 → 월 → 일 순서로 비교
bool Date::operator<( const Date &right ) const
{
   if ( year != right.year )
      return year < right.year;
   if ( month != right.month )
      return month < right.month;
   return day < right.day;
}

bool Date::operator==( const Date &right ) const
{
   return year == right.year && month == right.month && day == right.day;
}

// 나머지 넷은 < 와 == 를 이용해 작성 — 규칙이 한 곳에만 있도록
bool Date::operator!=( const Date &right ) const { return !( *this == right ); }
bool Date::operator>( const Date &right ) const { return right < *this; }
bool Date::operator<=( const Date &right ) const { return !( right < *this ); }
bool Date::operator>=( const Date &right ) const { return !( *this < right ); }

bool Date::leapYear( int testYear )
{
   return testYear % 400 == 0 || ( testYear % 100 != 0 && testYear % 4 == 0 );
}

unsigned int Date::lastDay( unsigned int m ) const
{
   return ( m == 2 && leapYear( year ) ) ? 29 : days[ m ];
}

bool Date::endOfMonth( int testDay ) const
{
   return testDay == static_cast< int >( lastDay( month ) );
}

void Date::helpIncrement()
{
   if ( !endOfMonth( day ) )
      ++day;
   else if ( month < 12 )
   {
      ++month;
      day = 1;
   }
   else
   {
      ++year;
      month = 1;
      day = 1;
   }
}

void Date::helpDecrement()
{
   if ( day > 1 )
      --day;
   else if ( month > 1 )
   {
      --month;
      day = lastDay( month ); // 이전 달의 마지막 날 (윤년 반영)
   }
   else
   {
      if ( year == 1900 )
         throw out_of_range( "Date cannot go before January 1, 1900" );
      --year;
      month = 12;
      day = 31;
   }
}

ostream &operator<<( ostream &output, const Date &d )
{
   static string monthName[ 13 ] = { "", "January", "February", "March", "April",
      "May", "June", "July", "August", "September", "October", "November", "December" };
   output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
   return output;
}

int main()
{
   Date d1( 3, 1, 2024 );
   cout << "d1 = " << d1 << endl;
   cout << "--d1 = " << --d1 << "  (2024년은 윤년)" << endl;
   Date d2( 3, 1, 2100 );
   cout << "--d2 = " << --d2 << "  (2100년은 윤년 아님)" << endl;
   Date d3( 1, 1, 2011 );
   cout << "d3-- = " << d3-- << endl;
   cout << "d3 = " << d3 << "\n\n";

   Date a( 7, 14, 2010 ), b( 7, 15, 2010 ), c( 7, 14, 2010 );
   cout << boolalpha;
   cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
   cout << "a == c : " << ( a == c ) << "   a != b : " << ( a != b ) << endl;
   cout << "a <  b : " << ( a < b ) << "   a >  b : " << ( a > b ) << endl;
   cout << "a <= c : " << ( a <= c ) << "   b >= a : " << ( b >= a ) << endl;
   cout << "++a == b : " << ( ++a == b ) << "\n\n";

   Date first;
   cout << "first = " << first << endl;
   try
   {
      --first;
   }
   catch ( out_of_range &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }
   cout << "first = " << first << endl;
}
