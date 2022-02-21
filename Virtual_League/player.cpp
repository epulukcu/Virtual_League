#include "player.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

Player* Player::instance = 0;
int Player::objCounter = 0;

vector<string> Player::playerNamesData;
vector<string> Player::playerSurnamesData;
vector<bool> Player::bitmapPlayerNames;
vector<bool> Player::bitmapPlayerSurnames;
vector<bool> Player::bitmapUniformNumbers;

Player::Player()
{
    //id = ++objCounter;
}

Player::Player(string name, string surname, bool isRealPlayer) : Employee(name, surname)
{
    if (isRealPlayer) {

        id = ++objCounter;
    }

    this->name = generateRandomName(name);
    this->surname = generateRandomSurname(surname);
    this->age = generateAge();
}

Player::~Player() {
    // objCounter--;
}

Player* const Player::getInstance() {

    if (!instance) {

        instance = new Player;
        // objCounter--;
    }

    return instance;
}

void Player::setName(string _name) {
    name = _name;
}

string Player::getName() const {
    return name;
}

void Player::setSurname(string _surname) {
    surname = _surname;
}

string Player::getSurname() const {
    return surname;
}

void Player::setAge(int _age) {
    age = _age;
}

int Player::getAge() const {
    return age;
}

void Player::setUniformNumber(int _uniform_number) {
    uniform_number = _uniform_number;
}

int Player::getUniformNumber() const {
    return uniform_number;
}

void Player::setPosition(string _position) {
    position = _position;
}

string Player::getPosition() const {
    return position;
}

void Player::setPerformance(int _performance) {
    performance = _performance;
}

int Player::getPerformance() const {
    return performance;
}

vector<string> const Player::getPlayerNamesData() {

    return playerNamesData;

}

vector<string> const Player::getPlayerSurnamesData() {

    return playerSurnamesData;

}

string Player::generateRandomName(string _name) {
    bool isNameFinded = false;

    while (!isNameFinded) {
        int number1 = rand() % playerNamesData.size();
        if (bitmapPlayerNames[number1] == false) {
            bitmapPlayerNames[number1] = true;
            _name = playerNamesData[number1];
            isNameFinded = true;
        }
    }
    return _name;
}

string Player::generateRandomSurname(string _surname) {
    bool isSurnameFinded = false;

    while (!isSurnameFinded) {
        int number2 = rand() % playerSurnamesData.size();
        if (bitmapPlayerSurnames[number2] == false) {
            bitmapPlayerSurnames[number2] = true;
            _surname = playerSurnamesData[number2];
            isSurnameFinded = true;
        }
    }
    return _surname;
}


int Player::generateAge() {
    // srand((unsigned) time(NULL));
    while (true) {
        age = rand() % 36;
        if (age > 18 && age < 36) {
            break;
        }
        else
            continue;
    }
    return age;
}


int Player::generateAveragePerformance() {
    // srand((unsigned) time(NULL));
    while (true) {
        performance = rand() % 100;
        if (performance > 30 && performance < 100) {
            break;
        }
        else
            continue;;
    }

    return performance;
}


void Player::readData(const string file_name) { }

void Player::readData(const string file_name_n, const string file_name_s) {

    ifstream file(file_name_n, ios::in);

    if (!file.good()) {

        cout << "Player::readData: " << file_name_n << " not found..!" << endl;

        exit(EXIT_FAILURE);
    }

    string line;

    while (getline(file, line)) {

        Player::playerNamesData.push_back(line);
        Player::bitmapPlayerNames.push_back(false);
    }

    file.close();

    // cout << "Player::readData: " << Player::playerNamesData.size() << " rows are loaded successfully from " << file_name_n << "." << endl;


    file.open(file_name_s, ios::in);

    if (!file.good()) {

        cout << "Player::readData: " << file_name_s << " not found..!" << endl;

        exit(EXIT_FAILURE);
    }

    while (getline(file, line)) {

        Player::playerSurnamesData.push_back(line);
        Player::bitmapPlayerSurnames.push_back(false);
    }

    file.close();

    // cout << "Player::readData: " << Player::playerSurnamesData.size() << " rows are loaded successfully from " << file_name_s << "." << endl;
    // objCounter--;
}

void Player::clearData() {

    Player::playerNamesData.clear();
    Player::playerSurnamesData.clear();

    Player::bitmapPlayerNames.clear();
    Player::bitmapPlayerSurnames.clear();
}

void Player::print() const {

    cout << std::setfill(' ') << setw(15) << left << name << " "
        << std::setfill(' ') << setw(15) << left << surname << " "
        << std::setfill(' ') << setw(8) << left << age << " "
        << std::setfill(' ') << setw(8) << left << uniform_number << " "
        << std::setfill(' ') << setw(8) << left << performance << " "
        << std::setfill(' ') << setw(8) << left << position << endl;
}

void Player::printDetailed() const {

    cout << setfill(' ') << setw(15) << left << "Name" << " "
        << setfill(' ') << setw(15) << left << "Surname" << " "
        << setfill(' ') << setw(8) << left << "Age" << " "
        << setfill(' ') << setw(8) << left << "Kit" << " "
        << setfill(' ') << setw(8) << left << "Avg." << " "
        << setfill(' ') << setw(8) << left << "Pos" << endl;

    cout << "----" << "            " << "-------" << "         " << "---" << "      " << "---" << "      " << "---" << "      " << "---" << endl;

    print();
}

void Player::printData() const {

    cout << "Player Name" << "    " << "Player Surname" << endl;

    for (int i = 0; i < Player::playerNamesData.size(); i++) {

        cout << playerNamesData[i] << "    " << playerSurnamesData[i] << endl;

    }
}