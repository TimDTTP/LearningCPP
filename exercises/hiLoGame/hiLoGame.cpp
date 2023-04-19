#include <iostream>
#include <random>
#include <limits>

// random function
int randomNum()
{
    std::random_device rd;
    std::seed_seq ss { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };

    std::mt19937 mt{ ss };

    std::uniform_int_distribution num{ 1, 100 };

    return num(mt);
}

// inputs
int guess(int attempt)
{
    int userInput{ };
    std::cout << "Guess #" << attempt << ": ";
    std::cin >> userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return userInput;
}

void game(int target)
{
    for (int i{ 1 }; i <= 7; ++i)
        {
            int userGuess{ guess(i) };

            if (userGuess < target)
            {
                std::cout << "Your guess is too low.\n";
                continue;
            }
            if (userGuess > target)
            {
                std::cout << "Your guess is too high.\n";
                continue;
            }
            if (userGuess == target)
            {
                std::cout << "Correct! You win!\n";
                break;
            }
            else
            {
                std::cout << "Sorry, you lose. The correct number was " << target << '\n';
                break;
            }
        }
}

bool continuation()
{
    char yesNo{ };
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> yesNo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } 
    while (yesNo != 'y' && yesNo != 'n');

    bool userDecision{ };
    if (yesNo == 'y')
        userDecision = true;
    if (yesNo == 'n')
        userDecision = false;

    return userDecision;
}

int main()
{
    do
    {
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    
        // random number
        int target{ randomNum() };


        // input
        game(target);
    }
    while (continuation());

    return 0;
}