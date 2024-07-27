#include <vector>
#include <unordered_map>
#include <string>
#include "finger.h"
#include "key.h"

class Keyboard
{
public: 
    std::vector<Key> keys;
    std::unordered_map<char, Key> charToKeyMap;
    std::vector<Finger> fingers;
    double score;

    Keyboard(const std::vector<Key> &keys, const std::vector<Finger> fingers, const std::unordered_map<char, Key> &charToKeyMap) 
            : keys(keys), fingers(fingers), charToKeyMap(charToKeyMap), score(0) {}
    


    void intialiseKeys(std::string str)
    {
        int offsets[4] {0, 1.5, 1.75, 1.25};
        int rowKeyAmount[4] {14, 12, 12, 11};
        int fingerAssignments [4][14] ={
        { 0, 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 7 },
        { 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7},
        { 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7},
        { 0, 1, 2, 3, 3, 4, 4, 4, 5, 6, 7}};
        int keyId {0};

        for(int row = 0; row < 4; row++)
        {
            double y = row + 0.5;
            for (int col = 0; col < rowKeyAmount[row]; col++)
            {
                double x = 0.5 + col + offsets[row];
                int fingerId = fingerAssignments[row][col];
                keys.push_back({keyId, x, y, fingerId});
                //charToKeyMap[str[0]] = str[0] == '\n' ? Key key: keys.back();
                keyId++;
            } 
        }
    }

    void initialiseFingers()
    {
        fingers.push_back(Finger(0, 0, 2.25, 2.25, 0.6));
        fingers.push_back(Finger(1, 0, 3.25, 2.25, 0.8));
        fingers.push_back(Finger(2, 0, 4.25, 2.25, 1));
        fingers.push_back(Finger(3, 0, 5.25, 2.25, 0.8));
        fingers.push_back(Finger(4, 1, 8.25, 2.25, 0.6));
        fingers.push_back(Finger(5, 1, 9.25, 2.25, 0.8));
        fingers.push_back(Finger(6, 1, 10.25, 2.25, 1));  
        fingers.push_back(Finger(7, 1, 11.25, 2.25, 0.8));
    }
};