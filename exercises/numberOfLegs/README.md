
# Problem

LearnCPP Chapter 10.4 exercise #1

Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck. Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for that animal as a std::string_view (or std::string if you’re using C++14). Write another function named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on. Make sure both functions have a default case that prints an error message. Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:

A cat has 4 legs.
A chicken has 2 legs.