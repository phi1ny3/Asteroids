#pragma once
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include <iostream>
#define M_PI 3.14
using namespace std;

class flyingobject
{
protected:
	Point point;
	Velocity velocity;
	bool alive;
	int angle;
public:
	flyingobject();
	~flyingobject();
	// returns flyingobject's point
	Point getPoint();
	// returns flyingobject's velocity
	Velocity getVelocity();
	// returns if alive is true or false
	bool isAlive();
	// sets flying object point
	void setPoint(Point a);
	// sets flying object velocity
	void setVelocity(Velocity a);
	// sets flying object alive true or false
	void setAlive(bool a);
	// sets flying object alive to false
	void kill();
	// advances the object's place on screen
	void advance();
	// virtual draw function
	virtual void draw() = 0;

	int getAngle();
	void setAngle(int);
	void rotateLeft(int);
	void rotateRight(int);
};

