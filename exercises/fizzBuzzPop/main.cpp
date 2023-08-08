#include <iostream>
#include <string>
#include <iterator> // std::size()
#include <cassert> // for assert()

int main()
{
    constexpr int divisor[]{ 3, 5, 7, 11, 13, 17, 19 };
    constexpr std::string_view divisorWord[]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    // assert length of arrays are equal
    static_assert((std::size(divisor)) == (std::size(divisorWord)), "Length of divisor and words are unequal");

    // loop through 1-150
    for (int range{ 1 }; range <= 150; ++range)
    {
        bool check{false};
        // loop through divisor
        for (int divisorIndex{ 0 }; divisorIndex < std::size(divisor); ++divisorIndex)
        {
            // checks if range value is evenly divisible by divisor
            if (range % divisor[divisorIndex] == 0)
            {
                check = true;
                std::cout << divisorWord[divisorIndex]; // print word associated with divisor
            }
        }

        // if number is not divisible, print number
        if (check == false)
            std::cout << range;

        // next number
        std::cout << '\n';
    }

    return 0;
}