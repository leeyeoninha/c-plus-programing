// 실습 1 [하] ─ 설계 카드를 채우고 추상 기반 Unit 과 파생 두 개를 만든다
#include <iostream>
#include <vector>
#include "Unit.h"
#include "Warrior.h"
#include "Archer.h"

int main() {
    // (1) 추상 클래스는 객체를 만들 수 없다 ─ 아래 줄의 주석을 풀어 확인한다
    // Unit u("Nobody", 10);

    std::vector<Unit*> team;
    team.push_back(new Warrior("Conan", 100, 12));
    team.push_back(new Archer("Legolas", 80, 11, 6));

    for (Unit* u : team) {
        u->print(std::cout);                    // 파생마다 다른 print
        std::cout << " -> attack " << u->attack() << std::endl;   // 파생마다 다른 attack
    }

    for (Unit* u : team) delete u;
}
