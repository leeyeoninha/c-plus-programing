#include "Mage.h"

Mage::Mage(const std::string& name, int hp, int power, int mana)
    : Unit(name, hp), power_(power), mana_(mana) {}

Mage::~Mage() {
    std::cout << "[dtor] Mage(" << name() << ")" << std::endl;
}

int Mage::attack() {
    if (mana_ >= 10) {              // 마나가 있으면 두 배로 때리고 마나를 쓴다
        mana_ -= 10;
        return power_ * 2;
    }
    return power_;                  // 마나가 없으면 평타
}

void Mage::print(std::ostream& out) const {
    Unit::print(out);
    out << " power " << power_ << " mana " << mana_;
}
