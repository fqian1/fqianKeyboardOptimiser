#include <iostream>
#include <cmath>
#include "key.h"
#include "finger.h"

Finger::Finger(int id, std::pair<double, double> home_pos, double dex)
        : id(id), home_position(home_pos), current_position(home_pos), score(0), dexterity(dex), isUsed(false){}

inline double Finger::distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2)
{
    double dx = p2.first - p1.first;
    double dy = p2.second - p1.second;
    return std::sqrt(dx*dx + dy*dy);
}

double Finger::press(const Key& key)
{
    double x{std::pow(Finger::distance(current_position, key.position), 1/dexterity) + (isUsed ? 1 : 0)};
    score += x; 
    current_position = key.position;
    isUsed = true;
    return x;
}

double Finger::getDistanceTo(const Key& key)
{
    return distance(current_position, key.position);
}

void Finger::returnToHome()
{
    isUsed = false;
    current_position = home_position;
}

void Finger::moveToKey(const Key& key) {
    current_position = key.position;
}

void Finger::moveToPos(std::pair<double, double> pos)
{
    current_position = std::pair<double, double>(home_position.first + pos.first, home_position.second + pos.first);
}

void Finger::print() const{
    std::cout << "Finger(ID: " << id << ", Home: (" 
                << home_position.first << ", " << home_position.second 
                << "), Current: (" << current_position.first << ", " 
                << current_position.second << "))" << std::endl;
}

