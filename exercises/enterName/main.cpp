#include <iostream>

// function that inputs a name and returns the name to main()

// function prints array (loop)

int main()
{
    // ask user for number of names
    std::cout << "How many names would you like to enter? ";
    int lenNames{};
    std::cin >> lenNames;

    // loops for next name + add to array
    for (int i{ 0 }; i < lenNames; ++i)
    {
        std::cout >> i >> '\n';
    }

    return 0;
}