// 과제 1 · 동적 메모리 할당 기초 — new / new[] / 값 초기화 / delete[]
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   // 1) new int  와  new int()  의 차이
   int *noInit = new int;      // 값 초기화하지 않음 → 쓰레기값 (읽지 않는다)
   int *zeroed = new int();    // 값 초기화 → 0
   cout << "new int()  : " << *zeroed << "   (값 초기화)\n";
   cout << "new int    : 값 초기화하지 않으므로 읽지 않음 (쓰레기값)\n\n";
   delete noInit;
   delete zeroed;

   // 2) 배열 동적 할당 — 원소를 0으로 값 초기화
   int n;
   cout << "배열의 크기를 입력하세요: ";
   if ( !( cin >> n ) || n <= 0 )
   {
      cout << "1 이상의 정수를 입력해야 합니다." << endl;
      return 1;
   }

   int *grades = new int[ n ]();   // () → 모든 원소를 0으로 초기화
   cout << "할당 직후 (모두 0):";
   for ( int i = 0; i < n; ++i )
      cout << setw( 5 ) << grades[ i ];
   cout << "\n\n";

   // 3) 목록 초기화자로 일부만 지정 (C++11)
   int *fixedArr = new int[ 5 ]{ 1, 2, 3 };  // 나머지 두 원소는 0
   cout << "new int[5]{ 1, 2, 3 } :";
   for ( int i = 0; i < 5; ++i )
      cout << setw( 5 ) << fixedArr[ i ];
   cout << "\n\n";
   delete[] fixedArr;   // new[] 로 할당했으므로 delete[]

   // 4) 값을 입력받아 합·평균·최댓값 계산
   cout << n << "개의 정수를 입력하세요: ";
   for ( int i = 0; i < n; ++i )
   {
      if ( !( cin >> grades[ i ] ) )
      {
         cout << "숫자를 입력해야 합니다." << endl;
         delete[] grades;
         return 1;
      }
   }

   long long sum = 0;
   int maxValue = grades[ 0 ];
   for ( int i = 0; i < n; ++i )
   {
      sum += grades[ i ];
      if ( grades[ i ] > maxValue )
         maxValue = grades[ i ];
   }

   cout << "합계   : " << sum << endl;
   cout << "평균   : " << fixed << setprecision( 2 )
        << static_cast< double >( sum ) / n << endl;
   cout << "최댓값 : " << maxValue << "\n\n";

   delete[] grades;   // 다 쓴 뒤 반드시 해제 — new[] 와 짝
   cout << "메모리를 해제했습니다." << endl;
}
