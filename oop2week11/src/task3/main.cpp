// 실습 단계 3 ─ 표준 입력으로 아군을 구성하고, 리포트를 ostream& 로 출력한다
#include <iostream>
#include <string>
#include <vector>
#include "Unit.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"

// 출력 대상을 ostream& 로 받는다 ─ cout 말고 cerr 로도 같은 리포트가 나간다
void printReport(const std::vector<Unit*>& team, std::ostream& out) {
    for (int i = 0; i < 44; ++i) out.put('-');       // 구분선은 put 으로 한 글자씩
    out << '\n';
    for (const Unit* u : team) {
        u->print(out);                               // 가상 함수가 파생 버전을 고른다
        out << '\n';
    }
}

static Unit* firstAlive(std::vector<Unit*>& team) {
    for (Unit* u : team)
        if (u->alive()) return u;
    return nullptr;
}

static void attackPhase(std::vector<Unit*>& attackers, std::vector<Unit*>& defenders,
                        const char* label, std::ostream& out) {
    for (Unit* a : attackers) {
        if (!a->alive()) continue;
        Unit* target = firstAlive(defenders);
        if (target == nullptr) return;

        int damage = a->attack();
        target->takeDamage(damage);
        out << label << " " << a->name() << " -> " << target->name()
            << " : " << damage << " damage, " << target->name()
            << " hp " << target->hp();
        if (!target->alive()) out << " (defeated)";
        out << '\n';
    }
}

int main() {
    std::vector<Unit*> heroes;
    std::string kind;

    // 입력:  W 이름 체력 공격력 | A 이름 체력 공격력 민첩 | M 이름 체력 공격력 마나
    while (std::cin >> kind) {
        std::string name;
        int hp = 0;

        if (kind == "W") {
            int power;
            std::cin >> name >> hp >> power;
            if (hp <= 0) {
                std::cerr << "[warn] " << name << ": hp must be positive, skipped\n";
                continue;
            }
            heroes.push_back(new Warrior(name, hp, power));
        } else if (kind == "A") {
            int power, agility;
            std::cin >> name >> hp >> power >> agility;
            if (hp <= 0) {
                std::cerr << "[warn] " << name << ": hp must be positive, skipped\n";
                continue;
            }
            heroes.push_back(new Archer(name, hp, power, agility));
        } else if (kind == "M") {
            int power, mana;
            std::cin >> name >> hp >> power >> mana;
            if (hp <= 0) {
                std::cerr << "[warn] " << name << ": hp must be positive, skipped\n";
                continue;
            }
            heroes.push_back(new Mage(name, hp, power, mana));
        } else {
            std::cerr << "[error] unknown type '" << kind << "'\n";
            break;
        }
    }

    std::vector<Unit*> enemies { new Mage("Saruman", 70, 18, 20), new Warrior("Orc", 60, 9) };

    for (int round = 1; round <= 3; ++round) {
        std::cout << "--- round " << round << " ---\n";
        attackPhase(heroes, enemies, "hero", std::cout);
        attackPhase(enemies, heroes, "enemy", std::cout);
    }

    std::cout << "--- heroes ---\n";
    printReport(heroes, std::cout);
    std::cout << "--- enemies ---\n";
    printReport(enemies, std::cout);

    for (Unit* u : heroes)  delete u;
    for (Unit* u : enemies) delete u;
}
