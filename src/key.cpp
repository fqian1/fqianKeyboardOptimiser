class Key 
{
public:
    Key(double x, double y, int finger) : x(x), y(y), assigned_finger(finger) {}

    double getX() const { return x; }
    double getY() const { return y; }
    int getAssignedFinger() const { return assigned_finger; }

private:
    double x, y; // Position of the key on the keyboard
    int assigned_finger; // Finger assigned to this key
};
