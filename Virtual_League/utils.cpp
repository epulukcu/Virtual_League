#include "utils.h"
#include "player.h"
#include "coach.h"
#include "team.h"
#include "league.h"

extern League* league;

void func_MENU_MAIN() {

	if (splash) {

		utils_print_splash_screen();

		splash = false;
	}
	cout << "---- Main Menu ---" << endl;
	cout << "1. " << "Player Menu" << endl;
	cout << "2. " << "Team Menu" << endl;
	cout << "3. " << "League Menu" << endl;

	while (true) {

		cout << "Choice (-1 for exit): ";
		cin >> choice;

		if (choice == -1) {

			exit(EXIT_SUCCESS);
		}

		if (choice >= 1 && choice <= 3) {

			MENU_FLAG = 1 << (choice + 1);
			system("cls");
			utils_print_splash_screen();
			break;
		}
		else {

			cout << "Wrong choice..!" << endl;
		}
	}
}

void func_MENU_PLAYER() {

	cout << "---- Player Menu ---" << endl;
	cout << "0. " << "Main Menu" << endl;
	cout << "1. " << "Search by name" << endl;
	cout << "2. " << "Modify Performance" << endl;

	while (true) {

		cout << "Choice: ";
		cin >> choice;

		if (choice >= 0 && choice <= 2) {

			if (choice == 0) {

				MENU_FLAG = MENU_MAIN;
				system("cls");
				utils_print_splash_screen();
				break;
			}

			MENU_FLAG = 1 << (choice + 4);
			break;
		}
		else {

			cout << "Wrong choice..!" << endl;
		}
	}
}

void func_MENU_PLAYER_SUBMENU_1() {

	playerSearchByNameDialog();

	MENU_FLAG = MENU_PLAYER;
}

void func_MENU_PLAYER_SUBMENU_2() {

	playerModifyPerformanceDialog();

	MENU_FLAG = MENU_PLAYER;
}

void func_MENU_TEAM() {

	cout << "---- Team Menu ---" << endl;
	cout << "0. " << "Main Menu" << endl;
	cout << "1. " << "Search by name" << endl;
	cout << "2. " << "Search by abbreviation" << endl;
	cout << "3. " << "Change formation" << endl;

	while (true) {

		cout << "Choice: ";
		cin >> ws >> choice;

		if (choice >= 0 && choice <= 3) {

			if (choice == 0) {

				MENU_FLAG = MENU_MAIN;
				system("cls");
				utils_print_splash_screen();

				break;
			}

			MENU_FLAG = 1 << (choice + 6);
			system("cls");
			utils_print_splash_screen();
			break;
		}
		else {

			cout << "Wrong choice..!" << endl;
		}
	}
}

void func_MENU_TEAM_SUBMENU_1() {

	teamSearchByNameDialog();

	MENU_FLAG = MENU_TEAM;
}

void func_MENU_TEAM_SUBMENU_2() {

	teamSearchByAbbreviationDialog();

	MENU_FLAG = MENU_TEAM;
}

void func_MENU_TEAM_SUBMENU_3() {

	teamSetFormationDialog();

	MENU_FLAG = MENU_TEAM;
}

