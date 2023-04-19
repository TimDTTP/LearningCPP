#include <iostream>
#include "constants.h"

// calculation function of current height
double currentHeight(int initialHeight, int fallTime)
{
    // x = (1/2)at^2
    double fallDistance { initialHeight - ((myConstants::gravity * (fallTime * fallTime)) / 2) };

    return( fallDistance );
}

// while loop that prints current height
void printHeight(int initialHeight)
{
    int fallTime{ 0 };

    while (currentHeight(initialHeight, fallTime) > 0)
    {
        std::cout << "At " << fallTime << " seconds, the ball is at height: " << currentHeight(initialHeight, fallTime) << '\n';
        ++fallTime;
    }

    std::cout << "At " << fallTime << " seconds, the ball is on the ground." << '\n';
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    int initialHeight{ };
    std::cin >> initialHeight;

    printHeight(initialHeight);

    return 0;
}