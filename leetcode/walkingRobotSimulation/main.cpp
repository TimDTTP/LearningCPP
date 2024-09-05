
#include <array>
#include <iostream>
#include <set>
#include <unordered_map>
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
  std::unordered_map<int, std::set<int>> obsCoord{};

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

  // dictionary of obstacles per axis basis
  void occupyMap(std::vector<std::vector<int>> obstacles) {
    for (std::vector<int> coordinates : obstacles) {
      obsCoord[coordinates[0]].insert(coordinates[1]);
    }
  }

  // obstacle checking
  bool obstacleCheck(int x, int y) {
    return (obsCoord[x].find(y) != obsCoord[x].end());
  }

  void walking(std::pair<int, int> &location, char direction, int distance) {
    int uninterferedDistance{0};

    switch (direction) {
    case 'n':
      for (int i = 1; i <= distance; ++i) {
        if (!obstacleCheck(location.first, location.second + i)) {
          ++uninterferedDistance;
        } else
          break;
      }
      location.second += uninterferedDistance;

      break;
    case 'e':
      for (int i = 1; i <= distance; ++i) {
        if (!obstacleCheck(location.first + i, location.second)) {
          ++uninterferedDistance;
        } else
          break;
      }
      location.first += uninterferedDistance;

      break;
    case 's':
      for (int i = 1; i <= distance; ++i) {
        if (!obstacleCheck(location.first, location.second - i)) {
          ++uninterferedDistance;
        } else
          break;
      }
      location.second -= uninterferedDistance;

      break;
    case 'w':
      for (int i = 1; i <= distance; ++i) {
        if (!obstacleCheck(location.first - i, location.second)) {
          ++uninterferedDistance;
        } else
          break;
      }
      location.first -= uninterferedDistance;

      break;
    }
  }

public:
  int robotSim(std::vector<int> &commands,
               std::vector<std::vector<int>> &obstacles) {
    std::array<char, 4> dir{'n', 'e', 's', 'w'};
    int point{0};
    std::pair<int, int> location{0, 0};
    int distance{0};
    int maxDistance{0};

    // map obstacle coordinates
    occupyMap(obstacles);

    // loop through each command
    for (int instruction : commands) {
      if (instruction < 0) {
        point = direction(dir, point, instruction);
      } else {
        walking(location, dir[point], instruction);
        distance = (pow(location.first, 2) + pow(location.second, 2));
        maxDistance = std::max(maxDistance, distance);
      }
    }

    return maxDistance;
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