void func_MENU_LEAGUE() {

	if (!isLeagueStarted) {

		cout << "---- League Menu ---" << endl;
		cout << "0. " << "Main Menu" << endl;
		cout << "2. " << "Print matches" << endl;
		cout << "3. " << "Search match by id" << endl;
		cout << "4. " << "Search by team name" << endl;
		cout << "5. " << "Make Matches" << endl;
	}

	else {

		cout << "---- League Menu ---" << endl;
		cout << "0. " << "Main Menu" << endl;
		cout << "1. " << "Print standings" << endl;
		cout << "2. " << "Print matches" << endl;
		cout << "3. " << "Search match by id" << endl;
		cout << "4. " << "Search by team name" << endl;
	}


	while (true) {

		cout << "Choice: ";
		cin >> choice;

		if (!isLeagueStarted && (choice == 0 || (choice >= 2 && choice <= 5))) {

			if (choice == 0) {

				MENU_FLAG = MENU_MAIN;
				system("cls");
				utils_print_splash_screen();
				break;
			}

			if (choice == 5) {

				cout << "Lig basladi..." << endl;

				isLeagueStarted = true;
			}

			MENU_FLAG = 1 << (choice + 9);
			system("cls");
			utils_print_splash_screen();
			break;
		}

		else if (isLeagueStarted && (choice == 0 || choice <= 4)) {

			if (choice == 0) {

				MENU_FLAG = MENU_MAIN;
				system("cls");
				utils_print_splash_screen();
				break;
			}

			MENU_FLAG = 1 << (choice + 9);
			system("cls");
			utils_print_splash_screen();
			break;
		}

		else {

			cout << "Wrong choice..!" << endl;
		}
	}
}

void func_MENU_LEAGUE_SUBMENU_1() {

	leaguePrintStandingsDialog();

	MENU_FLAG = MENU_LEAGUE;
}

void func_MENU_LEAGUE_SUBMENU_2() {

	leaguePrintMatchesDialog();

	MENU_FLAG = MENU_LEAGUE;
}

void func_MENU_LEAGUE_SUBMENU_3() {

	leagueSearchMatchByIdDialog();

	MENU_FLAG = MENU_LEAGUE;
}

void func_MENU_LEAGUE_SUBMENU_4() {

	leagueSearchMatchByNameDialog();

	MENU_FLAG = MENU_LEAGUE;
}

void func_MENU_LEAGUE_SUBMENU_5() {

	leagueMakeMatchesDialog();

	MENU_FLAG = MENU_LEAGUE;
}

void begin() {

	Coach::getInstance()->clearData();
	Player::getInstance()->clearData();
	Team::getInstance()->clearData();

	Coach::getInstance()->readData("takimlar.txt");
	Player::getInstance()->readData("isim.txt", "soyisim.txt");
	Team::getInstance()->readData("takimlar.txt");
}

void init() {

	static vector<Team> team_list;

	int k = -1;
	Player* p_p = Player::getInstance();
	Coach* c_p = Coach::getInstance();
	Team* t_p = Team::getInstance();

	int numberOfPlayerNames = p_p->getPlayerNamesData().size();
	int numberOfPlayerSurnames = p_p->getPlayerSurnamesData().size();
	int numberOfCoaches = c_p->getCoachNamesData().size();
	int numberOfTeams = t_p->getTeamNamesData().size();


	if (numberOfPlayerNames != numberOfPlayerSurnames) {

		cout << "Number of player names and player surnames not equal..!" << endl;

		exit(EXIT_FAILURE);
	}

	else if (numberOfPlayerNames != 11 * numberOfTeams) {


		cout << "numberOfPlayerNames != 11 * numberOfTeams" << endl;

		exit(EXIT_FAILURE);
	}

	else if ((numberOfTeams % 2) != 0) {

		cout << "Number of teams must be 2*n" << endl;

		exit(EXIT_FAILURE);
	}


	for (int i = 0; i < numberOfTeams; i++) {

		vector<Player> player_list;

		for (int j = 0; j < 11; j++) {

			Player p(p_p->getPlayerNamesData()[(11 * i) + j], p_p->getPlayerSurnamesData()[(11 * i) + j], true);

			player_list.push_back(p);
		}

		Coach c(c_p->getCoachNamesData()[i], c_p->getCoachSurnamesData()[i], true);
		Team t(c, player_list, F_442, true);
		t.calculatePerf();
		t.calculateDPerf();
		t.calculateMFPerf();
		t.calculateFPerf();
		t.calculateAvgAge();
		t.setTeamUniformNumbers();

		team_list.push_back(t);
	}

	static League L(team_list, true);
	L.generateFixture();
	league = &L;
}

