#pragma once
#include <SFML/Graphics.hpp>


struct Point { 
	double x;
	double y;
};

enum SpaceObjType { SHIP, ASTEROID, PHOTON_TORPEDO, SHIP_EXPLODING, SHIP_GONE };

class SpaceObject
{
public:
	SpaceObject();
	SpaceObject(SpaceObjType type, double radius, Point location, Point velocity, double angle);
	//=============================================
	//mutators
	bool setRadius(int radius);
	bool setLocation(double x, double y);
	bool setVelocity(double velocityX, double velocityY);
	bool setAngle(double angDeg);
	void applyThrust();
	void applyBrakes();
	//change angle by given amount.
	void changeAngle(double deltaDeg);
	//============================================
	//accessors
	double getRadius() const;
	Point getLocation() const;
	Point getVelocity() const;
	double getAngle() const;
	
	//============================================
	//others
	void updatePosition();
	void draw(sf::RenderWindow& win);
	void drawAsteroid(sf::RenderWindow& win);
	void drawShip(sf::RenderWindow& win);
// the exlosion start here
	void explode();

private:
	SpaceObjType type;	  //type of object
	Point location;	  //current location (x,y)
	Point velocity;	  //current velocity (in pixels/frame)
	double angleDeg;	  //angle object is facing (in degrees)
	double radius;        //gross radius of object (for collision detection)

};

