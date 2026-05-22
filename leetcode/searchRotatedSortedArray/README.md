
# Problem
Given...
    - Vector\<int> nums
    - Integer target

Return...
    - Integer

Where...
nums is an array that is...
- sorted in ascending order
- possibly left rotated at and unknown index, k.
i.e.
\{4,5,6,7,0,1,2,3}
Rotated by 4 indices

Given array nums after the possible rotation, return the indices of target. 
Return -1 if not in nums.

Algorithm must be O\(log n) runtime complexity

[#33 Search in rotated sorted array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-22)

## Constraint
- 1 <= nums.length <= 5000
- -10^4 <= nums\[i] <= 10^4
- All values of nums are unique
- nums is an ascending array that is possibly rotated
- -10^4 <= target <= 10^4

## Approach
- Divide and conquer
- Track upper and lower bound
- While upper and lower bound are more than 1 index apart keep going
- Divide and decide if to narrow down which direction
- If neither upper or lower are equivalent to target, return -1

Runtime:
0ms beats 100.00%
Memory:
15.20mB beats 33.92%

## Improvements

