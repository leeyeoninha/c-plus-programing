// [제공 코드] 진단 1~5에서 사용하는 기본 프로그램 — 이 상태로 컴파일·실행하면 정상 동작합니다.
#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string& name) : name_(name) {}
    virtual ~Animal() {
        std::cout << "[소멸] Animal(" << name_ << ")" << std::endl;
    }
    virtual void makeSound() const {
        std::cout << "Some sound" << std::endl;
    }
    const std::string& getName() const { return name_; }
private:
    std::string name_;
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name), ball_(new int[10]) {}
    ~Dog() {
        std::cout << "[소멸] Dog(" << getName() << ")" << std::endl;
        delete[] ball_;
    }
    void makeSound() const { std::cout << "Woof!" << std::endl; }
    void fetch() const { std::cout << "공을 물어 옵니다." << std::endl; }
private:
    int* ball_;
};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
    ~Cat() {
        std::cout << "[소멸] Cat(" << getName() << ")" << std::endl;
    }
    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

void makeAnimalSound(const Animal& animal) {
    animal.makeSound();
}

int main() {
    Dog dog("바둑이");
    Cat cat("나비");

    Animal* p = &dog;
    p->makeSound();

    makeAnimalSound(cat);

    Animal* q = new Dog("순돌이");
    delete q;

    return 0;
}
