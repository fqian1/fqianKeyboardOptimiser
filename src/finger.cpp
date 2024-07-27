#include <cmath>
#include "finger.h"
#include "key.h"

class Finger
{
public: 
    int id;
    double score;
    bool isUsed;
    double dexterity;
    double currentX, currentY;
    double homeX, homeY;

    Finger(int id, bool hand, double homex, double homeY, double dexterity)
          : id(id), score(0), isUsed(false), dexterity(dexterity), currentX(homeX), currentY(homeY), homeX(homeX), homeY(homeY) {}

    void press(const Key& key, bool prevHand)
    {
        double dist = std::sqrt(std::pow(key.x - currentX, 2) + std::pow(key.y - currentY, 2));
        score += std::pow(dist, 1/dexterity) + (isUsed ? 1 : 0);
        currentX = key.x;
        currentY = key.y;
        isUsed = true;
    }

    void move(const Key& key)
    {
        currentX = key.x;
        currentY = key.y;
    }

    void release()
    {
        isUsed = false;
        currentX = homeX;
        currentY = homeY;
    }
};