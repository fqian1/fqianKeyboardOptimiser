#include "iostream"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    bool currentIds[8] {0};
    bool prevIds[8] {0};

    for(int i{0}; i < 100; i++)
    {
        int rng = rand() % 8;

        std::copy(currentIds, currentIds + 8, prevIds);
        std::fill(currentIds, currentIds + 8, 0);

        currentIds[rng] = !currentIds[rng];

        std::cout << "Current Ids: [ ";
        for(bool id : currentIds)
        {
            std::cout << id << " ";
        }
        std::cout << "]\n";
        std::cout << "Prev Ids:    [ ";
        for(bool id : prevIds)
        {
            std::cout << id << " ";
        }
        std::cout << "]\n\n";
    }
    return 0;
}