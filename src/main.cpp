#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <codecvt>
#include "keyboard.h"
#include "finger.h"
#include "key.h"

std::vector<Finger> initFingers()
{
    std::vector<Finger> fingers;
    fingers.push_back(Finger(0, std::pair<double, double>(2.25, 2.25), 0.6)); 
    fingers.push_back(Finger(1, std::pair<double, double>(3.25, 2.25), 0.8)); 
    fingers.push_back(Finger(2, std::pair<double, double>(4.25, 2.25), 1)); 
    fingers.push_back(Finger(3, std::pair<double, double>(5.25, 2.25), 0.8)); 
    fingers.push_back(Finger(4, std::pair<double, double>(6.25, 2.25), 0.8)); 
    fingers.push_back(Finger(5, std::pair<double, double>(7.25, 2.25), 1)); 
    fingers.push_back(Finger(6, std::pair<double, double>(8.25, 2.25), 0.8)); 
    fingers.push_back(Finger(7, std::pair<double, double>(9.25, 2.25), 0.6)); 
    return fingers;
}

std::vector<Key> initKeys(std::wstring_view sv)
{
    std::vector<Key> keys;

    double rowOffsets[4] {0, 1.5, 1.75, 0.25};
    int rowKeyAmount[4] {13, 12, 12, 13};
    int fingerAssignments [4][14] ={
    { 0, 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7 },
        { 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7 },
        { 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7 },
    { 0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7 }};

    int keyId {0};
    for(int row{0}; row < 4; row++)
    {
        double y {row + 0.5};
        for (int col{0}; col < rowKeyAmount[row]; col++)
        {
            double x{col + 0.5 + rowOffsets[row]};
            int fingerId{fingerAssignments[row][col]};
            if(row == 3 && col == 0 )
            {
                keys.push_back(Key(keyId, std::pair<double, double>(x, y), '←', '←', fingerAssignments[row][col]));
            }
            else if(row == 3 && col == 12)
            {
                keys.push_back(Key(keyId, std::pair<double, double>(x, y), '→', '→',  fingerAssignments[row][col]));
            }
            else
            {
                keys.push_back(Key(keyId, std::pair<double, double>(x, y), sv[keyId], sv[keyId + 48], fingerAssignments[row][col]));
            }
            keyId++;
        }
    }
    return keys;
}

 int main()
 {
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wstring charLayout = LR"(`1234567890-=qwertyuiop[]asdfghjkl;'#\zxcvbnm,./¬!"£$%^&*()_+QWERTYUIOP{}ASDFGHJKL:@~|ZXCVBNM<>?)"; //qwerty
    std::wstring_view sv{charLayout};

    std::vector<Key> keys {initKeys(sv)};
    std::vector<Finger> fingers {initFingers()};

    for(auto& key : keys)
    {
        key.print();
    }
    return 0;
 } 