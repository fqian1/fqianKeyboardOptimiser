#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include "key.h"

using assignedFingers = std::variant<int, std::pair<int, int>>;

class Key {
public:
    int id;
    std::pair<int, int> position;
    char regular_char;
    char shift_char;
    std::vector<assignedFingers> finger_ids;

    Key(int id, std::pair<int, int> pos, char reg_char, char sh_char, std::vector<assignedFingers> fings)
       : id(id), position(pos), regular_char(reg_char), shift_char(sh_char), finger_ids(fings) {}

    void print() const 
    {
        std::cout << "Key(ID: " << id << ", Position: (" << position.first << ", " << position.second
                  << "), Regular: '" << regular_char << "', Shift: '" << shift_char << "', Fingers: [";
        for (const auto &finger_id : finger_ids) 
        {
            if(std::holds_alternative<int>(finger_id))
            {
                std::cout << std::get<int>(finger_id);
            }
            else
            {
                auto pair = std::get<std::pair<int, int>>(finger_id);
                std::cout << pair.first << pair.second << "\n";
            }
        }
        std::cout << "])" << std::endl;
    }
};
