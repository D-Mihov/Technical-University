#include "stdafx.h"
#include "League.h"
#include <algorithm>
#include <iomanip>


League::League()
{
	this->name[0] = 0;
}


League::~League()
{
}

League::League(char* name)
{
	strcpy_s(this->name, 20, name);
}

void League::addTeam(Team& team)
{
	if (this->teams.size() < 20)
	{
		this->teams.push_back(team);
	}
}

void League::removeTeam(Team& team)
{
	//this->teams.erase(std::remove(teams.begin(), teams.end(), team), teams.end());
	teams.erase(std::remove_if(teams.begin(), teams.end(), [this](Team& team) {
		for each (auto tm in this->getTeams())
		{
			return team == tm;
		}
		return false;
	}), teams.end());
}

void League::dropDelegatedTeams()
{
	this->sortTeamsByPoints();
	for (int i = 0; i < 3; i++)
	{
		this->teams.pop_back();
	}
}

void League::sortTeamsByPoints()
{
	std::sort(this->teams.begin(), this->teams.end(), [](Team& team1, Team& team2) {
		return team1.getPoints() > team2.getPoints();
	});
}

void League::displayRanking()
{
	std::cout << "\tRanking" << std::endl;
	std::cout << "  W   D   L   P    Team Name" << endl;
	for each (auto team in this->teams)
	{
		std::cout << "| " << team.getWins() << " | "
			<< team.getDraws() << " | " << team.getLoses() << " | " << std::setw(2) << team.getPoints() << " | " << team.getTeamName() << std::endl;
	}
	std::cout << endl;

	std::cout << "Players from teams:" << endl;

	for each (auto team in this->teams)
	{
		std::cout << "  Team: " << team.getTeamName() << endl;
		for each (auto player in team.getPlayers())
		{
			std::cout << "    " << player.getName() << " " << player.getAge() << " " << player.getSalary() << endl;
		}
	}
}

char* League::getName()
{
	return this->name;
}

void League::setName(char* name)
{
	strcpy_s(this->name, 20, name);
}

void League::setTeams(std::vector<Team>& teams)
{
	this->teams = teams;
}

std::vector<Team> League::getTeams()
{
	return this->teams;
}