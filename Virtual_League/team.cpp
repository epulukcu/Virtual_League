#include "team.h"
#include "coach.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

Team* Team::instance = 0;
int Team::objCounter = 0;


vector<string> Team::teamNamesData;
vector<string> Team::teamAbbrevations;
vector<string> Team::formation_442 = { "GK", "D", "D", "D", "D", "MF", "MF", "MF", "MF", "F", "F" };
vector<string> Team::formation_433 = { "GK", "D", "D", "D", "D", "MF", "MF", "MF", "F", "F", "F" };
vector<string> Team::formation_451 = { "GK", "D", "D", "D", "D", "MF", "MF", "MF", "MF", "MF", "F" };
vector<string> Team::formation_352 = { "GK", "D", "D", "D", "MF", "MF", "MF", "MF", "MF", "F", "F" };
vector<string> Team::formation_343 = { "GK", "D", "D", "D", "MF", "MF", "MF", "MF", "F", "F", "F" };


Team::Team() {

    // id = ++objCounter;
    //cout << "Constructor calisti" << " " << "ObjCounter: " << objCounter << endl;
}

Team::Team(Coach coach, vector<Player> players, Formations formation, bool isRealTeam) {

    this->name = generateTeamName(name);
    this->abbreviation = generateAbbrevation(name);
    this->coach = coach;
    this->players = players;
    setFormation(formation);
    //this->average_perf = calculatePerf();

    if (isRealTeam) {

        id = ++objCounter;
    }
}

Team::~Team() {

    // objCounter--;
    //cout << "Destrcutor calisti" << " " << "ObjCounter: " << objCounter << endl;
}

void Team::setFormation(Formations formation) {

    this->formation = formation;

    switch (formation)
    {
    case F_442:

        for (int i = 0; i < players.size(); i++) {
            players[i].setPosition(formation_442[i]);
        }
        break;

    case F_433:

        for (int i = 0; i < players.size(); i++) {
            players[i].setPosition(formation_433[i]);
        }
        break;

    case F_451:

        for (int i = 0; i < players.size(); i++) {
            players[i].setPosition(formation_451[i]);
        }
        break;

    case F_352:

        for (int i = 0; i < players.size(); i++) {
            players[i].setPosition(formation_352[i]);
        }
        break;

    case F_343:

        for (int i = 0; i < players.size(); i++) {
            players[i].setPosition(formation_343[i]);
        }
        break;

    default:
        cout << "Team::setFormation: Invalid formation information..!" << endl;
        exit(EXIT_FAILURE);
        break;
    }
}

string Team::getFormation() {

    switch (formation) {

    case F_442:

        return "4-4-2";

    case F_433:

        return "4-3-3";

    case F_451:

        return "4-5-1";

    case F_352:

        return "3-5-2";

    case F_343:

        return "3-4-3";

    default:
        cout << "Team::setFormation: Invalid formation information..!" << endl;
        exit(EXIT_FAILURE);
    }
}

Team* const Team::getInstance() {

    if (!instance) {

        instance = new Team;
        // objCounter--;
    }

    return instance;
}

string Team::generateTeamName(string& name) {

    name = teamNamesData[objCounter];

    return name;
}

string Team::generateAbbrevation(string& name) {

    bool isUnique = true;
    string a = name.substr(0, 2);

    for (int i = 0; i < teamAbbrevations.size(); i++) {
        if (teamAbbrevations[i].compare(a) == 0) {
            isUnique = false;
        }
    }
    if (isUnique) {
        teamAbbrevations.push_back(a);
    }
    else {
        a = name.substr(0, 3);
        teamAbbrevations.push_back(a);
    }

    return a;
}

void Team::addPlayer(Player player) {

    if (players.size() < 11) {
        players.push_back(player);
    }

    else {
        cout << "Team::addPlayer: " << "Exceeded maximum allowed players number..!" << endl;
    }

}

void Team::calculatePerf() {

    // avg = (A - r_min) / (i + 1);
    // A = (avg_perf * i)
    // B = i + 1
    // r_min = 60B - A;

    int r_min;
    double A;
    double B;

    for (int i = 0; i < players.size(); i++) {

        if (i == 0) {
            players[i].setPerformance(100);
            avg_perf = 100;
            continue;
        }

        A = avg_perf * i;
        B = i + 1;
        r_min = round(((60 * B) - A));

        if (r_min < 60) {
            r_min = 60;
        }

        int max = 99;
        int min = r_min + 1;

        int random = (rand() % (max - (min + 1)) + min);
        players[i].setPerformance(random);

        avg_perf = (A + random) / B;
    }
}

void Team::reCalculatePerf() {

    double perf_sum = 0;

    for (int i = 0; i < players.size(); i++) {

        perf_sum += players[i].getPerformance();
    }

    avg_perf = perf_sum / players.size();
}

void Team::calculateDPerf() {

    int i = 0;

    for (int j = 0; j < players.size(); j++) {

        if (players[j].getPosition() == "D") {

            perf_D += players[j].getPerformance();
            i++;
        }
    }

    perf_D /= i;
}

void Team::calculateMFPerf() {

    int i = 0;

    for (int j = 0; j < players.size(); j++) {

        if (players[j].getPosition() == "MF") {

            perf_MF += players[j].getPerformance();
            i++;
        }
    }

    perf_MF /= i;
}

