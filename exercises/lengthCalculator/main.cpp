
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

  // overloading operator +
  friend Length operator+(const Length &l1, const Length &l2);

  void printLength() {
    std::cout << m_feet << "\'" << m_inches << "\"" << '\n';
  }
};

// TODO:
// add 2 lengths
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

  // convert to type Length
  Length val1{convertLength(i_length)};
  Length val2{convertLength(i_width)};

  Length sum{val1 + val2};

  // print sum
  sum.printLength();

  return 0;
}
