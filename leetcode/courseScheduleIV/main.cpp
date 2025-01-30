
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Test {
public:
  struct TestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisite;
    std::vector<std::vector<int>> queries;
    std::vector<bool> output;
  };

  TestCase testA() {
    TestCase obj;
    obj.numCourses = 2;
    obj.prerequisite = {{1, 0}};
    obj.queries = {{0, 1}, {1, 0}};
    obj.output = {false, true};
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.numCourses = 2;
    obj.prerequisite = {};
    obj.queries = {{1, 0}, {0, 1}};
    obj.output = {false, false};
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.numCourses = 3;
    obj.prerequisite = {{1, 2}, {1, 0}, {2, 0}};
    obj.queries = {{1, 0}, {1, 2}};
    obj.output = {true, true};
    return obj;
  }
};

class Solution {
public:
  std::vector<bool>
  checkIfPrerequisite(int numCourses,
                      std::vector<std::vector<int>> &prerequisite,
                      std::vector<std::vector<int>> &queries) {
    // consolidate the prerequisite list
    std::unordered_map<int, std::unordered_set<int>> table{};
    for (std::vector<int> i : prerequisite) {
      table[i[1]].insert(i[0]);
    }

    // iterate through query and DFS to search
    std::vector<bool> out(queries.size());
    std::stack<int> check{};
    int temp;
    for (int pattern{0}; pattern < queries.size(); ++pattern) {
      // initial push of numbers into stack
      for (int i : table[queries[pattern][1]]) {
        check.push(i);
      }

      // DFS
      while (!check.empty()) {
        if (check.top() == queries[pattern][0]) {
          out[pattern] = true;
          break;
        } else {
          temp = check.top();
          check.pop();
          // push children into stack
          for (int i : table[temp]) {
            check.push(i);
          }
        }
      }
    }

    return out;
  }
};

void printVector(std::vector<bool> input) {
  for (bool i : input) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<bool> output{solCur.checkIfPrerequisite(
      unit.numCourses, unit.prerequisite, unit.queries)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    printVector(unit.output);
    std::cout << "Actual: ";
    printVector(output);
  }
  std::cout << std::endl;

  return 0;
}