void start() {

	while (true) {

		switch (MENU_FLAG) {

		case MENU_MAIN:

			func_MENU_MAIN();

			break;

		case MENU_PLAYER:

			func_MENU_PLAYER();

			break;

		case MENU_PLAYER_SUBMENU_1:

			func_MENU_PLAYER_SUBMENU_1();

			break;

		case MENU_PLAYER_SUBMENU_2:

			func_MENU_PLAYER_SUBMENU_2();

			break;

		case MENU_TEAM:

			func_MENU_TEAM();

			break;

		case MENU_TEAM_SUBMENU_1:

			func_MENU_TEAM_SUBMENU_1();

			break;

		case MENU_TEAM_SUBMENU_2:

			func_MENU_TEAM_SUBMENU_2();

			break;

		case MENU_TEAM_SUBMENU_3:

			func_MENU_TEAM_SUBMENU_3();
			break;

		case MENU_LEAGUE:

			func_MENU_LEAGUE();

			break;

		case MENU_LEAGUE_SUBMENU_1:

			func_MENU_LEAGUE_SUBMENU_1();

			break;

		case MENU_LEAGUE_SUBMENU_2:

			func_MENU_LEAGUE_SUBMENU_2();

			break;

		case MENU_LEAGUE_SUBMENU_3:

			func_MENU_LEAGUE_SUBMENU_3();

			break;

		case MENU_LEAGUE_SUBMENU_4:

			func_MENU_LEAGUE_SUBMENU_4();

			break;

		case MENU_LEAGUE_SUBMENU_5:

			func_MENU_LEAGUE_SUBMENU_5();

			break;

		default:
			break;
		}
	}
}


void playerSearchByNameDialog() {

	string playerName;

	cout << "Player name to search: ";
	getline(cin >> ws, playerName);
	// cin >> playerName;

	int teamId;
	Player* player = league->searchPlayerByName(playerName, teamId);

	if (player != NULL) {

		cout << playerName << " finded..." << endl;
		cout << playerName << " informations are followings: " << endl;
		player->printDetailed();

		return;
	}

	cout << playerName << " not finded..!" << endl;
}

void playerModifyPerformanceDialog() {

	string playerName;

	cout << "Player name to search: ";
	getline(cin >> ws, playerName);

	int teamId;
	Player* player = league->searchPlayerByName(playerName, teamId);

	if (player != NULL) {

		Team* team = &(league->getTeamList()[teamId]);

		cout << playerName << " finded..." << endl;
		cout << playerName << " informations are followings: " << endl;
		player->printDetailed();


		double perf_old = player->getPerformance();
		double A = (team->getTeamPerf() * (*(team->getPlayers())).size()) - perf_old;
		double B = (*(team->getPlayers())).size();
		double perf_min = round(((60 * B) - A));

		if (perf_min < 60) {
			perf_min = 60;
		}

		int max = 99;
		int min = perf_min;

		int new_perf_value;

		while (true) {

			cout << "New performance value (" << min << "," << max << "):";
			cin >> ws >> new_perf_value;

			if (new_perf_value > min && new_perf_value <= max) {

				player->setPerformance(new_perf_value);
				team->reCalculatePerf();
				player->print();
				break;
			}
			else {

				cout << "Wrong performance choice..!" << endl;
			}
		}

		return;
	}

	cout << playerName << " not finded..!" << endl;
}

void teamSearchByAbbreviationDialog() {

	string teamAbbreviation;

	cout << "Team abbreviation to search: ";
	cin >> teamAbbreviation;

	Team* team = league->searchTeamByAbbreviation(teamAbbreviation);

	if (team != NULL) {

		cout << teamAbbreviation << " finded..." << endl;
		cout << team->getName() << " informations are followings: " << endl;
		team->print();

		return;
	}

	cout << teamAbbreviation << " not finded..!" << endl;
}


