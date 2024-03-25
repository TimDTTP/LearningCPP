
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student {
  std::string name{};
  int points{};
};

bool isGreater(Student i, Student j) { return (i.points < j.points); }

int main() {
  // array copied from problem
  std::array<Student, 8> arr{{{"Albert", 3},
                              {"Ben", 5},
                              {"Christine", 2},
                              {"Dan", 8}, // Dan has the most points (8).
                              {"Enchilada", 4},
                              {"Francis", 1},
                              {"Greg", 3},
                              {"Hagrid", 5}}};

  std::string mostPoints{
      (*std::max_element(arr.begin(), arr.end(), isGreater)).name};

  std::cout << mostPoints << " is the best student" << '\n';

  return 0;
}
