#include <array>
#include <iostream>

// enum to list items
enum class Items
{
    health_potion,
    torch,
    arrow,
};


// fcn returns how many items
// pass as const ref because std::array does not decay
int countTotalItems(const std::array<int, 3>& ItemQuantity)
{
    int total{};
    for (auto i : ItemQuantity)
    {
        total += i;
    }

    return total;
}


int main()
{
    // array to hold number of each item
    std::array<int, 3> ItemQuantity{ 2, 5, 10 };

    // print how many items TOTAL
    std::cout << "The total number of items being carried:\n"
              << countTotalItems(ItemQuantity)
              << "\n\n";

    // prints how many torches
    std::cout << "Torches: " << ItemQuantity[static_cast<int>(Items::torch)] << '\n';

    return 0;
}


/*
Possible improvements:
- Prefix item in enum with "item_" for better readability
- Instead of a loop to count total items, it is more efficient to use std::reduce in <numeric>
*/