void teamSearchByNameDialog() {

	string teamName;

	cout << "Team name to search: ";
	getline(cin >> ws, teamName);

	Team* team = league->searchTeamByName(teamName);

	if (team != NULL) {

		cout << teamName << " finded..." << endl;
		cout << teamName << " informations are followings: " << endl;
		team->print();

		return;
	}

	cout << teamName << " not finded..!" << endl;
}

void teamSetFormationDialog() {

	string teamName;

	cout << "Team name to search: ";
	getline(cin >> ws, teamName);

	Team* team = league->searchTeamByName(teamName);

	if (team != NULL) {

		while (true) {

			cout << teamName << " finded..." << endl;
			cout << teamName << " informations are followings: " << endl;
			team->print();

			int formation;

			cout << "New formation value" << "(0: 4-4-2, 1: 4-3-3, 2: 4-5-1, 3: 3-5-2, 4: 3-4-3): ";
			cin >> formation;

			switch (formation)
			{
			case 0:

				team->setFormation(F_442);
				team->print();

				return;

			case 1:
				team->setFormation(F_433);
				team->print();

				return;

			case 2:
				team->setFormation(F_451);
				team->print();

				return;

			case 3:
				team->setFormation(F_352);
				team->print();

				return;

			case 4:
				team->setFormation(F_343);
				team->print();

				return;

			default:
				cout << "Invalid formation information value..!" << endl;
				break;
			}

		}
	}

	cout << teamName << " not finded..!" << endl;
}

void leaguePrintStandingsDialog() {

	league->printStandings();
}

void leaguePrintMatchesDialog() {

	league->getMatchList()->print();
}

void leagueSearchMatchByIdDialog() {

	int matchId;

	cout << "Match id to search: ";
	cin >> matchId;

	SinglyNode* match = league->getMatchList()->findMatchById(matchId);

	if (match != NULL) {

		match->team_one->print();
		match->team_two->print();

		double winning_possibility_team_1 = (match->team_one->getTeamPerf() * 100) / (match->team_one->getTeamPerf() + match->team_two->getTeamPerf());
		double winning_possibility_team_2 = 100.0 - winning_possibility_team_1;

		cout << "Winning Possibilities: " << "%" << winning_possibility_team_1 << "- " << "%" << winning_possibility_team_2 << endl;

		return;
	}

	cout << matchId << " not finded..!" << endl;
}

void leagueSearchMatchByNameDialog() {

	string teamName;

	cout << "Team name to search: ";
	getline(cin >> ws, teamName);

	int a = 5;

	vector<SinglyNode> matches = league->getMatchList()->getMatchesByName(teamName);

	if (matches.size() != 0) {

		for (int i = 0; i < matches.size(); i++) {

			cout << matches[i].team_one->getName() << " (" << matches[i].team_one->getAbbreviation() << ")"
				<< " - "
				<< matches[i].team_two->getName() << " (" << matches[i].team_two->getAbbreviation() << ")" << endl;
		}

		return;
	}

	cout << teamName << " not finded..!" << endl;
}

void leagueMakeMatchesDialog() {


	League::getMatchList()->match();
}

string utils_toLower(const string& s) {

	string s_copy = s;

	for (auto& c : s_copy) {
		c = tolower(c);
	}

	return s_copy;
}

void utils_print_splash_screen() {

	cout << R"(
____   ____.__         __               .__    .____                                        
\   \ /   /|__|_______/  |_ __ _______  |  |   |    |    ____ _____     ____  __ __   ____  
 \   Y   / |  \_  __ \   __\  |  \__  \ |  |   |    |  _/ __ \\__  \   / ___\|  |  \_/ __ \ 
  \     /  |  ||  | \/|  | |  |  // __ \|  |__ |    |__\  ___/ / __ \_/ /_/  >  |  /\  ___/ 
   \___/   |__||__|   |__| |____/(____  /____/ |_______ \___  >____  /\___  /|____/  \___  >
                                      \/               \/   \/     \//_____/             \/
)" << endl;
}