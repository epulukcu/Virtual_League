#ifndef LEAGUE_H
#define LEAGUE_H

#include <iostream>
#include <vector>
#include <string>
#include "team.h"

struct SinglyNode {

	int match_ID;
	Team* team_one;
	Team* team_two;

	SinglyNode* next;
};

struct SinglyLinkedList {

	SinglyNode* head = NULL;

	void addBack(int match_ID, Team* team_one, Team* team_two) {
		SinglyNode* v = new SinglyNode;
		v->match_ID = match_ID;
		v->team_one = team_one;
		v->team_two = team_two;
		v->next = NULL;

		if (head == NULL)
			head = v;
		else
		{
			SinglyNode* first = head;
			while (first->next != NULL) first = first->next;
			first->next = v;
		}
	}

	void print() {

		SinglyNode* first = head;
		while (first != NULL)
		{
			for (int i = 0; i < Team::getTeamNamesData().size() - 1; i++) {
				cout << "--------------------" << i + 1 << ". Week Fixture" << "--------------------" << endl;
				for (int j = 0; j < Team::getTeamNamesData().size() / 2; j++) {
					cout << first->match_ID << " " << first->team_one->getName() << " - " << first->team_two->getName() << endl;
					first = first->next;
				}
				cout << endl;
			}
		}
	}

	void makeMatch(Team* team_one, Team* team_two);

	void match() {

		SinglyNode* first = head;
		while (first != NULL)
		{
			makeMatch(first->team_one, first->team_two);
			first = first->next;
		}
	}

	SinglyNode* findMatchById(int matchId) {

		SinglyNode* first = head;
		while (first != NULL)
		{

			first = first->next;

			if (first->match_ID == matchId) {

				return first;
			}
		}

		return NULL;
	}

	vector<SinglyNode> getMatchesByName(string teamname) {

		vector<SinglyNode> matches;
		SinglyNode* first = head;
		while (first != NULL)
		{

			string teamname_finded_1 = first->team_one->getName();
			string teamname_finded_2 = first->team_two->getName();

			if ((teamname_finded_1.compare(teamname) == 0) || (teamname_finded_2.compare(teamname) == 0)) {

				matches.push_back(*first);
			}

			first = first->next;
		}

		return matches;
	}
};

class League {

private:
	//int number_of_coachs;
	//int number_of_players;
	//int number_of_teams;

	vector<Team>& teamList;
	static SinglyLinkedList matchList;

public:
	League(vector<Team>& team_list, bool isRealLeague = false);
	~League();

	vector<Team>& getTeamList();
	void generateFixture();
	//void makeMatch(Team& team_one, Team& team_two);
	void printStandings();

	Player* searchPlayerByName(string& player_name, int& teamId);

	Team* searchTeamByAbbreviation(string& team_abbreviation);
	Team* searchTeamByName(string& team_name);

	static SinglyLinkedList* getMatchList();
};

#endif // LEAGUE_H