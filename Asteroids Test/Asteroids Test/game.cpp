#include "pch.h"
/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

 // These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
 
 float Game :: getClosestDistance(const flyingobject &obj1, const flyingobject &obj2) //const
 {
	 //why are the obj1 things here not working? Find out

	// find the maximum distance traveled
	float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
	dMax = max(dMax, abs(obj2.getVelocity().getDx()));
	dMax = max(dMax, abs(obj2.getVelocity().getDy()));
	dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

	float distMin = std::numeric_limits<float>::max();
	for (float i = 0.0; i <= dMax; i++)
	{
	   Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
					  obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
	   Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
					  obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

	   float xDiff = point1.getX() - point2.getX();
	   float yDiff = point1.getY() - point2.getY();

	   float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

	   distMin = min(distMin, distSquared);
	}

	return sqrt(distMin);
 }


 //Skeet Game Functions
 /*
 /***************************************
 * GAME CONSTRUCTOR
 ***************************************/
 Game::Game(Point tl, Point br)
	 : topLeft(tl), bottomRight(br), Ship()
 {
	 // Set up the initial conditions of the game
	 score = 0;

	 // TODO: Set your bird pointer to a good initial value (e.g., NULL)
	 Rock = NULL;

 }

 /****************************************
  * GAME DESTRUCTOR
  ****************************************/
 Game :: ~Game()
 {
	 // TODO: Check to see if there is currently a bird allocated
	 //       and if so, delete it.
	 if (Rock != NULL) {
		 delete Rock;
	 }
 }

 /***************************************
  * GAME :: ADVANCE
  * advance the game one unit of time
  ***************************************/
 void Game::advance()
 {
	 advanceBullets();
	 advanceShip();
	 advanceRock();

	 handleCollisions();
	 cleanUpZombies();
 }

 /***************************************
  * GAME :: ADVANCE BULLETS
  * Go through each bullet and advance it.
  ***************************************/
 void Game::advanceBullets()
 {
	 // Move each of the bullets forward if it is alive
	 for (int i = 0; i < bullets.size(); i++)
	 {
		 if (bullets[i].isAlive())
		 {
			 // this bullet is alive, so tell it to move forward
			 bullets[i].advance();

			 if (!isOnScreen(bullets[i].getPoint()))
			 {
				 // the bullet has left the screen
				 // we need it to wrap around the opposite side
			 }

		 }
	 }
 }
 //We should have a function here to initialize the first 5 rocks in a vector


 //Then we need to have the rocks split into smaller rocks when their hit points are depleated 

 /**************************************************************************
  * GAME :: ADVANCE BIRD
  *
  * 1. If there is no bird, create one with some probability
  * 2. If there is a bird, and it's alive, advance it
  * 3. Check if the bird has gone of the screen, and if so, "kill" it
  **************************************************************************/
 void Game::advanceRock()
 {
	 
	 // we have a rock, make sure it's alive
		 if (Rock->isAlive())
		 {
			 // move it forward
			 Rock->advance();

			 // check if the bird has gone off the screen
			 if (!isOnScreen(Rock->getPoint()))
			 {
				 // We have missed the bird
				 Bird->kill();
			 }
		 }
	 

 }

 //Create and initialize the ship

 /**************************************************************************
  * GAME :: IS ON SCREEN
  * Determines if a given point is on the screen.
  **************************************************************************/
 bool Game::isOnScreen(const Point & point)
 {
	 //What is the off screen border amount
	 return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
		 && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
		 && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
		 && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
 }

 /**************************************************************************
  * GAME :: HANDLE COLLISIONS
  * Check for a collision between a bird and a bullet.
  **************************************************************************/
 void Game::handleCollisions()
 {
	 //Add in functionality for the ships collision with rocks 

	 //change the bellow function so that the rocks get hit by bullets

	 // now check for a hit (if it is close enough to any live bullets)
	 for (int i = 0; i < bullets.size(); i++)
	 {
		 if (bullets[i].isAlive())
		 {
			 // this bullet is alive, see if its too close

			 // check if the bird is at this point (in case it was hit)
			 if (Bird != NULL && Bird->isAlive())
			 {
				 // BTW, this logic could be more sophisiticated, but this will
				 // get the job done for now...
				 if (fabs(bullets[i].getPoint().getX() - Bird->getPoint().getX()) < CLOSE_ENOUGH
					 && fabs(bullets[i].getPoint().getY() - Bird->getPoint().getY()) < CLOSE_ENOUGH)
				 {
					 //we have a hit!

					 // hit the bird
					 int points = Bird->hit();
					 score += points;

					 // the bullet is dead as well
					 bullets[i].kill();
				 }
			 }
		 } // if bullet is alive

	 } // for bullets
 }

 /**************************************************************************
  * GAME :: CLEAN UP ZOMBIES
  * Remove any dead objects (take bullets out of the list, deallocate bird)
  **************************************************************************/
 void Game::cleanUpZombies()
 {
	 // check for dead Rocks
	 if (Rock != NULL && Rock->isAlive() == false)
	 {
		 // the bird is dead, but the memory is not freed up yet

		 // TODO: Clean up the memory used by the bird
		 delete Rock;
		 Rock = NULL;
	 }

	 // Look for dead bullets
	 vector<Bullet>::iterator bulletIt = bullets.begin();
	 while (bulletIt != bullets.end())
	 {
		 Bullet bullet = *bulletIt;
		 // Asteroids Hint:
		 // If we had a list of pointers, we would need this line instead:
		 //Bullet* pBullet = *bulletIt;

		 if (!bullet.isAlive())
		 {
			 // If we had a list of pointers, we would need to delete the memory here...


			 // remove from list and advance
			 bulletIt = bullets.erase(bulletIt);
			 //bulletIt++; // advance

		 }
		 else
		 {
			 bulletIt++; // advance
		 }
	 }
	 //Look for a dead ship

 }

 /***************************************
  * GAME :: HANDLE INPUT
  * accept input from the user
  ***************************************/
 void Game::handleInput(const Interface & ui)
 {
	 // Change the direction of the rifle
	 if (ui.isLeft())
	 {
		 Ship.rotateLeft();
	 }

	 if (ui.isRight())
	 {
		 Ship.rotateRight();
	 }
	 if (ui.isUp())
	 {
		 //increase the ships forward velocity
	 }
	 // Check for "Spacebar
	 if (ui.isSpace())
	 {
		 Bullet newBullet;
		 newBullet.fire(Ship.getPoint(), Ship.getAngle());

		 bullets.push_back(newBullet);
	 }
 }

 /*********************************************
  * GAME :: DRAW
  * Draw everything on the screen
  *********************************************/
 void Game::draw(const Interface & ui)
 {
	 // draw the Rocks

	 // TODO: Check if you have a valid bird and if it's alive
	 // then call it's draw method

	 if (Ship != NULL && Ship->isAlive() == true) {
		 Ship->draw();
	 }


	 // draw the Ship
	 rifle.draw();

	 // draw the bullets, if they are alive
	 for (int i = 0; i < bullets.size(); i++)
	 {
		 if (bullets[i].isAlive())
		 {
			 bullets[i].draw();
		 }
	 }

	 // Put the score on the screen
	 Point scoreLocation;
	 scoreLocation.setX(topLeft.getX() + 5);
	 scoreLocation.setY(topLeft.getY() - 5);

	 drawNumber(scoreLocation, score);

 }
 
 //Moonlander Game 
 //Just in case implementation stuff
 /******************************************
  * GAME :: JUST LANDED
  * Did we land successfully?
  ******************************************/
 bool Game::justLanded() const
 {
	 bool landed = false;

	 Point platformCenter = ground.getPlatformPosition();
	 int width = ground.getPlatformWidth();

	 float xDiff = lander.getPoint().getX() - platformCenter.getX();
	 float yDiff = lander.getPoint().getY() - platformCenter.getY();

	 float margin = width / 2.0;

	 if (fabs(xDiff) < margin)
	 {
		 // between edges

		 if (yDiff < 4 && yDiff >= 0)
		 {
			 // right above it

			 if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
			 {
				 // we're there!
				 landed = true;
			 }
		 }
	 }

	 return landed;
 }

 /***************************************
  * GAME :: ADVANCE
  * advance the game one unit of time
  ***************************************/
 void Game::advance()
 {
	 if (lander.isAlive() && !lander.isLanded())
	 {
		 // advance the lander
		 lander.applyGravity(GRAVITY_AMOUNT);
		 lander.advance();

		 // check for crash
		 if (!ground.isAboveGround(lander.getPoint()))
		 {
			 lander.setAlive(false);
		 }

		 // check for just landed
		 if (justLanded())
		 {
			 lander.setLanded(true);
		 }
	 }
 }

 /***************************************
  * GAME :: HANDLE INPUT
  * accept input from the user
  ***************************************/
 void Game::handleInput(const Interface & ui)
 {
	 if (lander.isAlive() && !lander.isLanded())
	 {

		 if (ui.isDown())
		 {
			 lander.applyThrustBottom();
		 }

		 if (ui.isLeft())
		 {
			 lander.applyThrustLeft();
		 }

		 if (ui.isRight())
		 {
			 lander.applyThrustRight();
		 }
	 }
 }

 /*********************************************
  * GAME :: DRAW
  * Draw everything on the screen
  *********************************************/
 void Game::draw(const Interface & ui)
 {
	 lander.draw();

	 Point textLocation;
	 textLocation.setX(topLeft.getX() + 115);
	 textLocation.setY(topLeft.getY() - 20);

	 Point textLocation2;
	 textLocation2.setX(topLeft.getX() + 115);
	 textLocation2.setY(topLeft.getY() - 30);



	 if (lander.isLanded())
	 {
		 drawText(textLocation, "You have successfully landed!");
		 //drawText(textLocation2, "Press a to play again or b to quit");
	 }

	 if (!lander.isAlive())
	 {
		 drawText(textLocation, "You have crashed!");
		 //drawText(textLocation2, "Press a to play again or b to quit");
	 }

	 if (lander.canThrust())
	 {
		 drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
	 }

	 Point fuelLocation;
	 fuelLocation.setX(topLeft.getX() + 5);
	 fuelLocation.setY(topLeft.getY() - 5);

	 drawNumber(fuelLocation, lander.getFuel());

	 // draw ground
	 ground.draw();
 }