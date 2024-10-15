
#include <iostream>
#include <string>

class Solution {
public:
  long long minimumSteps(std::string s) {
    int blackBalls{0};
    long long moveCounter{0};

    // traverse string
    for (char ball : s) {
      switch (ball) {
      case '0':
        moveCounter += blackBalls;
        break;
      case '1':
        blackBalls++;
      }
    }

    return moveCounter;
  }
};

int main() {
  Solution solCur = Solution();

  std::string input{"011"};
  long long output{solCur.minimumSteps(input)};
  std::cout << output << std::endl;

  return 0;
}
