#pragma once
#include <string>
#include <iostream>

class Unit {
public:
    Unit(const std::string& name, int hp);
    virtual ~Unit();

    const std::string& name() const;
    int hp() const;
    bool alive() const;
    void takeDamage(int damage);

    virtual int attack() = 0;                     // 순수 가상 ─ 유닛마다 계산이 다르다
    virtual const char* type() const = 0;         // 순수 가상 ─ 이름 표시용
    virtual void print(std::ostream& out) const;  // 가상 ─ 공통 형식은 기반이 맡는다

private:
    std::string name_;
    int hp_;
    int maxHp_;
};
