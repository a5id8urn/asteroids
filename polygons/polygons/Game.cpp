#include <SFML/Graphics.hpp>
#include "constants.h"
#include "spaceObject.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//============================================================================
// new additions
Point  getRandomLocation();
Point getRandomVelocity();

int main()
{

	//create graphics window
	sf::RenderWindow window(
		sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
		"Polygons!",
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setFramerateLimit(60);

	//SETTING A RANDOM AMOUNT
	srand(42);
	for (int x = 0; x < 20; x++) {
		int randNum = rand() % 4 + 1;
		std::cout << randNum << '/n';
	}
	
	//create SpaceObjects
		//TODO: create asteroid (step 2.2)
	// this is how to talk to spaceOB-->>>>SpaceObject(SpaceObjType type, double radius, Point location, Point velocity, double angle);
	SpaceObject* asteroid = new SpaceObject(ASTEROID, 50.0, getRandomLocation(), getRandomVelocity(), 180.5);
	//getRandomVelocity();
	asteroid->drawAsteroid(window);
	//asteroid SpaceObject(ASTEROID, 10.0, (5,5), (5,5), 60);

	SpaceObject* ship = new SpaceObject(SHIP, 10, { 500, 500 }, { 0, 0 }, 0);
	//TODO: create ship (step 3.2)

	ship->drawShip(window);



	//game loop
	while (window.isOpen())
	{
		//handle user input (events and keyboard keys being pressed) ----
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			/*TODO: add code here to rotate ship left*/
			ship->changeAngle(1);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			/*TODO: add code here to rotate ship right*/
			ship->changeAngle(-1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			/*TODO: add code here to fire ships engine*/
			ship->applyThrust();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			/*TODO: add code here to fire ships engine*/
			ship->applyBrakes();

		// update game objects ------------------------------------------
		asteroid->updatePosition(); //uncomment this in step 2.2


		ship->updatePosition(); //uncomment this in step 3.2
		//Where you update the ship’s location (and previously updated the asteroid’s location)
		//Add code that goes through the entire Asteroid arrayand calls updateLocation for each non - null entry.


// draw new frame ------------------------------------------------
		window.clear();
		asteroid->draw(window);  //uncomment this in step 2.2 !!
		ship->draw(window);  //uncomment this in step 3.2 !!
		window.display();
	}


	return 0;
}

//Function definitions/implementations go here.

//returns a Point structure that contains A random x value between 0 and the SCREEN_WIDTH A random y value between 0 and the SCREEN_HEIGHT
Point getRandomLocation() {
	Point randLocation{};
	int domainX = SCREEN_WIDTH;
	int domainY = SCREEN_HEIGHT;
	int min = 0;
	int rangeX = domainX - min + 1;
	int rangeY = domainY - min + 1;
	randLocation.x = rand() % rangeX;
	randLocation.y = rand() % rangeY;
	
	return randLocation;

}


Point getRandomVelocity() {
	Point randVelocity{};
	int randVel_X1 = (1);
	int randVel_Y1 =( 1);
	
	randVelocity.x = (randVel_X1+110)^rand();
	randVelocity.y = (randVel_Y1+10)^rand();
	
	// test 
	std::cout << "***********************"<<randVelocity.y << '/n';
	
	//std::cout << randVelocity.y << '/n';
	return randVelocity;
	//this would kepp the number output to -1,1
	// if the random # is EVEN the output will be (positive) 1
	// if the random # is odd the output will be (negitve) -1
	// idk if the random # generator will kick out the number 0. possible fix, i should have it set to ^(srand()+1) forcing it to kick out any number besides 0

}

// CALLING THE FUNCTION FOR MAIN() MOVE AFTER COMPLITION OF THE FUNCTIONS ABOVE 
//SpaceObject(SpaceObjType::ASTEROID, 5.0, getRandomLocation(), getRandomVelocity(), 6.34); //this wouldn't be in here i don't think


/*
**********************************************************
that takes two SpaceObject pointers,
and returns true if the objects overlap on the screen
(compute the distance between the objects positions and compare that to the sum of their radii.).
Note: this function is NOT a member of the class,
it will need to call the accessor functions for the objects it was given (via pointers)
to get the info it needs about the objects).
right after you’ve updated the ship and asteroid’s locations,
determine if the ship has run into one of the asteroids by writing a loop that
goes through the Asteroid array and calls objectsIntersect for each non-null entry,
passing it the asteroid and the ship.  If true is returned, just print out “Crash!” on the console.
**********************************************************
bool objectsIntersect(spaceObject1,spaceObject2)
if ()
something = true;
return "Crash";
*/






/*
wondering how to add an easter egg of some sort. maybe increase the asteroids to super fast or make them invisible. then apone game end in this mode kick in the
ascii image of colorBlind Carl looking like hipster jesus or some kinda of notification of his likeness
*/