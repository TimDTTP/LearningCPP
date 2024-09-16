
#include <iostream>
#include <string>
#include <vector>

class Tests {
public:
  struct testCase {
    std::vector<std::string> input;
    int output;
  };

  testCase testA() {
    testCase obj;
    obj.input = {"23:59", "00:00"};
    obj.output = 1;

    return obj;
  }

  testCase testB() {
    testCase obj;
    obj.input = {"00:00", "23:59", "00:00"};
    obj.output = 0;

    return obj;
  }
};

class Solution {
private:
  const int minInHour{60};
  const int hourInDay{24};

  int shortestPath(int base, int cmp) {
    int greater{std::max(base, cmp)};
    int lesser{std::min(base, cmp)};

    int path{greater - lesser};

    if (path > (minInHour * (hourInDay / 2))) {
      path = (((hourInDay * minInHour) - greater) + lesser);
    }

    return path;
  }

public:
  int findMinDifference(std::vector<std::string> &timePoints) {

    // convert time points into flat integers
    int hours, minutes;
    std::vector<int> pointInMins;
    int temp;
    for (std::string time : timePoints) {
      hours = std::stoi(time.substr(0, 2));
      minutes = std::stoi(time.substr(3, 5));
      temp = (hours * minInHour) + minutes;
      pointInMins.push_back(temp);
    }

    int minPath{hourInDay * minInHour};
    for (int base{0}; base < timePoints.size(); ++base) {
      for (int comp{base + 1}; comp < timePoints.size(); ++comp) {
        minPath = std::min(minPath,
                           shortestPath(pointInMins[base], pointInMins[comp]));
      }
    }

    return minPath;
  }
};

class OnlineSolution {
private:
  const int minInHour{60};
  const int hourInDay{24};

  int shortestPath(int base, int cmp) {
    int greater{std::max(base, cmp)};
    int lesser{std::min(base, cmp)};

    int path{greater - lesser};

    if (path > (minInHour * (hourInDay / 2))) {
      path = (((hourInDay * minInHour) - greater) + lesser);
    }

    return path;
  }

public:
  int findMinDifference(std::vector<std::string> &timePoints) {

    // convert time points into flat integers
    int hours, minutes;
    std::vector<int> pointInMins;
    int temp;
    for (std::string time : timePoints) {
      hours = std::stoi(time.substr(0, 2));
      minutes = std::stoi(time.substr(3, 5));
      temp = (hours * minInHour) + minutes;
      pointInMins.push_back(temp);
    }

    // sort vector
    // in acending order
    std::sort(pointInMins.begin(), pointInMins.end());

    int minPath{hourInDay * minInHour};
    for (int base{0}; base < pointInMins.size() - 1; ++base) {
      minPath = std::min(
          minPath, shortestPath(pointInMins[base], pointInMins[base + 1]));
    }
    minPath =
        std::min(minPath, shortestPath(pointInMins[0],
                                       pointInMins[pointInMins.size() - 1]));

    return minPath;
  }
};

int main() {
  Tests testCur = Tests();
  OnlineSolution solCur = OnlineSolution();

  Tests::testCase test{testCur.testA()};

  int output{solCur.findMinDifference(test.input)};

  if (output == test.output)
    std::cout << "Success!\n" << std::endl;
  else {
    std::cout << "Fail!\n";
    std::cout << output << '\n' << std::endl;
  }

  return 0;
}
