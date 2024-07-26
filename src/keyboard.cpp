#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>

struct Key {
    char id;
    double x;
    double y;
    int assigned_finger;

    Key(char id, double x, double y, int assigned_finger)
        : id(id), x(x), y(y), assigned_finger(assigned_finger) {}
};


class Keyboard {
public:
    Keyboard() {
        initializeKeys();
    }

    Key getKey(char id) {
        return keys[id];
    }

private:
    std::unordered_map<char, Key> keys;

    void initializeKeys() {
        // Row 1
        double x = 0.0;
        for (char c = 'Q'; c <= 'P'; ++c, x += 1.0) {
            keys[c] = Key(c, x, 0.0, getFingerForKey(c));
        }

        // Row 2
        x = 1.5;
        for (char c = 'A'; c <= 'L'; ++c, x += 1.0) {
            keys[c] = Key(c, x, 1.0, getFingerForKey(c));
        }

        // Row 3
        x = 1.75;
        for (char c = 'Z'; c <= 'M'; ++c, x += 1.0) {
            keys[c] = Key(c, x, 2.0, getFingerForKey(c));
        }

        // Row 4
        x = 1.25;
        std::string row4 = "SHIFTZXCVBNM";
        for (char c : row4) {
            keys[c] = Key(c, x, 3.0, getFingerForKey(c));
            x += 1.0;
        }
    }

    int getFingerForKey(char key) {
        // Map keys to fingers (example mapping)
        if (key == 'Q' || key == 'A' || key == 'Z') return 0;  // Left pinky
        if (key == 'W' || key == 'S' || key == 'X') return 1;  // Left ring finger
        if (key == 'E' || key == 'D' || key == 'C') return 2;  // Left middle finger
        if (key == 'R' || key == 'T' || key == 'F' || key == 'G' || key == 'V') return 3;  // Left index finger
        if (key == 'Y' || key == 'U' || key == 'H' || key == 'J' || key == 'B' || key == 'N') return 6;  // Right index finger
        if (key == 'I' || key == 'K' || key == 'M') return 7;  // Right middle finger
        if (key == 'O' || key == 'L') return 8;  // Right ring finger
        if (key == 'P') return 9;  // Right pinky
        return 4;  // Right thumb for space, etc.
    }
};