void Team::calculateFPerf() {

    int i = 0;

    for (int j = 0; j < players.size(); j++) {

        if (players[j].getPosition() == "F") {

            perf_F += players[j].getPerformance();
            i++;
        }
    }

    perf_F /= i;
}

void Team::calculateAvgAge() {
    // avg = (A - r_min) / (i + 1);
    // A = (avg_age * i)
    // B = i + 1
    // r_min = B - A;

    int r_min;
    double A;
    double B;

    for (int i = 0; i < players.size(); i++) {

        if (i == 0) {
            players[i].setAge(32);
            avg_age = 32;
            continue;
        }

        A = avg_age * i;
        B = i + 1;
        r_min = round(((25 * B) - A));

        if (r_min < 25) {
            r_min = 25;
        }

        int max = 31;
        int min = r_min + 1;

        int random = (rand() % (max - (min + 1)) + min);
        players[i].setAge(random);

        avg_age = (A + random) / B;
    }
}

void Team::calculateGD() {
    GD = GF - GA;
}

vector<string> const Team::getTeamNamesData() {

    return teamNamesData;
}

string Team::getName() const {
    return name;
}

string Team::getAbbreviation() const {

    return abbreviation;
}

string Team::getCoachName() const {

    return coach.getName();
}

string Team::getCoachSurname() const {

    return coach.getSurname();
}

double Team::getTeamAgeAvg() const {
    return avg_age;
}

double Team::getTeamPerf() const {
    return avg_perf;
}

double Team::getDPerf() const {
    return perf_D;
}

double Team::getMFPerf() const {
    return perf_MF;
}

double Team::getFPerf() const {
    return perf_F;
}

int Team::getGF() const {
    return GF;
}

int Team::getGA() const {
    return GA;
}

int Team::getGD() {
    calculateGD();
    return GD;
}

int Team::getWin() const {
    return win;
}

int Team::getDraw() const {
    return draw;
}

int Team::getLose() const {
    return lose;
}

int Team::getPoint() const {
    return pts;
}

vector<Player>* Team::getPlayers() {

    return &players;
}

void Team::setTeamUniformNumbers() {

    srand((unsigned)time(NULL));

    vector<bool> bitmapUniformNumber;

    for (int i = 0; i < 99; i++) {
        bitmapUniformNumber.push_back(false);
    }

    for (int i = 0; i < players.size(); i++) {
        bool isNumberFinded = false;

        while (!isNumberFinded) {
            int number = (rand() % 99) + 1;
            if (bitmapUniformNumber[number] == false) {
                bitmapUniformNumber[number] = true;
                players[i].setUniformNumber(number);
                isNumberFinded = true;
            }
        }
    }
}


void Team::readData(const string file_name) {

    ifstream file(file_name, ios::in);

    if (!file.good()) {

        cout << "Team::readData: " << file_name << " not found..!" << endl;

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

    // cout << "Team::readData: " << result.size() << " rows are loaded successfully from " << file_name << "." << endl;

    for (int i = 0; i < result.size(); i++) {

        string data_team = result[i][0];

        Team::teamNamesData.push_back(data_team);
    }
}

void Team::clearData() {

    teamNamesData.clear();
    teamAbbrevations.clear();
}

void Team::print() {

    cout << "**********" << name << " " << "(" << abbreviation << ")" << " " << "Coach: " << coach.getName() << " " << coach.getSurname() << "**********" << endl;
    cout << "Formation: " << getFormation() << " " << "Average Perf: " << fixed << setprecision(2) << avg_perf << " " << "Average Age: " << avg_age << " " <<
        "Average D: " << perf_D << " " << "Average MF: " << perf_MF << " " << "Average F: " << perf_F << endl
        << "GF: " << GF << " " << "GA: " << GA << " " << "GD: " << getGD() << endl;

    cout << setfill(' ') << setw(15) << left << "Name" << " "
        << setfill(' ') << setw(15) << left << "Surname" << " "
        << setfill(' ') << setw(8) << left << "Age" << " "
        << setfill(' ') << setw(8) << left << "Kit" << " "
        << setfill(' ') << setw(8) << left << "Avg." << " "
        << setfill(' ') << setw(8) << left << "Pos" << endl;

    cout << "----" << "            " << "-------" << "         " << "---" << "      " << "---" << "      " << "---" << "      " << "---" << endl;

    for (int i = 0; i < players.size(); i++) {

        players[i].print();
    }
}

void Team::printData() const {

    cout << "Team Name" << endl;

    for (int i = 0; i < Team::teamNamesData.size(); i++) {
        cout << teamNamesData[i] << endl;
    }
}

Team& Team::operator++() {

    win++;
    pts += 3;

    return *this;
}

Team& Team::operator++(int) {

    draw++;
    pts += 1;

    return *this;
}

Team& Team::operator--() {

    lose++;

    return *this;
}

Team& Team::operator--(int) {

    lose++;

    return *this;
}

Team& Team::operator+=(int gf) {

    GF += gf;

    return *this;
}

Team& Team::operator-=(int ga) {

    GA += ga;

    return *this;
}