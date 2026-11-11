#pragma once
#include "Unit.h"

class Mage : public Unit {
public:
    Mage(const std::string& name, int hp, int power, int mana);
    ~Mage();

    int attack() override;
    const char* type() const override { return "Mage"; }
    void print(std::ostream& out) const override;

private:
    int power_;
    int mana_;
};
