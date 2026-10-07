// 과제 3 · 이항 산술 연산자와 >> 오버로딩 — 날짜 계산기 (교재 그림 10.6~10.8 + 10.5 기반)
#include <array>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Date
{
   friend ostream &operator<<( ostream &, const Date & );
   friend istream &operator>>( istream &, Date & );
public:
   Date( int m = 1, int d = 1, int y = 1900 );
   void setDate( int, int, int );
   Date &operator++();
   Date operator++( int );
   Date &operator+=( unsigned int );

   // ---- 이번 과제에서 추가 ----
   Date operator+( unsigned int ) const;   // Date + n  (값 반환)
   int operator-( const Date & ) const;    // Date - Date → 날짜 차이(일)
   bool operator==( const Date & ) const;
   bool operator<( const Date & ) const;

   static bool leapYear( int );
   bool endOfMonth( int ) const;
private:
   unsigned int month;
   unsigned int day;
   unsigned int year;
   static const array< unsigned int, 13 > days;
   void helpIncrement();
};

Date operator+( unsigned int, const Date & ); // n + Date  (비멤버)

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

// + 는 += 에 위임한다 — 복사본을 만들어 늘린 뒤 값으로 반환
Date Date::operator+( unsigned int n ) const
{
   Date result = *this;
   result += n;
   return result;
}

// 왼쪽 피연산자가 Date가 아니므로 비멤버. private 접근이 필요 없어 friend도 아니다
Date operator+( unsigned int n, const Date &d )
{
   return d + n;
}

bool Date::operator==( const Date &right ) const
{
   return year == right.year && month == right.month && day == right.day;
}

bool Date::operator<( const Date &right ) const
{
   if ( year != right.year )
      return year < right.year;
   if ( month != right.month )
      return month < right.month;
   return day < right.day;
}

// 이른 날짜에서 늦은 날짜까지 하루씩 세어 차이를 구한다 (this가 이르면 음수)
int Date::operator-( const Date &right ) const
{
   bool negative = *this < right;
   Date from = negative ? *this : right;
   const Date &to = negative ? right : *this;

   int count = 0;
   while ( !( from == to ) )
   {
      ++from;
      ++count;
   }
   return negative ? -count : count;
}

bool Date::leapYear( int testYear )
{
   return testYear % 400 == 0 || ( testYear % 100 != 0 && testYear % 4 == 0 );
}

bool Date::endOfMonth( int testDay ) const
{
   if ( month == 2 && leapYear( year ) )
      return testDay == 29;
   else
      return testDay == static_cast< int >( days[ month ] );
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

ostream &operator<<( ostream &output, const Date &d )
{
   static string monthName[ 13 ] = { "", "January", "February", "March", "April",
      "May", "June", "July", "August", "September", "October", "November", "December" };
   output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
   return output;
}

// MM/DD/YYYY 형식으로 입력
//  - 구분자가 '/'가 아니거나 숫자가 아니면 failbit (형식 오류)
//  - 범위 밖이면 setDate가 던지는 invalid_argument가 전파 (값 오류)
istream &operator>>( istream &input, Date &d )
{
   int m, dd, y;
   char s1, s2;
   if ( input >> m >> s1 >> dd >> s2 >> y && s1 == '/' && s2 == '/' )
      d.setDate( m, dd, y );
   else
      input.setstate( ios::failbit );
   return input;
}

int main()
{
   Date start;
   int n;

   cout << "날짜(MM/DD/YYYY)와 더할 일 수를 입력하세요: ";
   try
   {
      if ( !( cin >> start >> n ) )
      {
         cout << "형식이 올바르지 않습니다." << endl;
         return 1;
      }
      if ( n < 0 )
      {
         cout << "더할 일 수는 0 이상이어야 합니다." << endl;
         return 1;
      }
      unsigned int addDays = static_cast< unsigned int >( n );

      Date later = start + addDays;
      Date later2 = addDays + start;   // 비멤버 operator+
      cout << start << " + " << n << " = " << later << endl;
      cout << n << " + " << start << " = " << later2 << endl;
      cout << "start는 그대로: " << start << endl;
      cout << "later - start = " << ( later - start ) << "일" << endl;
      cout << "start - later = " << ( start - later ) << "일" << endl;
   }
   catch ( invalid_argument &e )
   {
      cout << "예외 발생: " << e.what() << endl;
   }
}
