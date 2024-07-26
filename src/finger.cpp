class Finger 
{
public:
    Finger(int dexterity) : distance_traveled(0), is_pressing(false), dexterity(dexterity), x(0), y(0) {}

    void pressKey(const Key& key, bool already_pressed) 
    {
        double distance = calculateDistance(key);
        if (!already_pressed) 
        {
            distance_traveled += distance / dexterity; // Example calculation
        } else 
        {
            distance_traveled += (distance / dexterity) * 1.5; // Penalty for already pressed key
        }
        x = key.getX();
        y = key.getY();
        is_pressing = true;
    }

    void releaseKey() 
    {
        is_pressing = false;
    }

    double getDistanceTraveled() const 
    {
        return distance_traveled;
    }

    bool isPressing() const 
    {
        return is_pressing;
    }

private:
    double distance_traveled;
    bool is_pressing;
    int dexterity;
    double x, y; // Current position of the finger

    double calculateDistance(const Key& key) {
        return std::sqrt(std::pow(key.getX() - x, 2) + std::pow(key.getY() - y, 2));
    }
};
