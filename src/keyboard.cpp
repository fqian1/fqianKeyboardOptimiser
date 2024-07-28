#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include "finger.h"
#include "key.h"
#include "keyboard.h"

Keyboard::Keyboard(std::string_view charLayout, const std::vector<Key>& keys, const std::vector<Finger>& fingers)
                  : charLayout(charLayout), keys(keys), fingers(fingers), score(0) 
{
    for(auto& key : keys)
    {
        charToKeyMap[key.regular_char] = key.id;
        charToKeyMap[key.shift_char] = key.id;
        keyToFingersMap[key.id] = key.finger_id;
    }
}

double Keyboard::evaluate(const std::string_view text)
{
    int score{0};
    bool currentFingers[8] {0};
    bool previousFingers[8] {0};

    for(char c : text)
    {
        std::copy(previousFingers, previousFingers + 8, currentFingers);
        std::fill(currentFingers, currentFingers + 8, 0);

        if(charToKeyMap.find(c) != charToKeyMap.end())
        {
            int keyId = charToKeyMap[c];
            int fingerId = keyToFingersMap[keyId];

            score += fingers[fingerId].press(keys[keyId]);// Will add more logic here, to handle shifts or undesirable movement


            currentFingers[fingerId] = 1;
            previousFingers[fingerId] = 0;// If finger was just used, don't return to home this iteration

            // Return fingers to home after 1 iteration delay
            for(bool previousFinger : previousFingers)
            {
                if(previousFinger == true)
                {
                    fingers[fingerId].returnToHome();
                }
            }
        }
    }
    return score;
}