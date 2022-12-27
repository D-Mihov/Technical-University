#pragma once
#include <vector>
#include "Team.h"
class League
{
	char name[20];
	std::vector<Team> teams;
	Team winner;

public:
	League();
	~League();
	League(char* name);
	void addTeam(Team& team);
	void removeTeam(Team& team);
	void dropDelegatedTeams();
	void sortTeamsByPoints();
	void displayRanking();
	friend void play(League& league);
	char* getName();
	void setName(char* leagueName);
	void setTeams(std::vector<Team>& teams);
	std::vector<Team> getTeams();
};

