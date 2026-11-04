// 과제2 [중] — 도형 계층 설계 (모범답안, Linux 검증용: #pragma comment 는 주석)
#include <iostream>
#include <iomanip>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::string name() const { return "도형"; }
    virtual double area() const { return 0.0; }
    virtual void print() const {
        std::cout << name() << ": " << std::fixed << std::setprecision(2) << area() << std::endl;
    }
};

class Circle : public Shape {
public:
    Circle(double r) : r_(r) {}
    std::string name() const { return "원"; }
    double area() const { return 3.14159 * r_ * r_; }
private:
    double r_;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : w_(w), h_(h) {}
    std::string name() const { return "직사각형"; }
    double area() const { return w_ * h_; }
private:
    double w_, h_;
};

class Triangle : public Shape {
public:
    Triangle(double base, double height) : base_(base), height_(height) {}
    std::string name() const { return "삼각형"; }
    double area() const { return base_ * height_ / 2.0; }
private:
    double base_, height_;
};

int main() {
    Circle circle(3.0);
    Rectangle rect(4.0, 5.0);
    Triangle tri(6.0, 2.0);

    Shape* shapes[3] = { &circle, &rect, &tri };

    double total = 0.0;
    const Shape* widest = shapes[0];
    for (int i = 0; i < 3; ++i) {
        shapes[i]->print();
        total += shapes[i]->area();
        if (shapes[i]->area() > widest->area()) {
            widest = shapes[i];
        }
    }
    std::cout << "총 면적: " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << "가장 넓은 도형: " << widest->name() << std::endl;

    return 0;
}
