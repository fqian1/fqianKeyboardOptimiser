#pragma once

#include <utility>
#include <variant>
#include <vector>

using assignedFingers = std::variant<int, std::pair<int, int>>;

class Key {
public:
    int id;
    std::pair<int, int> position;
    char regular_char;
    char shift_char;
    assignedFingers finger_ids;

    Key(int key_id, std::pair<int, int> pos, char reg_char, char sh_char, 
        std::vector<assignedFingers> fings);

    void print() const; 
};
