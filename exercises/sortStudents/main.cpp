#include <iostream>
#include <string> // for std::string
#include <vector> // for std::vector

// struct for User type student
struct Student
{
    std::string name{};
    int grade{};
};


// function to handle excess string in std::cin buffer
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// function for user input
Student clientInput()
{
    // get name
    Student student{};
    std::cout << "Enter the student's name: ";
    std::cin >> student.name;

    // verify std::cin success
    if (!std::cin)
    {
        if (std::cin.eof())
            exit(0);

        std::cin.clear();
        ignoreLine();
    }
    else
        ignoreLine();

    // verify value is within range
    if (student.grade < 0 || student.grade > 100)
    {

    }

    // get grade 
    do
    {
        // get grade
        getGrade:
        std::cout << "Enter the student's grade: ";
        std::cin >> student.grade;

        // verify std::cin success
        if (!std::cin)
        {
            if (std::cin.eof())
                exit(0);

            std::cin.clear();
            ignoreLine();

            // let user know it failed and redo
            std::cout << "Invalid grade input!\n\n";
            goto getGrade; // jumps within scope
        }
        else
            ignoreLine();

    }
    while (student.grade < 0 || student.grade > 100);

    std::cout << '\n';

    return student;
}


// function to sort vector
bool sortGradeDescending(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}


// function to print vector
void printVector(const std::vector<Student>& vec)
{
    for (auto i : vec)
        std::cout << i.name << " got a grade of " << i.grade << '\n';
}


int main()
{
    // ask for vector size
    int numberStudents{};
    std::cout << "How many students are there?\n";
    std::cin >> numberStudents;

    // verify std::cin success
    if (!std::cin)
    {
        if (std::cin.eof())
            exit(0);

        std::cin.clear();
        ignoreLine();
    }
    else
        ignoreLine();

    // create vector with preset size
    std::vector<Student> vStudents( numberStudents );

    // loop x amount; user input -> vector
    for (int i{ 0 }; i < numberStudents; ++i)
    {
        vStudents[i] = clientInput();
    }

    // sort vector
    std::sort(vStudents.begin(), vStudents.end(), sortGradeDescending);

    // print
    printVector(vStudents);

    return 0;
}