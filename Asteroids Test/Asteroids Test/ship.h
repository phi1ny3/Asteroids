#pragma once
#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include "flyingObject.h"

class ship :
	public flyingobject
{
public:
	ship();
	~ship();
	void draw();
};

