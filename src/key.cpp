#include <iostream>
#include <vector>
#include "key.h"

class Key {
public:
    int id;
    std::pair<int, int> position;
    char regular_char;
    char shift_char;
    int finger_id;

    Key(int id, std::pair<int, int> pos, char reg_char, char sh_char, int fing)
       : id(id), position(pos), regular_char(reg_char), shift_char(sh_char), finger_id(fing) {}

    void print() const 
    {
        std::cout << "Key(ID: " << id << ", Position: (" << position.first << ", " << position.second
                  << "), Regular: '" << regular_char << "', Shift: '" << shift_char << "', Finger: "
                  << finger_id << ")" << std::endl;
    }
};