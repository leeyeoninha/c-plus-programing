#pragma once
#include "Unit.h"

class Archer : public Unit {
public:
    Archer(const std::string& name, int hp, int power, int agility);
    ~Archer();

    int attack() override;
    const char* type() const override { return "Archer"; }
    void print(std::ostream& out) const override;

private:
    int power_;
    int agility_;
};
