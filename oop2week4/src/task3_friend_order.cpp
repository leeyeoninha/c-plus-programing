// 과제 3 (중) · 프렌드 함수/프렌드 클래스와 생성자·소멸자 호출 순서
#include <iostream>
#include <format>
#include <string>
using namespace std;

class Engine {
    friend class Car;                    // Car의 모든 멤버 함수에 접근 권한 부여
    friend void inspect(const Engine &e); // 이 함수 하나에만 접근 권한 부여
public:
    explicit Engine(int hp, const string &name);
    ~Engine();
    int getHorsePower() const { return horsePower; }
private:
    int    horsePower;
    bool   running = false;
    string label;
};

Engine::Engine(int hp, const string &name) : horsePower(hp), label(name) {
    cout << format("  [Engine 생성자] {} ({}마력)\n", label, horsePower);
}
Engine::~Engine() {
    cout << format("  [Engine 소멸자] {}\n", label);
}

// 프렌드 함수 — 멤버가 아니지만 private에 접근 가능
void inspect(const Engine &e) {
    cout << format("  점검: {} / {}마력 / 상태 {}\n",
                   e.label, e.horsePower, e.running ? "가동" : "정지");
}

class Car {
public:
    Car(const string &model, int hp);
    ~Car();
    void start();
private:
    string modelName;
    Engine engine;                       // has-a : Car는 Engine을 가진다
};

Car::Car(const string &model, int hp)
    : modelName(model), engine(hp, model + "-엔진")
{
    cout << format("[Car 생성자] {}\n", modelName);
}
Car::~Car() {
    cout << format("[Car 소멸자] {}\n", modelName);
}

void Car::start() {
    engine.running = true;               // friend class이므로 private 직접 접근
    cout << format("{} 시동 ({}마력)\n", modelName, engine.horsePower);
}

Car globalCar{"전역차", 100};             // 전역 객체

int main() {
    cout << "\nMAIN 시작\n";
    Car myCar{"세단", 250};

    cout << "\n--- 프렌드 클래스: Car가 Engine의 private 수정 ---\n";
    myCar.start();
    inspect(Engine{90, "임시엔진"});      // 임시 객체 + 프렌드 함수

    cout << "\n--- 블록 스코프 ---\n";
    {
        Car blockCar{"블록차", 130};
        blockCar.start();
    }
    cout << "블록을 벗어났습니다\n";

    static Car staticCar{"정적차", 180};  // static 지역 객체

    cout << "\nMAIN 종료\n";
    return 0;
}
