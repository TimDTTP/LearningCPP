
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
- Traversal
1. While loop with 'i' as iterator and index marker
2. Int start tracks beginning of unique char
3. If next num increase, delete repeating numbers and reset index value to start of unique value
4. At the end delete duplicates once more and return vector
