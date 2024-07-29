#include <iostream>
#include <vector>
#include "key.h"

Key::Key(int id, std::pair<double, double> pos, wchar_t reg_char, wchar_t sh_char, int fing)
        : id(id), position(pos), regular_char(reg_char), shift_char(sh_char), finger_id(fing) {}

void Key::print() const 
{
    std::wcout << L"Key(ID: " << id << L", Position: (" << position.first << L", " << position.second
                << L"), Regular: '" << regular_char << L"', Shift: '" << shift_char << L"', Finger: "
                << finger_id << L")" << std::endl;
}

bool Key::isRegular(wchar_t c) const
{
    return c == regular_char ? true : false;
}
