#include <vector>
#include <unordered_map>
#include <string>
#include "finger.h"
#include "key.h"
#include "keyboard.h"

class Keyboard
{
public: 
    std::string_view charLayout;
    std::vector<Key> keys;
    std::vector<Finger> fingers;
    std::unordered_map<char, int> charToKeyMap;
    std::unordered_map<int, int> keyToFingersMap;
    double score;

    Keyboard(const std::vector<Key>& keys, const std::vector<Finger>& fingers)
            : keys(keys), fingers(fingers), score(0) 
    {
        for(auto& key : keys)
        {
            charToKeyMap[key.regular_char] = key.id;
            charToKeyMap[key.shift_char] = key.id;
            keyToFingersMap[key.id] = key.finger_id;
        }
    }

    int evaluate(const std::string_view text)
    {
        int score{0};
        for(char c : text)
        {
            int keyId = charToKeyMap['c'];
            int fingerId = keyToFingersMap[keyId];
            fingers[fingerId].press(keys[keyId]);
        }
        return score;
    }
};