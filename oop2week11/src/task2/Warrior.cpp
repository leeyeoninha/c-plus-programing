#include "Warrior.h"

Warrior::Warrior(const std::string& name, int hp, int power)
    : Unit(name, hp), power_(power) {}

Warrior::~Warrior() {
    std::cout << "[dtor] Warrior(" << name() << ")" << std::endl;
}

int Warrior::attack() { return power_; }        // 공격력이 그대로 피해

void Warrior::print(std::ostream& out) const {
    Unit::print(out);                           // 공통 부분은 기반에 맡긴다
    out << " power " << power_;
}
