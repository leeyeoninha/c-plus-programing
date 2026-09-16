// time2.h — class Time 선언(인터페이스)
// 멤버 함수 정의는 time2.cpp에 있습니다.
#ifndef TIME2_H          // 헤더 중복 포함 방지
#define TIME2_H

class Time {
public:
    Time(int = 0, int = 0, int = 0);   // 기본 인자를 가진 생성자
    ~Time();                           // 소멸자
    void setTime(int, int, int);       // 유효성 검사 후 설정
    void printUniversal() const;       // 24시간 형식 출력
    void printStandard() const;        // 12시간 형식 출력
private:
    int hour;    // 0-23
    int minute;  // 0-59
    int second;  // 0-59
};

#endif
