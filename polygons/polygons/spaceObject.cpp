#include "spaceObject.h"
#include "constants.h"
#include <SFML/Graphics.hpp>



SpaceObject::SpaceObject() {
	this->type = ASTEROID;
	this->radius = 10;
	this->velocity.x = 1;
	this->velocity.y = 1;
	this->location.x = 1;
	this->location.y = 1;
	this->angleDeg = 90;
}
SpaceObject::SpaceObject(SpaceObjType type, double radius,
	Point location, Point velocity, double angle) {
	this->type = type;
	this->radius = radius;
	this->location = location;
	this->velocity = velocity;
	this->angleDeg = angle;
}
//=============================================
//mutators 
bool SpaceObject::setRadius(int radius) {
	if (radius < 0 || radius>(SCREEN_HEIGHT / 2))
		return false;
	this->radius = radius;
	return true;
}
bool SpaceObject::setLocation(double x, double y) {
	if (x < 0 || x>SCREEN_HEIGHT) {
		return false;
		if (y < 0 || y>SCREEN_WIDTH)
			return false;
	}
	location.x = x;
	location.y = y;

	return true;
}
bool SpaceObject::setVelocity(double velocityX, double velocityY) {
	if (velocityX < 0 || velocityX > 5) {
		return false;
		if (velocityY < 0 || velocityY > 5)
			return false;
	}
	velocity.x = velocityX;
	velocity.y = velocityY;
	return true;

}
bool SpaceObject::setAngle(double angDeg) {
	if (angDeg < 0 || angDeg > 359)
		return false;

	angleDeg = angDeg;
	return true;
}



//change angle by given amount.
void SpaceObject::changeAngle(double deltaDeg) {
	//this is to deturmine if the player is turning left or right
	double turn = getAngle();
	//to turn right
	if (deltaDeg < 0) {
		angleDeg = turn + 1;
	}
	//turn left
	if (deltaDeg > 0) {
		angleDeg = turn - 1;
	}
	// add if statements so if the type is not SHIP nothing is done (only ships in good working order, i.e. not exploding, are controllable)
}
//
////accessors
double SpaceObject::getRadius() const {
	return radius;
}
Point SpaceObject::getLocation() const {
	return location;
}
Point SpaceObject::getVelocity() const {
	return velocity;
}
double SpaceObject::getAngle() const {
	return angleDeg;
}

//
////============================================
////others
void SpaceObject::updatePosition() {
	//this keeps the asteroid and ship on the world map
	location.x = location.x + velocity.x;
	location.y = location.y + velocity.y;
	//htis keeps the right in bounds
	if (location.x < 0)
		location.x = SCREEN_WIDTH;
	//this keep the left in bounds
	if (location.x > SCREEN_WIDTH)
		location.x = 0;

	//this keeps the bottom in bounds
	if (location.y < 0)
		location.y = SCREEN_HEIGHT;
	// this keeps the top in bounds
	if (location.y > SCREEN_HEIGHT)
		location.y = 0;


	setLocation(location.x, location.y);
}


/** --------------------------------------------------------------------------
*   Draws the spaceobject on the given window
*
*     @param win - the window on which we’ll draw the ship
---------------------------------------------------------------------------- */
void SpaceObject::draw(sf::RenderWindow& win) {
	if (type == SHIP)
		drawShip(win);
	else
		drawAsteroid(win);
}

/** --------------------------------------------------------------------------
*   Draws the spaceobject on the given window as an asteroid
*
*     @param win - the window on which we’ll draw the ship
---------------------------------------------------------------------------- */
void SpaceObject::drawAsteroid(sf::RenderWindow& win) {
	//Configure a graphics object to be used for drawing our object
	//this code draws a simple pentagon.Feel free to modify it if you want.
	int points = 5;
	sf::CircleShape shape(radius, points); //radius from our SpaceObject

	sf::Vector2f midpoint(radius, radius);
	shape.setOrigin(midpoint);

	shape.setFillColor(sf::Color(111, 111, 111));
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color(255, 255, 255));

	//apply our object position to the graphics object and draw it
	shape.setPosition(location.x, location.y);
	shape.setRotation(angleDeg);

	win.draw(shape);

	//Note: if asteroid is near the edge (within a radius) then we should 
	//draw it again on the other side of the screen so the part off the edge 
	//shows up immediately on the other edge. Code to do that should be added
	//here.
}

/** --------------------------------------------------------------------------
*   Draws the spaceobject on the given window as a ship
*
*     @param win - the window on which we’ll draw the ship
---------------------------------------------------------------------------- */
void SpaceObject::drawShip(sf::RenderWindow& win) {
	// draw ship
	sf::ConvexShape shipShape;
	shipShape.setPointCount(3);
	shipShape.setPoint(0, sf::Vector2f(10, 0));
	shipShape.setPoint(1, sf::Vector2f(0, 25));
	shipShape.setPoint(2, sf::Vector2f(20, 25));

	sf::Vector2f midpoint(10, 15);
	shipShape.setOrigin(midpoint);

	shipShape.setFillColor(sf::Color(0, 0, 0));
	shipShape.setOutlineThickness(1);
	shipShape.setOutlineColor(sf::Color(255, 255, 255));

	shipShape.setPosition(location.x, location.y);
	shipShape.setRotation(angleDeg);
	win.draw(shipShape);
}
void SpaceObject::applyThrust() {
	double engineThrust = 0.05;
	double forcex = cos((angleDeg - 90) * PI / 180) * engineThrust;
	double forcey = sin((angleDeg - 90) * PI / 180) * engineThrust;
	velocity.x = velocity.x + forcex;
	velocity.y = velocity.y + forcey;
	// add if statements so if the type is not SHIP nothing is done (only ships in good working order, i.e. not exploding, are controllable)

}
// this gives the ship a reverse
void SpaceObject::applyBrakes() {
	double engineThrust = -0.1;
	double forcex = cos((angleDeg - 90) * PI / 180) * engineThrust;
	double forcey = sin((angleDeg - 90) * PI / 180) * engineThrust;
	velocity.x = velocity.x + forcex;
	velocity.y = velocity.y + forcey;
	// add if statements so if the type is not SHIP nothing is done (only ships in good working order, i.e. not exploding, are controllable)

}
/*
implementation for the explode() function. It should change the type
from SHIP to SHIP_EXPLODING, and change its velocity to 0.

*/
void explode(){}