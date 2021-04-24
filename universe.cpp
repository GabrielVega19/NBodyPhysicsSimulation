#include <iostream>

#include "universe.h"
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

Universe::Universe(int initWindowSize): windowSize(initWindowSize) {
    cin >> numberOfParticles >> radius;
    
    for (int i = 0; i < numberOfParticles; i++){
        shared_ptr<CelestialBody> p = make_shared<CelestialBody>(radius, windowSize); 
        cin >> *p;
        p->setSprite();
        p->setSpritePos();

        myVector.push_back(p);
    }
}

void Universe::step(double seconds){
	double xF;
	double yF;
	double xA;
	double yA;

	for (int i = 0; i < numberOfParticles; i++){
		//calculates net force for the planet
		calculateNetForce(myVector[i], xF, yF);

		//calculates acceleration for the planet
		xA = xF / myVector[i]->getMass();
		yA = yF / myVector[i]->getMass();

		//calculates velocity for the planet
		myVector[i]->setXVel(myVector[i]->getXVel() + (seconds * xA));
		myVector[i]->setYVel(myVector[i]->getYVel() + (seconds * yA));

		//calculates the position for the planet
		myVector[i]->setXPos(myVector[i]->getXPos() + (seconds * myVector[i]->getXVel()));
		myVector[i]->setYPos(myVector[i]->getYPos() + (seconds * myVector[i]->getYVel()));

		//updates the sprite position for the planet
		myVector[i]->setSpritePos();
	}
}

void Universe::calculateNetForce(shared_ptr<CelestialBody> obj, double& xF, double& yF){
	xF = 0;
	yF = 0;

	double tempX;
	double tempY;
	double totalF;
	double r;
	double deltaY;
	double deltaX;

	for (int i = 0; i < numberOfParticles; i++){
		if (obj != myVector[i]){
			//calculate the r and delta x and y 
			deltaY = myVector[i]->getYPos() - obj->getYPos();
			deltaX = myVector[i]->getXPos() - obj->getXPos();
			r = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

			//calculate the total force
			totalF = (G * obj->getMass() * myVector[i]->getMass()) / pow(r, 2);


			//split up the total force into its components 
			tempX = totalF * (deltaX / r);
			tempY = totalF * (deltaY / r);

			//add it to the final net force
			xF += tempX;
			yF += tempY;
		}
	}
}

