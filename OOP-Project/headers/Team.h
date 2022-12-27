#pragma once
#include <vector>
#include "Player.h"
class Team
{
	char teamName[20];
	std::vector<Player> players;
	int wins;
	int draws;
	int loses;
	int points;
public:
	Team();
	Team(char* teamName);
	~Team();
	void transferPlayer(char* playerName, Team& teamToTransfer);
	void addPlayer(Player& player);
	void removePlayer(Player& player);
	friend void playGame(Team& team1, Team& team2);
	char* getTeamName();
	std::vector<Player> getPlayers();
	int getWins();
	int getDraws();
	int getLoses();
	int getPoints();
	void setTeamName(char* teamName);
	void setWins(int wins);
	void setDraws(int draws);
	void setLoses(int loses);
	void setPoints(int points);
	bool Team::operator==(Team& team);
};

/*bool operator==(Team& team1, Team& team2)
{
	if (strcmp(team1.getTeamName(), team2.getTeamName()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/
