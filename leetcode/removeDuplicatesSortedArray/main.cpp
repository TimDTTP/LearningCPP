
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int buffer{nums[0]};

    for (int i{1}; i < nums.size(); ++i) {
      if (nums[i] == buffer) {
        nums.erase(nums.begin() + i);
        --i;
        continue;
      } else
        buffer = nums[i];
    }

    return nums.size();
  }
};

class OnlineSolution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int ptr1{1};

    for (int ptr2{1}; ptr2 < nums.size(); ++ptr2) {
      if (nums[ptr2] != nums[ptr2 - 1]) {
        nums[ptr1] = nums[ptr2];
        ++ptr1;
      }
    }

    return ptr1;
  }
};

int main() {
  std::vector<int> ASample{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::vector<int> AExpected{0, 1, 2, 3, 4};

  // check solution
  std::vector<int> nums{ASample};           // Input array
  std::vector<int> expectedNums{AExpected}; // The expected answer

  OnlineSolution cur = OnlineSolution();
  int k = cur.removeDuplicates(nums); // Calls your implementation

  assert(k = expectedNums.size());
  for (int i = 0; i < k; i++) {
    assert(nums[i] == expectedNums[i]);
  }

  // std::cout << k << '\n';
  // for (auto i : nums) {
  //   std::cout << i << '\n';
  // }
  // std::cout << '\n';

  std::cout << "Success!" << '\n';

  return 0;
}
