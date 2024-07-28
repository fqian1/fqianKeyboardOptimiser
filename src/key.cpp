#include <iostream>
#include <vector>
#include "key.h"

Key::Key(int id, std::pair<double, double> pos, wchar_t reg_char, wchar_t sh_char, int fing)
        : id(id), position(pos), regular_char(reg_char), shift_char(sh_char), finger_id(fing) {}

void Key::print() const 
{
    std::wcout << "Key(ID: " << id << ", Position: (" << position.first << ", " << position.second
                << "), Regular: '" << regular_char << "', Shift: '" << shift_char << "', Finger: "
                << finger_id << ")" << std::endl;
}
