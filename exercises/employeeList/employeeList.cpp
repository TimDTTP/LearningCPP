#include <iostream>
#include <string>

// possible positions in office
enum class Positions
{
    receptionist,
    dentalAssistant,
    dentalHygienist,
    radiologist,
    dentist,
};

// struct for program-defined type Employee
struct Employee
{
    std::string firstName{};
    std::string lastName{};
    std::string dob{};
    Positions pos{};
};

// function that prints employee attributes

int main()
{
    // loop asking for employee details
    bool end{ false };

    while (end != true)
    {
        // create Employee object
        // ask for first name
        // ask for last name
        // ask for dob
        // ask for position

        // reassign object name to  employee name
        // add attributes to object

        // add ENTIRE object to a list outside of loop
        
        // ask if user wants to continue
    }


    return 0;
}
