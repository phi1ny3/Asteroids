#pragma once
/***********************************************************************
 * Header File:
 *    Velocity : A class representing the Velocity
 * Author:
 *    Jordan Hakes
 * Summary:
 *    Velocity, very good
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"




 /********************************************
  * VELOCITY
  *
  ********************************************/
class Velocity
{
public:
	// Default Constructor
	Velocity()
	{
		dx = 0;
		dy = 0;
	}
	// Non Default Constructor
	Velocity(float a, float b)
	{
		dx = a;
		dy = b;
	}
	// Returns dx variable value
	float getDx();
	// Returns dy variable value
	float getDy();
	// Sets dx variable value
	void setDx(float);
	// Sets dy variable value
	void setDy(float);

protected:
	// Variables
	float dx;

	float dy;


};
#endif // VELOCITY_H