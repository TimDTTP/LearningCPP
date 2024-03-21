
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>

namespace constants {
const int FOOT = 12;
}

class Length {
private:
  int m_feet{};
  int m_inches{};

public:
  Length(int feet, int inches) : m_feet{feet}, m_inches{inches} {}

  // overloading operator
  friend Length operator+(const Length &l1, const Length &l2);
  friend Length operator-(const Length &l1, const Length &l2);
  friend Length operator*(const Length &l1, const int i);
  friend Length operator/(const Length &l1, const int i);

  void printLength() {
    std::cout << m_feet << "\'" << m_inches << "\"" << '\n';
  }
};

// friend function for operator+
Length operator+(const Length &l1, const Length &l2) {
  int overflow;

  // add inches first
  int inchSum{l1.m_inches + l2.m_inches};

  // force a "floor" division
  overflow = static_cast<int>(inchSum / constants::FOOT);

  inchSum = inchSum % constants::FOOT;

  // add feet + 1 if inches > 12
  int feetSum{l1.m_feet + l2.m_feet + overflow};

  Length temp{feetSum, inchSum};

  return temp;
}

// friend function for operator-
Length operator-(const Length &l1, const Length &l2) {
  int overflow{0};

  // subtract inches first
  int inchDiff{l1.m_inches - l2.m_inches};
  if (inchDiff < 0) {
    overflow = static_cast<int>(inchDiff / constants::FOOT);

    // to account surpassing limit initially
    ++overflow;
  }
  inchDiff = std::abs(inchDiff);

  inchDiff = constants::FOOT - (inchDiff % constants::FOOT);

  // add feet + 1 if inches > 12
  int feetDiff{l1.m_feet - l2.m_feet - overflow};

  Length temp{feetDiff, inchDiff};

  return temp;
}

// friend function for operator *
Length operator*(const Length &l1, const int i) {
  int overflow{};
  int inchProduct{};
  int feetProduct{};

  // multiply inches first
  inchProduct = l1.m_inches * i;

  // add to overflow var using floor division
  // must static_cast to get floor div
  overflow = static_cast<int>(inchProduct / constants::FOOT);

  // hold onto usable value using modulus
  inchProduct = inchProduct % constants::FOOT;

  // multiply feet + overflow value
  feetProduct = (l1.m_feet * i) + overflow;

  Length temp{feetProduct, inchProduct};

  return temp;
}

// friend function for operator/
Length operator/(const Length &l1, const int i) {
  // FIX:
  // disclaimer: Only does floor division, so it rounds down!!
  int feetDiv{static_cast<int>(l1.m_feet / i)};
  int inchDiv{static_cast<int>(l1.m_inches / i)};

  Length temp{feetDiv, inchDiv};

  return temp;
}

Length convertLength(std::string input) {
  int feet{};
  int inches{};

  // parse string and obtain feet and inches using regex
  std::regex findFeet{"[0-9]+(?=\')"};
  std::regex findInches{"[0-9]+(?=\")"};

  std::smatch match;

  std::regex_search(input, match, findFeet);
  feet = std::stoi(match[0].str());

  std::regex_search(input, match, findInches);
  inches = std::stoi(match[0].str());

  Length temp{feet, inches};

  return temp;
}

int main() {
  std::string i_length{"5'4\""};
  std::string i_width{"10'10\""};

  int multiple{2};

  // convert to type Length
  Length val1{convertLength(i_length)};
  Length val2{convertLength(i_width)};

  Length sum{val1 + val2};
  Length diff{val1 - val2};
  Length prod{val1 * multiple};
  Length div{val2 / multiple};

  // print sum
  sum.printLength();

  // print diff
  diff.printLength();

  // print product
  prod.printLength();

  // print div
  div.printLength();

  return 0;
}
