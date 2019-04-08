#include "pch.h"
/***********************************************************************
 * Source File:
 *    Velocity : The representation of the velocity
 * Author:
 *    Jordan Hakes
 * Summary:
 *    The velocity of the lander which gives the data to how it moves on screen.
 *
 ************************************************************************/

#include "velocity.h"
#include <cassert>

 /******************************************
  * Velocity :
  *
  *****************************************/

  // returns the velocity in the x direction
float Velocity::getDx()
{
	return dx;
}
// returns velocity in the y direction 
float Velocity::getDy()
{
	return dy;
}
// sets velocity in the x direction 
void Velocity::setDx(float a)
{
	dx = a;
}
// sets velocity in the y direction   
void Velocity::setDy(float a)
{
	dy = a;
}