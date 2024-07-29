#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <unordered_map>
#include "key.h"
#include "finger.h"

class Keyboard
{
public: 
    std::wstring_view charLayout;
    std::vector<Key> keys;
    std::vector<Finger> fingers;
    std::unordered_map<wchar_t, int> charToKeyMap;
    std::unordered_map<int, int> keyToFingersMap;
    double score;
    std::wstring fingerNames[8] {
        L"Left_Pinky",
        L"Left_Ring",
        L"Left_Middle",
        L"Left_Index",
        L"Right_Index",
        L"Right_Middle",
        L"Right_Ring",
        L"Right_Pinky"};

    Keyboard(std::wstring_view charLayout, const std::vector<Key>& keys, const std::vector<Finger>& fingers);

    double evaluate(const std::wstring_view text);
};
#endif
