
#include <iostream>
#include <vector>

struct TestCase {
  std::vector<int> people;
  int limit;
  int expected;
};

TestCase test1() {
  TestCase obj;
  obj.people = {1, 2};
  obj.limit = 3;
  obj.expected = 1;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.people = {3, 2, 2, 1};
  obj.limit = 3;
  obj.expected = 3;

  return obj;
}

TestCase test3() {
  TestCase obj;
  obj.people = {3, 5, 3, 4};
  obj.limit = 5;
  obj.expected = 4;

  return obj;
}

class Solution {
public:
  int numRescueBoats(std::vector<int> &people, int limit) {
    int numBoats{0};
    int ptrStart{0};
    int ptrEnd = people.size() - 1;

    std::sort(people.begin(), people.end());

    while (ptrStart < ptrEnd) {
      if ((people[ptrStart] + people[ptrEnd]) <= limit)
        ++ptrStart;

      ++numBoats;
      --ptrEnd;
    }

    // if 1 remaining
    if (ptrStart == ptrEnd)
      ++numBoats;

    // else ptrStart has surpassed ptrEnd

    return numBoats;
  }
};

int main() {
  Solution answer = Solution();
  TestCase input{test1()};
  int output{answer.numRescueBoats(input.people, input.limit)};

  std::cout << "Expected: " << '\n' << input.expected << "\n\n";
  std::cout << "Actual: " << '\n' << output << "\n\n";

  return 0;
}
