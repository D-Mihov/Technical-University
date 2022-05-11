#pragma once
class Film
{
	char filmName[30];
	char releaseDate[30];
	char filmGenre[30];
	double price;
public:
	Film();
	Film(char *_filmName, char *_releaseDate, char *_filmGenre, double _price);
	~Film();
};

