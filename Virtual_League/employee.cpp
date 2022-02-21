#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

Employee::Employee() {
}

Employee::Employee(string name, string surname) {
    this->name = name;
    this->surname = surname;
}

Employee::Employee(string name, string surname, int age) {
    this->name = name;
    this->surname = surname;
    this->age = age;
}

Employee::~Employee() { }