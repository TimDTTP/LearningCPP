
# Problem
Given a sorted vector...
Return
- Int, indicating the number of unique elements
- Vector, "nums" matching assertion
    - Assertion being remove duplicate numbers in place

[\#26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## Notes
- Array 'nums' are sorted in a non-decreasing order

## Approach
- For loop through array
- If i < i + 1
    - Erase all duplicates
    - nums.erase(nums.begin() + (start + 1), nums.begin() + i)
    - Hold onto beginning of unique value
    - start = i
- If !(i < i + 1)
    - Continue
