#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <utility>

class Key {
public:
    Key(int id, std::pair<double, double> pos, wchar_t reg_char, wchar_t sh_char, int fing);

    void print() const;

    int id;
    std::pair<double, double> position;
    wchar_t regular_char;
    wchar_t shift_char;
    int finger_id;
};

#endif 
