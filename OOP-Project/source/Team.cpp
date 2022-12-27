#include "stdafx.h"
#include "Team.h"
#include <algorithm>


Team::Team()
{
	this->setTeamName("");
	this->setWins(0);
	this->setDraws(0);
	this->setLoses(0);
	this->setPoints(0);
}

Team::Team(char* teamName)
{
	Team::Team();
	this->setTeamName(teamName);
}


Team::~Team()
{
}

void Team::transferPlayer(char* playerName, Team& teamToTransfer)
{
	for (auto player : players)
	{
		if (strcmp(player.getName(), playerName) == 0)
		{
			teamToTransfer.addPlayer(player);
			this->removePlayer(player);
			return;
		}
	}
}

void Team::addPlayer(Player& player)
{
	if (this->players.size() < 20)
	{
		this->players.push_back(player);
	}
}

void Team::removePlayer(Player& player)
{
	//players.erase(std::remove(players.begin(), players.end(), player), players.end());
	players.erase(std::remove_if(players.begin(), players.end(), [this](Player& player) {
		for each (auto pl in this->getPlayers())
		{
			return player == pl;
		}
		return false;
	}), players.end());
}

std::vector<Player> Team::getPlayers() 
{
	return this->players;
}

int Team::getPoints()
{
	return this->points;
}

char* Team::getTeamName()
{
	return this->teamName;
}

int Team::getWins()
{
	return this->wins;
}

int Team::getDraws()
{
	return this->draws;
}

int Team::getLoses()
{
	return this->loses;
}

void Team::setTeamName(char* name)
{
	strcpy_s(this->teamName, 20, name);
}

void Team::setDraws(int draws)
{
	this->draws = draws;
}

void Team::setLoses(int loses)
{
	this->loses = loses;
}

void Team::setPoints(int points)
{
	this->points = points;
}

void Team::setWins(int wins)
{
	this->wins = wins;
}

bool Team::operator==(Team& team)
{
	if (strcmp(team.getTeamName(), this->teamName) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}