#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>
#include "coach.h"
#include "player.h"
#include "employee.h"

using namespace std;

enum Formations { F_442, F_433, F_4231, F_451, F_352, F_343 };

class Team {

private:

    double avg_perf;
    double avg_age;
    double perf_D;
    double perf_MF;
    double perf_F;

    static vector<string> teamAbbrevations;
    static vector<string> teamNamesData;

    static Team* instance;
    static int objCounter;
    int id;

    string name;
    string abbreviation;
    int pts;
    int GF;
    int GA;
    int GD;
    int win;
    int draw;
    int lose;

    Coach coach;
    vector<Player> players;
    Formations formation;

    static vector<string> formation_442;
    static vector<string> formation_433;
    static vector<string> formation_451;
    static vector<string> formation_352;
    static vector<string> formation_343;

public:

    Team();
    Team(Coach coach, vector<Player> players, Formations formation = Formations::F_442, bool isRealTeam = false);
    ~Team();
    void setFormation(Formations formation);
    string getFormation();
    static Team* const getInstance();
    string generateTeamName(string& name);
    string generateAbbrevation(string& name);
    void addPlayer(Player player);
    void calculatePerf();
    void reCalculatePerf();
    void calculateDPerf();
    void calculateMFPerf();
    void calculateFPerf();
    void calculateAvgAge();
    void setTeamUniformNumbers();
    void calculateGD();
    static vector<string> const getTeamNamesData();
    string getName() const;
    string getAbbreviation() const;
    string getCoachName() const;
    string getCoachSurname() const;
    double getTeamAgeAvg() const;
    double getTeamPerf() const;
    double getDPerf() const;
    double getMFPerf() const;
    double getFPerf() const;
    int getGF() const;
    int getGA() const;
    int getGD();
    int getWin() const;
    int getDraw() const;
    int getLose() const;
    int getPoint() const;
    vector<Player>* getPlayers();



    void readData(const string file_name);
    void clearData();
    void print();
    void printData() const;


    Team& operator++();
    Team& operator++(int);
    Team& operator--();
    Team& operator--(int);
    Team& operator+=(int);
    Team& operator-=(int);
};

#endif // TEAM_H