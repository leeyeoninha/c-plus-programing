#pragma once
#include <string>

class Employee {
public:
    Employee(const std::string& name);
    virtual ~Employee();

    const std::string& getName() const;

    virtual double earnings() const;
    virtual void print() const;

private:
    std::string name_;
};
