
#include <ios>
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    bool output;
  };

  TestCase testA() {
    TestCase obj{{4, 9, 6, 10}, true};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{6, 8, 11, 12}, true};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{5, 8, 3}, false};
    return obj;
  }
};

class Solution {
private:
  bool isPrime(int num, const std::vector<int> &primes) {
    int perfectSquare = std::sqrt(num);

    // find all prime under perfect square if divisible
    int index{0};
    while (primes[index] <= perfectSquare) {
      if (num % primes[index] == 0)
        return false;

      index++;
    }

    return true;
  }

public:
  bool primeSubOperation(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> primes{2, 3};

    // loop through vector for pattern
    for (int i{n - 2}; i >= 0; i--) {
      // not in descending order (backwards)
      if (nums[i] >= nums[i + 1]) {
        // find prime value
        // if already in array
        if (nums[i] - primes[primes.size() - 1] < nums[i + 1]) {
          for (int prime : primes) {
            if (prime >= nums[i])
              return false;
            else if (nums[i] - prime < nums[i + 1]) {
              nums[i] -= prime;
              break;
            }
          }
        }

        // not in array, have to find
        else {
          for (int j{primes[primes.size() - 1] + 1}; j < nums[i]; j++) {
            // check if prime
            if (isPrime(j, primes)) {
              primes.push_back(j);
              if (nums[i] - j < nums[i + 1]) {
                nums[i] -= j;
                break;
              }
            }
          }

          if (nums[i] - primes[primes.size() - 1] >= nums[i + 1]) {
            return false;
          }
        }
      }
    }

    return true;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  bool output{solCur.primeSubOperation(unit.nums)};

  std::cout << std::boolalpha;
  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
