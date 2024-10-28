
# Problem
Given...
- A vector of ints, nums
- A int, target

Return...
- A int

Where...
the return value is the index of "target" in nums or where it would be if it 
was to be inserted.

[#35 Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)

## Constraints
- 1 <= nums.length <= 10^4
- -10^4 <= nums\[i] <= 10^4
- nums contains distinct values sorted in ascending order
- -10^4 <= target <= 10^4

## Approach
Quick sort
- 2 ptrs, start and end
- 1 ptr is the pivot, ~middle of start and end
- If pivot == target, return pivot
- If pivot > target, end = pivot
- If pivot < target, start = pivot
- Continue until start - end <= 2
- Iterate through remaining vector
- If val == target; return val's index
- If val >  target, return val's index - 1
- If end, return last index + 1

Runtime
0ms Beats 100%

Memory
12.45mB Beats 6.91%
