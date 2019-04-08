#pragma once
#include "flyingObject.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"
#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

class Game
{
public:
	Game();
	Game(Point, Point);
	~Game();
	float getClosestDistance(const flyingobject &obj1, const flyingobject &obj2); //const;

	/*********************************************
	 * Constructor
	 * Initializes the game
	 *********************************************/
	Game(Point tl, Point br);
	~Game();

	/*********************************************
	 * Function: handleInput
	 * Description: Takes actions according to whatever
	 *  keys the user has pressed.
	 *********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	 * Function: advance
	 * Description: Move everything forward one
	 *  step in time.
	 *********************************************/
	void advance();

	/*********************************************
	 * Function: draw
	 * Description: draws everything for the game.
	 *********************************************/
	void draw(const Interface & ui);

private:
	rock *Rock;
	ship Ship;

	Point topLeft;
	Point bottomRight;

	int score;
	std::vector<Bullet> bullets;
	std::vector<rock> rocks;

	/*************************************************
	 * Private methods to help with the game logic.
	 *************************************************/
	bool isOnScreen(const Point & point);
	void advanceBullets();
	void advanceShip();
	void advanceRock();
	ship* createShip();

	void handleCollisions();
	void cleanUpZombies();
};

