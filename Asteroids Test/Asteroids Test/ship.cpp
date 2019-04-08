#include "pch.h"
#include "ship.h"


ship::ship()
{
	angle = 0;
}


ship::~ship()
{
}

void ship::draw()
{
	cout << "draw() called x = " << point.getX() << "x" << "y = " << point.getY();
	cout << "dx = " << velocity.getDx() << "dy = " << velocity.getDy() << "\n";
	drawShip(point, getAngle() , THRUST_AMOUNT);
}


