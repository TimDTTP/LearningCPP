
#include <iostream>
#include <vector>

struct test {
  std::vector<int> nums;
  int val;
};

test test1() {
  test obj;
  obj.nums = {3, 2, 2, 3};
  obj.val = 3;

  return obj;
}

test test2() {
  test obj;
  obj.nums = {0, 1, 2, 2, 3, 0, 4, 2};
  obj.val = 2;

  return obj;
}

test test3() {
  test obj;
  obj.nums = {2};
  obj.val = 3;

  return obj;
}

test test4() {
  test obj;
  obj.nums = {1};
  obj.val = 1;

  return obj;
}

test test5() {
  test obj;
  obj.nums = {3, 3};
  obj.val = 3;

  return obj;
}

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    // empty list
    if (nums.size() == 0)
      return 0;

    int begin{0};
    size_t end{nums.size() - 1};

    // initial val of end
    while (nums[end] == val && end > begin)
      --end;

    if (begin == end && nums[begin] == val)
      return 0;

    while (begin < end) {
      if (nums[begin] == val) {
        nums[begin] = nums[end];
        nums[end] = val;

        // re-assign end
        while (nums[end] == val) {
          --end;
          if (begin == end) {
            return begin + 1;
          }
        }
      } else
        ++begin;
    }

    return begin + 1;
  }
};

int main() {
  test input{test4()};

  Solution ans = Solution();

  std::cout << ans.removeElement(input.nums, input.val) << '\n';

  for (int i : input.nums) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
