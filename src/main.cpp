#include <iostream>
#include <vector>
#include <cmath>
#include <map
#include "finger.h"
#include "key.h"


constexpr void initialiseFingers()
{

}

 int main()
 {

    std::vector<Finger> fingers;
    fingers.push_back(Finger(-1, 0, 2.25, 2.25, 0.6));
    fingers.push_back(Finger(0, 0, 3.25, 2.25, 0.8));
    fingers.push_back(Finger(1, 0, 4.25, 2.25, 1));
    fingers.push_back(Finger(2, 0, 5.25, 2.25, 0.8));
    fingers.push_back(Finger(3, 1, 8.25, 2.25, 0.6));
    fingers.push_back(Finger(4, 1, 9.25, 2.25, 0.8));
    fingers.push_back(Finger(5, 1, 10.25, 2.25, 1));  
    fingers.push_back(Finger(6, 1, 11.25, 2.25, 0.8));

    return 0;
 } 