#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "celestial.h"

using std::cout;
using std::istream;
using std::ostream;
using std::cin;
using std::endl;

CelestialBody::CelestialBody(float initRadius, float initWindowHeight): xPos(0), yPos(0), xVel(0), yVel(0), mass(0), radius(initRadius), windowHeight(initWindowHeight){ }

void CelestialBody::setSprite(void){
    texture.loadFromFile(fileName);
    sprite.setTexture(texture);
}

void CelestialBody::setSpritePos(void){
    float adjustment = windowHeight/2;
    float scale = adjustment/radius;
    float adjustedX = adjustment + (scale * xPos);
    float adjustedY = adjustment - (scale * yPos);

    sprite.setPosition(adjustedX, adjustedY);
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(sprite, states);
}

istream& operator>>(istream& in, CelestialBody& obj){
    in >> obj.xPos >> obj.yPos >> obj.xVel >> obj.yVel >> obj.mass >> obj.fileName;

    return in;
}

ostream& operator<<(ostream& out, const CelestialBody& obj){
    out << obj.xPos  << ' ' << obj.yPos << ' ' << obj.xVel << ' ' << obj.yVel << ' ' << obj.mass << ' ' << obj.fileName << endl;

    return out;
}


