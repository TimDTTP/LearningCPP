
#include <array>
#include <vector>

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

int main() { return 0; }
