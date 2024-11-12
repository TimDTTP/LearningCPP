
#include <iostream>
#include <unordered_map>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> items;
    std::vector<int> queries;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj;
    obj.items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    obj.queries = {1, 2, 3, 4, 5, 6};
    obj.output = {2, 4, 5, 5, 6, 6};
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.items = {{1, 2}, {1, 2}, {1, 3}, {1, 4}};
    obj.queries = {1};
    obj.output = {4};
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.items = {{10, 1000}};
    obj.queries = {5};
    obj.output = {0};
    return obj;
  }
};

class Solution {
public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items,
                                 std::vector<int> &queries) {
    std::sort(
        items.begin(), items.end(),
        [](std::vector<int> a, std::vector<int> b) { return a[0] < b[0]; });

    // consolidate prices
    std::vector<std::pair<int, int>> db{};
    int highest{0};
    int currPrice{items[0][0]};
    for (std::vector<int> item : items) {
      if (item[0] == currPrice) {
        highest = std::max(highest, item[1]);
      } else {
        db.push_back({currPrice, highest});
        highest = std::max(highest, item[1]);
        currPrice = item[0];
      }
    }
    db.push_back({currPrice, highest});

    // begin query
    std::vector<int> output{};
    for (int q : queries) {
      highest = 0;
      for (std::pair<int, int> item : db) {
        if (item.first > q)
          break;
        highest = item.second;
      }
      output.push_back(highest);
    }

    return output;
  }
};

void printVector(std::vector<int> vec) {
  for (int i : vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::vector<int> output{solCur.maximumBeauty(unit.items, unit.queries)};

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
}
