#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

using namespace std;

class Player : public Employee {

private:

    static vector<string> playerNamesData;
    static vector<string> playerSurnamesData;
    static vector<bool> bitmapPlayerNames;
    static vector<bool> bitmapPlayerSurnames;
    static vector<bool> bitmapUniformNumbers;

    static Player* instance;
    static int objCounter;
    int id;

    int uniform_number;
    int performance;
    string position;

    string generateRandomName(string _name);
    string generateRandomSurname(string _surname);

public:
    Player();
    Player(string name, string surname, bool isRealPlayer = false);
    ~Player();

    static Player* const getInstance();

    void setName(string _name);
    string getName() const;

    void setSurname(string _surname);
    string getSurname() const;

    void setAge(int _age);
    int getAge() const;

    void setUniformNumber(int _uniform_number);
    int getUniformNumber() const;

    void setPosition(string _position);
    string getPosition() const;

    void setPerformance(int _performance);
    int getPerformance() const;

    static vector<string> const getPlayerNamesData();
    static vector<string> const getPlayerSurnamesData();

    int generateAge();

    int generateAveragePerformance();


    void readData(const string file_name);
    void readData(const string file_name_n, const string file_name_s);
    void clearData();
    void print() const;
    void printDetailed() const;
    void printData() const;
};

#endif // PLAYER_H