// [제공 코드] 진단 6에서 사용하는 기본 프로그램 — 이 상태로 컴파일·실행하면 정상 동작합니다.
#include <iostream>
#include <string>

class Animal {
public:
    enum AnimalType { CAT, DOG, BIRD };
    Animal(AnimalType type) : type_(type) {}
    AnimalType getType() const { return type_; }
private:
    AnimalType type_;
};

class Cat : public Animal {
public:
    Cat() : Animal(CAT) {}
    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

class Dog : public Animal {
public:
    Dog() : Animal(DOG) {}
    void makeSound() const { std::cout << "Woof!" << std::endl; }
};

class Bird : public Animal {
public:
    Bird() : Animal(BIRD) {}
    void makeSound() const { std::cout << "Tweet!" << std::endl; }
};

void makeAnimalSound(const Animal& animal) {
    switch (animal.getType()) {
    case Animal::CAT:  static_cast<const Cat&>(animal).makeSound();  break;
    case Animal::DOG:  static_cast<const Dog&>(animal).makeSound();  break;
    case Animal::BIRD: static_cast<const Bird&>(animal).makeSound(); break;
    default: std::cout << "Unknown animal sound!" << std::endl;
    }
}

int main() {
    Cat cat;
    Dog dog;
    Bird bird;

    makeAnimalSound(cat);
    makeAnimalSound(dog);
    makeAnimalSound(bird);

    return 0;
}
