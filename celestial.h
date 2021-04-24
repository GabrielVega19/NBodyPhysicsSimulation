#ifndef CELESTIAL_H
#define CELESTIAL_H

#include <string>
#include <SFML/Graphics.hpp>

using sf::Sprite;
using sf::Texture;
using std::istream;
using std::ostream;
using std::string;


class CelestialBody: public sf::Drawable {
public:
    CelestialBody(float initRadius, float initWindowHeight);
    
    void setSprite(void);
    void setSpritePos(void);
    double getXPos(void) const { return xPos; }
    double getYPos(void) const { return yPos; }
    double getMass(void) const { return mass; }  
    double getXVel(void) const { return xVel; }
    double getYVel(void) const { return yVel; }
    void setXVel(double XVel) { xVel = XVel; }
    void setYVel(double YVel) { yVel = YVel; }
    void setXPos(double XPos) { xPos = XPos; }
    void setYPos(double YPos) { yPos = YPos; }

    friend istream& operator>>(istream& in, CelestialBody& obj);
    friend ostream& operator<<(ostream& out, const CelestialBody& obj);
private:
    double xPos;
    double yPos;
    double xVel;
    double yVel;
    double mass;
    string fileName;

    float radius;
    float windowHeight;

    Sprite sprite;
    Texture texture;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

istream& operator>>(istream& in, CelestialBody& obj);
ostream& operator<<(ostream& out, const CelestialBody& obj);

#endif