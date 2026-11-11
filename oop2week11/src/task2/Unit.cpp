#include "Unit.h"

Unit::Unit(const std::string& name, int hp)
    : name_(name), hp_(hp), maxHp_(hp) {}

Unit::~Unit() {
    std::cout << "[dtor] Unit(" << name_ << ")" << std::endl;
}

const std::string& Unit::name() const { return name_; }
int Unit::hp() const { return hp_; }
bool Unit::alive() const { return hp_ > 0; }

void Unit::takeDamage(int damage) {
    hp_ -= damage;
    if (hp_ < 0) hp_ = 0;
}

void Unit::print(std::ostream& out) const {
    out << type() << " " << name_ << " (hp " << hp_ << "/" << maxHp_ << ")";
}
