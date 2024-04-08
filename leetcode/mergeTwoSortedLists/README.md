
# Problem
Given 2 sorted linked lists...
Return 1 sorted linked list which combines the value of both lists 

[\#21 Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)

## Constraints
- Values from -100 to 100
- Sorted in non-decreasing order

## Approach
- Using tertiary list
1. Compare values of list 1 and 2
2. Add lesser into list 3, if same add both
3. Set head of list 1/2 to next value
4. Continue until 1 list ends and add the rest of the second list

## Improvements
Submitted approach is similar to optimize version
1. Can be Space complexity O(1) instead of O(n)
Improved version added to code
