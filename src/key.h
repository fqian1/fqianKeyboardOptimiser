#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <utility>

class Key {
public:
    Key(int id, std::pair<int, int> pos, char reg_char, char sh_char, int fing);

    void print() const;

    int id;
    std::pair<int, int> position;
    char regular_char;
    char shift_char;
    int finger_id;
};

#endif 
