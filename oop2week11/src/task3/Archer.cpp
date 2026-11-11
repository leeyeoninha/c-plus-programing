#include "Archer.h"

Archer::Archer(const std::string& name, int hp, int power, int agility)
    : Unit(name, hp), power_(power), agility_(agility) {}

Archer::~Archer() {
    std::cout << "[dtor] Archer(" << name() << ")" << std::endl;
}

int Archer::attack() { return power_ + agility_ / 2; }

void Archer::print(std::ostream& out) const {
    Unit::print(out);
    out << " power " << power_ << " agility " << agility_;
}
