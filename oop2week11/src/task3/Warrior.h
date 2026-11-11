#pragma once
#include "Unit.h"

class Warrior : public Unit {
public:
    Warrior(const std::string& name, int hp, int power);
    ~Warrior();

    int attack() override;
    const char* type() const override { return "Warrior"; }
    void print(std::ostream& out) const override;

private:
    int power_;
};
