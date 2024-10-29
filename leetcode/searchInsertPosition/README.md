
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
Merge sort approach
- Size = nums.size
- 2 pointer at each end
- loop till pointerA - pointerB < 2
- pivot = pointer A + (pointer B - pointer A)
- if target > pivot
    - pointer A = pivot
- if target < pivot
    - pointer B = pivot
- if target = pivot
    - return pivot
- return pivot if not found and pointer A - pointer B < 2
