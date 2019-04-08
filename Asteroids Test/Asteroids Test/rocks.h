#pragma once

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10
#include "flyingObject.h"
#include <cmath>


class rock :
	public flyingobject
{
public:
	rock();
	~rock();
	virtual void draw() = 0;
};

class bigRock :
	public rock 
{
	bigRock() 
	{
		int a = random(0, 360);
		angle = a;
		velocity = Velocity(-cos(M_PI / 180.0 * angle), sin(M_PI / 180.0 * angle));
	}
	~bigRock();
	void draw();
};

class mediumRock :
	public rock
{
	mediumRock();
	~mediumRock();
	void draw();
};

class smallRock :
	public rock 
{
	smallRock();
	~smallRock();
	void draw();
};