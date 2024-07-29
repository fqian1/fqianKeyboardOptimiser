#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include "finger.h"
#include "key.h"
#include "keyboard.h"

Keyboard::Keyboard(std::wstring_view charLayout, const std::vector<Key>& keys, const std::vector<Finger>& fingers)
                  : charLayout(charLayout), keys(keys), fingers(fingers), score(0) 
{
    for(auto& key : keys)
    {
        charToKeyMap[key.regular_char] = key.id;
        charToKeyMap[key.shift_char] = key.id;
        keyToFingersMap[key.id] = key.finger_id;
    }
}

double Keyboard::evaluate(const std::wstring_view text)
{
    // the score depends on how far the finger has to move
    std::wcout.imbue(std::locale());
    double score{0};
    bool currentFingers[8] {0};
    bool previousFingers[8] {0};

    for(wchar_t c : text)
    {
        // copy last iterations current fingers into previous fingers queue
        std::copy(currentFingers, currentFingers + 8, previousFingers);
        // reset current fingers queue for this iteration
        std::fill(currentFingers, currentFingers + 8, 0);

        if(charToKeyMap.find(c) != charToKeyMap.end())
        {
            int keyId = charToKeyMap[c];
            int fingerId = keyToFingersMap[keyId];

            // press the assigned finger and tally up the score, set status to current finger
            std::wcout << "keyboard score: " << std::to_wstring(score) << "\n";
            score += fingers[fingerId].press(keys[keyId]);
            currentFingers[fingerId] = 1;

            // shift positions of adjacent fingers in same direction as active finger
            std::pair<double, double> smallShiftAmount{std::pair<double, double>(0, keys[keyId].position.second / 2)};
            std::pair<double, double> largeShiftAmount{std::pair<double, double>(0, keys[keyId].position.second)};
            switch(fingerId)
            {
            case 0:
                fingers[1].moveToPos(largeShiftAmount);
                fingers[2].moveToPos(smallShiftAmount);
                std::fill(currentFingers, currentFingers + 3, 1);
                break;
            case 1:
                fingers[0].moveToPos(smallShiftAmount);
                fingers[2].moveToPos(smallShiftAmount);
                std::fill(currentFingers, currentFingers + 3, 1);
                break;
            case 2:
                fingers[0].moveToPos(smallShiftAmount);
                fingers[1].moveToPos(largeShiftAmount);
                std::fill(currentFingers, currentFingers + 3, 1);
                break;
            case 5:
                fingers[6].moveToPos(largeShiftAmount);
                fingers[7].moveToPos(smallShiftAmount);
                std::fill(currentFingers + 5, currentFingers + 8, 1);
                break;
            case 6:
                fingers[5].moveToPos(smallShiftAmount);
                fingers[7].moveToPos(smallShiftAmount);
                std::fill(currentFingers + 5, currentFingers + 8, 1);
                break;
            case 7:
                fingers[6].moveToPos(largeShiftAmount);
                fingers[5].moveToPos(smallShiftAmount);
                std::fill(currentFingers + 5, currentFingers + 8, 1);
                break;
            }

            std::wcout << L"Letter: " << c << L" was typed\n";
            std::wcout << L"Key : ";
            keys[keyId].print();
            // if key is shift key, get pinky to press shift button on opposite side
            if(!keys[keyId].isRegular(c))
            {
                if(fingerId > 3)
                {
                    fingers[0].moveToKey(keys[charToKeyMap[L'→']]);
                    currentFingers[0] = 1;
                    std::wcout << L"Left shift pressed\n";
                }
                else
                {
                    fingers[7].moveToKey(keys[charToKeyMap[L'←']]);
                    currentFingers[7] = 1;
                    std::wcout << L"Right shift pressed\n";
                }
            }
            std::wcout << L"Finger: " << fingerNames[fingerId] << L" was pressed\n";

            // if a finger has just moved (is in current finger), remove it from the previous finger queue if it belongs in it
            for(int i{0}; i < 8; i ++)
            {
                if(currentFingers[i] == 1 && previousFingers[i] == 1)
                {
                    previousFingers[i] = 0;
                }
            }

            // Return fingers to home after 1 iteration delay (if it is in prev fingers queue)
            for(int i{0}; i < 8; i++)
            {
                if(previousFingers[i])
                {
                    fingers[i].returnToHome();
                    std::wcout << fingerNames[i] << L" returned back to home" << "\n";
                }
            }
        }
        std::cout << "\n";
    }
    return score;
}