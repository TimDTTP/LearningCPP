
#include <cmath>
#include <iostream>
#include <unordered_map>

class Test {
public:
  struct TestCase {
    int numerator;
    int denominator;
    std::string output;
  };

  TestCase testA() { return {1, 2, "0.5"}; }

  TestCase testB() { return {2, 1, "2"}; }

  TestCase testC() { return {4, 333, "0.(012)"}; }
};

class Solution {
private:
  long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1)
        result = (result * base) % mod;
      base = (base * base) % mod;
      exp >>= 1;
    }
    return result;
  }

public:
  std::string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    std::string result;

    // Handle sign
    if ((numerator < 0) ^ (denominator < 0))
      result += "-";

    long long n = std::llabs((long long)numerator);
    long long d = std::llabs((long long)denominator);

    // Integer part
    result += std::to_string(n / d);
    long long rem = n % d;
    if (rem == 0)
      return result; // no fractional part

    result += ".";

    // Fractional part with remainder tracking
    std::unordered_map<long long, int> seen; // remainder -> position in string
    while (rem != 0) {
      if (seen.count(rem)) {
        // Insert '(' at earlier position
        result.insert(seen[rem], "(");
        result += ")";
        break;
      }
      seen[rem] = result.size();

      rem *= 10;
      result += std::to_string(rem / d);
      rem %= d;
    }

    return result;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::string output{
      solCur.fractionToDecimal(unit.numerator, unit.denominator)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
