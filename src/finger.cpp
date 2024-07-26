#pragma once

#include <cmath>
#include "key.h"

class Finger
{
public: 
    int id;
    double distanceTravelled;
    bool isUsed;
    double dexterity;
    double currentX, currentY;
    double homeX, homeY;

    Finger(int id, double homex, double homeY, double dexterity) : id(id), distanceTravelled(0), isUsed(false), dexterity(dexterity), currentX(homeX), currentY(homeY), homeX(homeX), homeY(homeY) {}

    void press(const Key& key)
    {
        double dist = std::sqrt(std::pow(key.x - currentX, 2) + std::pow(key.y - currentY, 2));
        distanceTravelled += dist * (1/dexterity) * isUsed ? 2 : 1;
        currentX = key.x;
        currentY = key.y;
        isUsed = true;
    }
};