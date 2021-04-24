#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <memory>
#include "celestial.h"

using std::vector;
using std::shared_ptr;

const double G = 6.67430e-11;

class Universe{
public:
    Universe(int initWindowSize);
    void step(double seconds);

    vector<shared_ptr<CelestialBody>> myVector;

private:
    int windowSize;
    int numberOfParticles;
    float radius;

    void calculateNetForce(shared_ptr<CelestialBody> obj, double& xF, double& yF);
};


#endif