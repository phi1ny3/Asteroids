#include "pch.h"
#include "bullet.h"
#include "ship.h"
#define _USE_MATH_DEFINES // for C++
#include <cmath>



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::draw()
{
	cout << "draw() called x = " << point.getX() << "x" << "y = " << point.getY();
	cout << "dx = " << velocity.getDx() << "dy = " << velocity.getDy() << "\n";
	drawDot(point);
}

void Bullet::fire(Point a, float b)
{
	float speed = 10.0;
	point = a;
	velocity.setDx(speed*(-cos(3.14159265358979323846 / 180.0*b)));
	velocity.setDy(speed*(sin(3.14159265358979323846 / 180.0*b)));
}
