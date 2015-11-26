#include "score.hpp"

Score::~Score()
{
	
};

Score::Score()
{
	
};

Score::Score(std::string nname, int result)

{
	name = nname;
	score = result;
	
	
	
};

void Score::setName(std::string nom)
{
	name = nom;
};

void Score::setScore(int scr)
{
	score = scr;
};

int Score::getScore()
{
	return score;
};

std::string Score::getName()
{
	return name;
};
