
#include <algorithm> // for std::sort
#include <array> // for std::array
#include <string> // for std::string
#include <vector> // for std::vector
#include <iostream>

struct Student
{
    std::string name{};
    int grade{};
};


Student inputFcn(int i)
{
    Student temp{};
    std::cout << "Enter name: ";
    std::cin >> temp.name;

    temp.grade = i;

    return temp;
}


bool sortGradeDescending(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}


int main()
{
    std::vector<Student> vStudent(5);
    
    for (int i{ 0 }; i < 5; ++i)
    {
        vStudent[i] = inputFcn(i);
    }

    // test array
    /*
    std::array<int, 5> nums{ 5, 19, 83, 23, 4 };
    std::sort(nums.begin(), nums.end());
    for (auto i : nums)
    {
        std::cout << "Test array: " << i << '\n';
    }
    */

    // sort
    std::sort(vStudent.begin(), vStudent.end(), sortGradeDescending);

    for (int i{ 0 }; auto student : vStudent)
    {
        std::cout << "Name: " << vStudent[i].name << '\n'
                  << "Grade: " << vStudent[i].grade << "\n\n";

        ++i;
    }

    return 0;
}