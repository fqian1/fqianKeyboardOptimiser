#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class Key {
public:
    int id;
    std::pair<int, int> position;
    char regular_char;
    char shift_char;
    std::vector<int> finger_ids;

    Key(int key_id, std::pair<int, int> pos, char reg_char, char sh_char, std::vector<int> fings)
        : id(key_id), position(pos), regular_char(reg_char), shift_char(sh_char), finger_ids(fings) {}

    void print() const {
        std::cout << "Key(ID: " << id << ", Position: (" << position.first << ", " << position.second
                  << "), Regular: '" << regular_char << "', Shift: '" << shift_char << "', Fingers: [";
        for (const auto &finger_id : finger_ids) {
            std::cout << finger_id << " ";
        }
        std::cout << "])" << std::endl;
    }
};
