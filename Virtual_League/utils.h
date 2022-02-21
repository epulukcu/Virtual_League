#ifndef UTILS_H
#define UTILS_H

#include "team.h"
#include "league.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const static int MENU_MAIN = (1 << 1);				// 2
const static int MENU_PLAYER = (1 << 2);            // 4
const static int MENU_TEAM = (1 << 3);              // 8
const static int MENU_LEAGUE = (1 << 4);            // 16
const static int MENU_PLAYER_SUBMENU_1 = (1 << 5);  // 32
const static int MENU_PLAYER_SUBMENU_2 = (1 << 6);  // 64
const static int MENU_TEAM_SUBMENU_1 = (1 << 7);    // 128
const static int MENU_TEAM_SUBMENU_2 = (1 << 8);    // 256
const static int MENU_TEAM_SUBMENU_3 = (1 << 9);    // 512
const static int MENU_LEAGUE_SUBMENU_1 = (1 << 10); // 1024
const static int MENU_LEAGUE_SUBMENU_2 = (1 << 11); // 2048
const static int MENU_LEAGUE_SUBMENU_3 = (1 << 12); // 4096
const static int MENU_LEAGUE_SUBMENU_4 = (1 << 13); // 8192
const static int MENU_LEAGUE_SUBMENU_5 = (1 << 14);
static int MENU_FLAG = MENU_MAIN;

static bool splash = true;
static int choice;

static bool isLeagueStarted = false;

void func_MENU_MAIN();
void func_MENU_PLAYER();
void func_MENU_PLAYER_SUBMENU_1();
void func_MENU_PLAYER_SUBMENU_1();
void func_MENU_TEAM();
void func_MENU_TEAM_SUBMENU_1();
void func_MENU_TEAM_SUBMENU_2();
void func_MENU_TEAM_SUBMENU_3();
void func_MENU_LEAGUE();
void func_MENU_LEAGUE_SUBMENU_1();
void func_MENU_LEAGUE_SUBMENU_2();
void func_MENU_LEAGUE_SUBMENU_3();
void func_MENU_LEAGUE_SUBMENU_4();
void func_MENU_LEAGUE_SUBMENU_5();

static League* league;

void begin();
void init();
void start();

void playerSearchByNameDialog();
void playerModifyPerformanceDialog();

void teamSearchByAbbreviationDialog();
void teamSearchByNameDialog();
void teamSetFormationDialog();

void leaguePrintStandingsDialog();
void leaguePrintMatchesDialog();
void leagueSearchMatchByIdDialog();
void leagueSearchMatchByNameDialog();
void leagueMakeMatchesDialog();

string utils_toLower(const string& s);

void utils_print_splash_screen();

#endif // UTILS_H