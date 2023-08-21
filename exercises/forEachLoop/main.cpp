#include <iostream>
#include <string>


int main()
{
    std::string_view names[]{ "Alex",
                              "Betty",
                              "Caroline",
                              "Dave",
                              "Emily",
                              "Fred",
                              "Greg",
                              "Holly" };

    // ask for user input
    std::cout << "Enter a name: ";
    std::string clientInput{};
    std::cin >> clientInput;

    bool inArray{ false };

    for (const auto& name : names)
    {
        if (clientInput == name)
        {
            std::cout << clientInput << " was found.\n";
            inArray = true;
        }
    }

    // if not in array print
    if (inArray == false)
        std::cout << clientInput << " was not found.\n";

    return 0;
}