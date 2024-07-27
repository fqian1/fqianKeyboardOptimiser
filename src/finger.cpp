#include <iostream>
#include <cmath>
#include "key.h"
#include "finger.h"

class Finger {
public:
    int id;
    double score;
    double dexterity;
    bool isUsed;
    std::pair<double, double> home_position;
    std::pair<double, double> current_position;

    Finger(int id, std::pair<double, double> home_pos, double dex)
        : id(id), home_position(home_pos), current_position(home_pos), score(0), dexterity(dex), isUsed(false){}

    inline double distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2)
    {
        double dx = p2.first - p1.first;
        double dy = p2.second - p1.second;
        return std::sqrt(dx*dx + dy*dy);
    }

    void press(const Key& key)
    {
        score += std::pow(distance(current_position, key.position), 1/dexterity) + (isUsed ? 1 : 0); 
        current_position = key.position;
        isUsed = true;
    }

    double getDistanceTo(const Key& key)
    {
        return distance(current_position, key.position);
    }

    void returnToHome()
    {
        isUsed = false;
        current_position = home_position;
    }
    
    void move(const Key& key) {
        current_position = key.position;
    }

    void print() const {
        std::cout << "Finger(ID: " << id << ", Home: (" 
                  << home_position.first << ", " << home_position.second 
                  << "), Current: (" << current_position.first << ", " 
                  << current_position.second << "))" << std::endl;
    }
};
