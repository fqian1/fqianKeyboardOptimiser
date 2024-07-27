#include <vector>
#include <unordered_map>
#include <string>
#include "finger.h"
#include "key.h"

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
            : charLayout(charLayout), keys(keys), fingers(fingers), score(0) {
            for(const auto& key: keys)
            {
                if(std::holds_alternative<int>(key.finger_ids))
                {
                    keyToFingersMap[key.id].push_back(std::get<int>(key.finger_ids));
                }
                else
                {
                    auto fingerPair = std::get<std::pair<int, int>>(key.finger_ids);
                    keyToFingersMap[key.id].push_back(fingerPair.first);
                    keyToFingersMap[key.id].push_back(fingerPair.second);
                }
            }}
    
    constexpr void intialiseKeys(std::string_view sv)
    {
        int rowOffsets[4] {0, 1.5, 1.75, 0.25};
        int rowKeyAmount[4] {13, 12, 12, 13};
        int fingerAssignments [4][14] ={
        { 0, 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7 },
           { 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7 },
           { 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7 },
        { 0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7 }};
        int keyId {0};

        for(int row = 0; row < 4; row++)
        {
            double y = row + 0.5;
            for (int col = 0; col < rowKeyAmount[row]; col++)
            {
                double x = col + 0.5 + rowOffsets[row];
                int fingerId = fingerAssignments[row][col];
                keys.push_back({keyId, x, y, fingerId});
                charToKeyMap[sv[keyId]] = keys.back();
                keyId++;
            } 
        }
    }


};