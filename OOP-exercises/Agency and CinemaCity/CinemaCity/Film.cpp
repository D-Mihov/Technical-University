#include "stdafx.h"
#include "Film.h"
#include <string.h>

Film::Film()
{
	strcpy_s(filmName, 30, "");
	strcpy_s(releaseDate, 30, "");
	strcpy_s(filmGenre, 30, "");
	price = 0;
}

Film::Film(char *_filmName, char *_releaseDate, char *_filmGenre, double _price)
{
	strcpy_s(filmName, 30, _filmName);
	strcpy_s(releaseDate, 30, _releaseDate);
	strcpy_s(filmGenre, 30, _filmGenre);
	price = _price;
}

Film::~Film()
{
}
