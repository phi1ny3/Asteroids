#include "pch.h"
#include "rocks.h"


rock::rock()
{
}


rock::~rock()
{
}

bigRock::~bigRock()
{
}

void bigRock::draw()
{
	cout << "draw() called x = " << point.getX() << "x" << "y = " << point.getY();
	cout << "dx = " << velocity.getDx() << "dy = " << velocity.getDy() << "\n";
	drawSmallAsteroid(point, SMALL_ROCK_SPIN);
}

mediumRock::~mediumRock()
{
}

void mediumRock::draw()
{
	cout << "draw() called x = " << point.getX() << "x" << "y = " << point.getY();
	cout << "dx = " << velocity.getDx() << "dy = " << velocity.getDy() << "\n";
	drawMediumAsteroid(point, MEDIUM_ROCK_SPIN);
}

smallRock::~smallRock()
{
}

void smallRock::draw()
{
	cout << "draw() called x = " << point.getX() << "x" << "y = " << point.getY();
	cout << "dx = " << velocity.getDx() << "dy = " << velocity.getDy() << "\n";
	drawLargeAsteroid(point, BIG_ROCK_SPIN);
}
