// Manip.h — 문제 3 [상] 모범 답안 : 클래스로 만든 스트림 조작자
#pragma once
#include <iostream>
#include <iomanip>

// ============================================================
// [0] 교재 13.6.4 방식 — 함수형 조작자 (매개변수 없음)
//     cout << endLine;  은 함수 포인터를 넘기고,
//     ostream::operator<<(ostream& (*)(ostream&)) 가 그 함수를 호출한다.
// ============================================================
inline std::ostream& endLine(std::ostream& out)
{
    return out << '\n' << std::flush;
}

// ============================================================
// [1] 출력 조작자 클래스의 공통 기반 — 추상 클래스
//     operator<< 는 하나만 두고, 무엇을 할지는 가상 함수 apply()가 정한다.
// ============================================================
class OutManip
{
public:
    virtual ~OutManip() = default;
    virtual void apply(std::ostream& out) const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const OutManip& m)
{
    m.apply(out);
    return out;                                 // 연쇄를 위해 스트림 참조를 돌려준다
}

// ============================================================
// [2] 매개변수 없는 조작자 클래스 — 객체 하나를 만들어 두고 이름으로 쓴다
// ============================================================

// 열 구분자 " | "
class Sep : public OutManip
{
public:
    void apply(std::ostream& out) const override { out << " | "; }
};

// 서식 상태를 처음 상태로 되돌린다 (진법·정렬·표기법·채움·정밀도·폭)
class ResetFormat : public OutManip
{
public:
    void apply(std::ostream& out) const override
    {
        out.flags(std::ios_base::dec | std::ios_base::skipws);
        out.fill(' ');
        out.precision(6);
        out.width(0);
    }
};

inline const Sep sep{};
inline const ResetFormat resetfmt{};

// ============================================================
// [3] 매개변수 있는 조작자 클래스 — 생성자 인자가 곧 조작자의 매개변수
//     기본 인자를 주면 인자를 생략한 호출도 된다:  Line()  Line('=')  Line('=', 20)
// ============================================================

// 같은 문자 n개 + 줄바꿈
class Line : public OutManip
{
public:
    explicit Line(char ch = '-', int count = 40) : ch(ch), count(count) {}
    void apply(std::ostream& out) const override
    {
        for (int i = 0; i < count; ++i)
            out.put(ch);
        out.put('\n');
    }
private:
    char ch;
    int count;
};

// 사번을 0X00A1 처럼 출력하고, 바꾼 서식은 되돌린다
class HexId : public OutManip
{
public:
    explicit HexId(int id, int digits = 4) : id(id), digits(digits) {}
    void apply(std::ostream& out) const override
    {
        std::ios_base::fmtflags oldFlags = out.flags();
        char oldFill = out.fill();
        out << "0X" << std::hex << std::uppercase << std::right
            << std::setfill('0') << std::setw(digits) << id;
        out.flags(oldFlags);
        out.fill(oldFill);
    }
private:
    int id;
    int digits;
};

// 금액을 오른쪽 정렬·고정 소수점으로 출력하고, 바꾼 서식은 되돌린다
class Money : public OutManip
{
public:
    explicit Money(double value, int width = 12, int places = 2)
        : value(value), width(width), places(places) {}
    void apply(std::ostream& out) const override
    {
        std::ios_base::fmtflags oldFlags = out.flags();
        std::streamsize oldPrec = out.precision();
        out << std::right << std::fixed << std::setprecision(places)
            << std::setw(width) << value;
        out.flags(oldFlags);
        out.precision(oldPrec);
    }
private:
    double value;
    int width;
    int places;
};

// ============================================================
// [4] 매개변수 있는 입력 조작자 클래스
//     cin >> Expect(':')  — 공백을 건너뛴 뒤 다음 문자가 ':'이면 꺼내고,
//     아니면 꺼내지 않고 failbit를 켠다(>>가 숫자 대신 문자를 만났을 때와 같은 규칙).
// ============================================================
class Expect
{
public:
    explicit Expect(char ch) : ch(ch) {}
    friend std::istream& operator>>(std::istream& in, const Expect& e)
    {
        in >> std::ws;
        if (in.peek() == e.ch)
            in.get();
        else
            in.clear(in.rdstate() | std::ios_base::failbit);   // 13.8 clear(state): 인자로 준 비트를 켠다
        return in;
    }
private:
    char ch;
};
