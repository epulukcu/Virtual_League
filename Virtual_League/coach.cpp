#include "coach.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Coach* Coach::instance = 0;
int Coach::objCounter = 0;

vector<string> Coach::coachNamesData;
vector<string> Coach::coachSurnamesData;

Coach::Coach() {
    // id = ++objCounter;
}

Coach::Coach(string name, string surname, bool isRealCoach) : Employee(name, surname) {
    this->name = name;
    this->surname = surname;

    if (isRealCoach) {

        id = ++objCounter;
    }
}

Coach::~Coach() {

    // objCounter--;
}

Coach* const Coach::getInstance() {

    if (!instance) {

        instance = new Coach;
        // objCounter--;
    }

    return instance;
}

void Coach::setName(string _name) {
    _name = name;
}

string Coach::getName() const {
    return name;
}

void Coach::setSurname(string _surname) {
    _surname = surname;
}

string Coach::getSurname() const {
    return surname;
}

vector<string> const Coach::getCoachNamesData() {

    return Coach::coachNamesData;
}

vector<string> const Coach::getCoachSurnamesData() {

    return Coach::coachSurnamesData;
}

void Coach::readData(const string file_name) {

    ifstream file(file_name, ios::in);

    if (!file.good()) {

        cout << "Coach::readData: " << file_name << " not found..!" << endl;

        exit(EXIT_FAILURE);
    }

    vector<vector<string>> result;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        vector<string> tokens;

        while (getline(ss, token, ';')) {

            tokens.push_back(token);

        }

        result.push_back(tokens);
    }

    file.close();

    // cout << "Coach::readData: " << result.size() << " rows are loaded successfully from " << file_name << "." << endl;

    for (int i = 0; i < result.size(); i++) {

        string data_coach = result[i][1];

        stringstream ss(data_coach);

        string token;

        vector<string> coach;

        while (getline(ss, token, ' ')) {

            coach.push_back(token);
        }

        Coach::coachNamesData.push_back(coach[0]);
        Coach::coachSurnamesData.push_back(coach[1]);
    }
}

void Coach::readData(const string file_name_n, const string file_name_s) { }

void Coach::clearData() {

    Coach::coachNamesData.clear();
    Coach::coachSurnamesData.clear();
}

void Coach::print() const {

    cout << name << "\t" << surname << endl;

}

void Coach::printData() const {

    cout << "Coach Name" << "\t" << "Coach Surname" << endl;

    for (int i = 0; i < Coach::coachNamesData.size(); i++) {

        cout << coachNamesData[i] << " " << coachSurnamesData[i] << endl;

    }
}