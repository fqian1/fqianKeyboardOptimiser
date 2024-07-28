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
    std::unordered_map<char, int> charToKeyMap;
    std::unordered_map<int, int> keyToFingersMap;
    double score;

    Keyboard(std::wstring_view charLayout, const std::vector<Key>& keys, const std::vector<Finger>& fingers);

    double evaluate(const std::wstring_view text);
};
#endif
