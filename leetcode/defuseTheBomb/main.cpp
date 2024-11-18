
#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> code;
    int k;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj{{5, 7, 1, 4}, 3, {12, 10, 16, 13}};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{1, 2, 3, 4}, 0, {0, 0, 0, 0}};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{2, 4, 9, 3}, -2, {12, 5, 6, 13}};
    return obj;
  }
};

class Solution {
private:
  void incPtr(int &curr, int size) {
    if (curr == size - 1)
      curr = 0;
    else
      curr++;
  }

public:
  std::vector<int> decrypt(std::vector<int> &code, int k) {
    int size = code.size();
    int ptr1, ptr2;

    if (k == 0) {
      for (int i{0}; i < size; i++) {
        code[i] = 0;
      }
      return code;
    } else if (k > 0) {
      ptr1 = 1;
      ptr2 = k;
    } else {
      ptr1 = size + k;
      ptr2 = size - 1;
    }

    int sum{std::accumulate(code.begin() + ptr1, code.end() - (size - ptr2 - 1),
                            0)};

    std::vector<int> output{};
    for (int i{0}; i < size; i++) {
      output.push_back(sum);

      sum -= code[ptr1];

      incPtr(ptr1, size);
      incPtr(ptr2, size);

      sum += code[ptr2];
    }

    return output;
  }
};

void print(std::vector<int> vec) {
  for (int i : vec)
    std::cout << i << ' ';
  std::cout << '\n';
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::vector<int> output{solCur.decrypt(unit.code, unit.k)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    print(unit.output);
    std::cout << "Actual: ";
    print(output);
  }
  std::cout << std::endl;
}
