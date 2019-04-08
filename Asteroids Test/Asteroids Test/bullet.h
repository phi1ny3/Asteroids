#pragma once
#include "flyingObject.h"
#define BULLET_SPEED 5
#define BULLET_LIFE 40
class Bullet :
	public flyingobject
{
public:
	Bullet();
	~Bullet();
	void draw();
	void fire(Point a, float b);
};
