
#include <iostream>
#include <unordered_map>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> A;
    std::vector<int> B;
    std::vector<int> expected;
  };

  TestCase testA() { return {{1, 3, 2, 4}, {3, 1, 2, 4}, {0, 2, 3, 4}}; }
  TestCase testB() { return {{2, 3, 1}, {3, 1, 2}, {0, 1, 3}}; }
  std::vector<TestCase> all() { return {testA(), testB()}; };

  void print(std::vector<int> vec) {
    for (int i : vec) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  std::vector<int> findThePrefixCommonArray(std::vector<int> &A,
                                            std::vector<int> &B) {
    int n = A.size();
    std::unordered_map<int, int> mapB{};
    for (int i{0}; i < n; ++i) {
      mapB[B[i]] = i;
    }

    std::vector<int> C{};
    C.resize(n, 0);
    for (int i{0}; i < n; ++i) {
      ++C[(std::max(i, mapB[A[i]]))];
    }

    int track{0};
    for (int i{0}; i < n; ++i) {
      track += C[i];
      C[i] = track;
    }

    return C;
  }
};

class OnlineSolution {
public:
  std::vector<int> findThePrefixCommonArray(std::vector<int> &A,
                                            std::vector<int> &B) {
    int n = A.size();
    std::vector<int> prefixCommonArray(n), frequency(n + 1, 0);
    int commonCount = 0;

    // Iterate through the elements of both arrays
    for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
      // Increment frequency of current elements in A and B
      // Check if the element in A has appeared before (common in prefix)
      if (++frequency[A[currentIndex]] == 2)
        ++commonCount;

      // Check if the element in B has appeared before (common in prefix)
      if (++frequency[B[currentIndex]] == 2)
        ++commonCount;

      // Store the count of common elements for the current prefix
      prefixCommonArray[currentIndex] = commonCount;
    }

    // Return the final array with counts of common elements in each prefix
    return prefixCommonArray;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    std::vector<int> result = sol.findThePrefixCommonArray(unit.A, unit.B);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "Expected:\n";
      tests.print(unit.expected);
      std::cout << "Got:\n";
      tests.print(result);
      std::cout << std::endl;
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
