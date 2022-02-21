#ifndef COACH_H
#define COACH_H

#include "employee.h"

#include <string>

using namespace std;

class Coach : public Employee {

private:
    static Coach* instance;
    static int objCounter;
    int id;

    static vector<string> coachNamesData;
    static vector<string> coachSurnamesData;

public:
    Coach();
    Coach(string name, string surname, bool isRealCoach = false);
    ~Coach();

    static Coach* const getInstance();

    void setName(string _name);
    string getName() const;

    void setSurname(string _surname);
    string getSurname() const;

    vector<string> const getCoachNamesData();
    vector<string> const getCoachSurnamesData();

    void readData(const string file_name);
    void readData(const string file_name_n, const string file_name_s);
    void clearData();
    void print() const;
    void printData() const;
};

#endif // COACH_H