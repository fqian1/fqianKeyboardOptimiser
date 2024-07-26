#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <finger.cpp>

struct Key
{
    int id;
    double x, y;
    int fingerId;
};

class Keyboard
{
public: 
    std::vector<Key> keys;
    std::unordered_map<char, Key> charToKeyMap;
    std::vector<Finger> fingers;
    // etc.
};