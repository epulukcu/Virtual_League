#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Employee {

protected:
    string name;
    string surname;
    int age;

public:
    Employee();
    Employee(string name, string surname);
    Employee(string name, string surname, int age);
    ~Employee();

    virtual void readData(const string file_name) = 0;
    virtual void readData(const string file_name_n, const string file_name_s) = 0;
    virtual void clearData() = 0;
    virtual void print() const = 0;
    virtual void printData() const = 0;
};

#endif // EMPLOYEE_H