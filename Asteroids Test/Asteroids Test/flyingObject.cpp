#include "pch.h"
#include "flyingObject.h"

flyingobject::flyingobject()
{
	Point point;
	Velocity velocity;
	alive = true;
}


flyingobject::~flyingobject()
{
}

Point flyingobject::getPoint()
{
	return point;
}

Velocity flyingobject::getVelocity()
{
	return velocity;
}

bool flyingobject::isAlive()
{
	return this->alive;
}

void flyingobject::setPoint(Point a)
{
	point = a;
}

void flyingobject::setVelocity(Velocity a)
{
	velocity = a;
}

void flyingobject::setAlive(bool a)
{
	alive = a;
}

void flyingobject::kill()
{
	this->alive = false;
}

void flyingobject::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}

int flyingobject::getAngle()
{
	return angle;
}

void flyingobject::setAngle(int a)
{
	this->angle = a;
}

void flyingobject::rotateLeft(int a)
{
	angle -= a;

}


void flyingobject::rotateRight(int a)
{
	angle += a;
}

