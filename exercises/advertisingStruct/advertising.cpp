#include <iostream>

// ad struct with 3 members
struct Advertisement
{
    int adsShown{};
    double percentOfClicks{};
    double pricePerClick{};
};

// function that asks for input of 3 values
Advertisement userInput()
{
    static Advertisement input{};

    std::cout << "How many ads were shown?\n";
    std::cin >> input.adsShown;
    std::cout << std::endl;

    std::cout << "What is the percentage of people who clicked on the ad?\n";
    std::cin >> input.percentOfClicks;
    std::cout << std::endl;

    std::cout << "How much, on average, was made per click? (USD)\n";
    std::cin >> input.pricePerClick;
    std::cout << std::endl << '\n';

    return input;
}

// function that prints daily average of all 3 numbers and total daily revenue
void printValues(const Advertisement& input)
{
    std::cout << "# of ads: " << input.adsShown << '\n';
    std::cout << "Click through rate: " << input.percentOfClicks << "%\n";
    std::cout << "Average made per ad: " << input.pricePerClick << '\n' << '\n';
    std::cout << "Total made today: $" << (input.adsShown
                                         * (input.percentOfClicks / 100)
                                         * input.pricePerClick)
                                         << '\n' << '\n'; 
}

int main()
{
    Advertisement ad{ userInput() };
    printValues( ad );

    return 0;
}