
#include <array>
#include <iostream>
#include <vector>

struct TestCase {
  std::vector<int> commands;
  std::vector<std::vector<int>> obstacles;
  int expected;
};

TestCase testA() {
  TestCase obj;
  obj.commands = {4, -1, 3};
  obj.obstacles = {};
  obj.expected = 25;

  return obj;
}

TestCase testB() {
  TestCase obj;
  obj.commands = {4, -1, 4, -2, 4};
  obj.obstacles = {{2, 4}};
  obj.expected = 65;

  return obj;
}

TestCase testC() {
  TestCase obj;
  obj.commands = {6, -1, -1, 6};
  obj.obstacles = {};
  obj.expected = 36;

  return obj;
}

class Solution {
private:
  char direction(std::array<char, 4> &dir, int curr, int rightLeft) {
    if (rightLeft == -1)
      curr += 1;
    if (rightLeft == -2)
      curr -= 1;

    if (curr == 4)
      curr = 0;
    if (curr == -1)
      curr = 3;

    return curr;
  }

  void walking(std::pair<int, int> location, char direction, int distance) {
    switch (direction) {
    case 'n':
      location.second += distance;
      break;
    case 'e':
      location.first += distance;
      break;
    case 's':
      location.first -= distance;
      break;
    case 'w':
      location.second -= distance;
      break;
    }
  }

public:
  int robotSim(std::vector<int> &commands,
               std::vector<std::vector<int>> &obstacles) {
    std::array<char, 4> dir{'n', 'e', 's', 'w'};
    int point{0};
    std::pair<int, int> location{0, 0};

    for (int instruction : commands) {
      if (instruction < 0) {
        point = direction(dir, point, instruction);
      } else {
        walking(location, dir[point], instruction);
      }
    }

    return 0;
  }
};

int main() {
  TestCase test{testA()};
  Solution cursor = Solution();

  int output{cursor.robotSim(test.commands, test.obstacles)};
  if (output == test.expected)
    std::cout << "Success!\n" << std::endl;
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << test.expected << '\n';
    std::cout << "Actual: " << output << '\n';
  }

  return 0;
}
