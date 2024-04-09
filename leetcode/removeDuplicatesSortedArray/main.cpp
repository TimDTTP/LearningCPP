
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    // tracks index of array
    int index{1};
    // tracks start of unique value
    int start{1};

    // edge case num.size() == 1
    if (nums.size() == 1)
      return 1;

    // deal with first value
    if (nums[0] == nums[index]) {
      start = 0;
    }

    while (index < nums.size()) {
      // FIX: Reverse checking
      if (nums[index] > nums[index - 1]) {
        // delete
        nums.erase(nums.begin() + (start + 1), nums.begin() + index);
        // reset
        index = start;
        start = index + 1;
      }

      ++index;
    }
    return nums.size();
  }
};

int main() {
  std::vector<int> ASample{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::vector<int> AExpected{0, 1, 2, 3, 4};

  // check solution
  std::vector<int> nums{ASample};           // Input array
  std::vector<int> expectedNums{AExpected}; // The expected answer

  Solution cur = Solution();
  int k = cur.removeDuplicates(nums); // Calls your implementation

  assert(k = expectedNums.size());
  for (int i = 0; i < k; i++) {
    assert(nums[i] == expectedNums[i]);
  }

  std::cout << "Success!" << '\n';

  return 0;
}
