
#include <array>
#include <iostream>
#include <limits>

// print array
void printArray(const std::array<int, 7> &arr) {
  for (const int i : arr) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

// print user prompt
void prompt(const std::array<int, 7> &arr) {
  std::cout << "Given array: ";
  printArray(arr);
  std::cout << "Choose one of the following approaches: " << std::endl;

  std::cout << "A) Nest loops" << '\n'
            << "B) Kadane's algorithm" << '\n'
            << "C) Traversal" << '\n'
            << std::endl;
}

// get user input
char getUserInput() {
  char input{};
  std::cout << "Enter: ";
  std::cin >> input;

  if (std::cin) {
    if (!std::cin.eof())
      exit(0);

    std::cin.clear();
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return input;
}

// Nested loop approach
int nestedLoop(std::array<int, 7> arr, int size) {
  int maxSoFar{};
  int temp{};

  for (int i{0}; i < (size - 1); ++i) {
    temp = arr[i];
    for (int j{i}; i < (size - 1); ++j) {
      if (arr[j] == 0)
        break;
      else
        temp *= arr[i];

      maxSoFar = std::max(temp, maxSoFar);
    }
  }

  return maxSoFar;
}

// Kadanes algorithm approach

// Traversal approach

int main() {
  std::array<int, 7> arr{4, 8, -2, 0, 5, -9, -4};

  char input{};

  prompt(arr);
  input = getUserInput();

  return 0;
}
