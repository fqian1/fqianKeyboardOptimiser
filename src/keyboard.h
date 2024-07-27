#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <unordered_map>
#include "key.h"
#include "finger.h"



class Keyboard
{
public: 
    std::string_view charLayout;
    std::vector<Key> keys;
    std::vector<Finger> fingers;
    std::unordered_map<char, int> charToKeyMap;
    std::unordered_map<int, std::vector<int>> keyToFingersMap;
    double score;

    Keyboard(std::string_view charLayout, const std::vector<Key>& keys, const std::vector<Finger>& fingers)
            : charLayout(charLayout), keys(keys), fingers(fingers), score(0) 
    {
    
    }
};
#endif
