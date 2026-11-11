// main.cpp ─ 예시 전투 루프. 그대로 써도 되고, 바꾸고 싶으면 바꿔도 된다.
#include <iostream>
#include <vector>
#include "Unit.h"                               // 직접 만든 유닛 클래스 헤더
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"

// 살아 있는 첫 유닛을 돌려준다. 없으면 nullptr
static Unit* firstAlive(std::vector<Unit*>& team) {
    for (Unit* u : team)
        if (u->alive()) return u;
    return nullptr;
}

// attackers의 살아 있는 유닛이 차례로 defenders의 살아 있는 첫 유닛을 공격한다
static void attackPhase(std::vector<Unit*>& attackers, std::vector<Unit*>& defenders,
                        const char* label, std::ostream& out) {
    for (Unit* a : attackers) {
        if (!a->alive()) continue;
        Unit* target = firstAlive(defenders);
        if (target == nullptr) return;

        int damage = a->attack();               // 가상 함수 ─ 유닛마다 다른 계산
        target->takeDamage(damage);
        out << label << " " << a->name() << " -> " << target->name()
            << " : " << damage << " damage, " << target->name()
            << " hp " << target->hp();
        if (!target->alive()) out << " (defeated)";
        out << '\n';
    }
}

int main() {
    std::vector<Unit*> heroes  { new Warrior("Conan", 100, 12), new Archer("Legolas", 80, 11, 6) };
    std::vector<Unit*> enemies { new Mage("Saruman", 70, 18, 20), new Warrior("Orc", 60, 9) };

    for (int round = 1; round <= 3; ++round) {  // 한 라운드 = 아군 전원 공격 → 적군 전원 공격
        std::cout << "--- round " << round << " ---\n";
        attackPhase(heroes, enemies, "hero", std::cout);
        attackPhase(enemies, heroes, "enemy", std::cout);
    }

    std::cout << "--- result ---\n";
    for (Unit* u : heroes)  { u->print(std::cout); std::cout << '\n'; }
    for (Unit* u : enemies) { u->print(std::cout); std::cout << '\n'; }

    for (Unit* u : heroes)  delete u;
    for (Unit* u : enemies) delete u;
}
