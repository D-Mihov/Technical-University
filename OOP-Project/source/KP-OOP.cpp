// KP-OOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "League.h"
#include "Player.h"
#include "Team.h"
#include <cstdlib>
#include <ctime>

void seedPlayers(std::vector<Player>& players, std::ifstream& playersInput);
void seedTeams(std::vector<Team>& teams, std::ifstream& teamsInput, std::vector<Player>& players);
void playGame(Team& team1, Team& team2);
void play(League& league);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	std::ifstream playersInput("players.txt");
	std::ifstream teamsInput("teams.txt");
	if (!playersInput.is_open())
	{
		std::cout << "Couldn't open players.txt" << std::endl;
		return 2;
	}
	if (!teamsInput.is_open())
	{
		std::cout << "Couldn't open teams.txt" << std::endl;
		return 2;
	}
	
	League league1;
	league1.setName("Golqma liga");

	std::vector<Player> players;
	std::vector<Team> teams;

	seedPlayers(players, playersInput);
	seedTeams(teams, teamsInput, players);

	league1.setTeams(teams);

	play(league1);
	league1.sortTeamsByPoints();
	league1.displayRanking();


	return 0;
}

void seedPlayers(std::vector<Player>& players, std::ifstream& playersInput)
{
	while (!playersInput.eof())
	{
		char playerName[20];
		int age;
		double salary;

		playersInput >> playerName >> age >> salary;

		Player player(playerName, age, salary);

		players.push_back(player);
	}
}

void seedTeams(std::vector<Team>& teams, std::ifstream& teamsInput, std::vector<Player>& players)
{
	while (!teamsInput.eof())
	{
		char teamName[20];

		teamsInput >> teamName;

		Team team(teamName);

		teams.push_back(team);
	}

	for (int i = 0; i < teams.size(); i++)
	{
		teams[i].addPlayer(players[i]);
	}
}

void playGame(Team& team1, Team& team2)
{
	int randNum = (rand() % 3) + 1;

	switch (randNum)
	{
	case 1:
		team1.setWins(team1.getWins() + 1);
		team1.setPoints(team1.getPoints() + 3);
		team2.setLoses(team2.getLoses() + 1);
		break;
	case 2:
		team1.setDraws(team1.getDraws() + 1);
		team1.setPoints(team1.getPoints() + 1);
		team2.setDraws(team2.getDraws() + 1);
		team2.setPoints(team2.getPoints() + 1);
		break;
	case 3:
		team2.setWins(team2.getWins() + 1);
		team2.setPoints(team2.getPoints() + 3);
		team1.setLoses(team1.getLoses() + 1);
		break;
	default:
		break;
	}
}

void play(League& league)
{
	std::vector<Team> teams = league.teams;

	for (int i = 1, j = 0; i < teams.size(); i++)
	{
		playGame(teams[0], teams[i]);

		if (i == teams.size() - 1)
		{
			league.teams[j] = teams[0];
			j++;
			teams.erase(teams.begin());
			if (teams.size() == 1)
			{
				league.teams[j] = teams[0];
			}
			else
			{
				i = 0;
			}
		}
	}
}