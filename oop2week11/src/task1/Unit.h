// 단계 1 시작 파일 ─ 멤버 구성만 정해 두었다.
// virtual, = 0, 소멸자 처리는 직접 결정해 이 파일에 채워 넣는다.
#pragma once
#include <iostream>
#include <string>

class Unit {
public:
    Unit(const std::string& name, int hp);
    ~Unit();

    const std::string& name() const;
    int hp() const;
    bool alive() const;
    void takeDamage(int damage);          // 체력은 0 아래로 내려가지 않는다

    int attack();
    const char* type() const;
    void print(std::ostream& out) const;

private:
    std::string name_;
    int hp_;
    int maxHp_;
};
