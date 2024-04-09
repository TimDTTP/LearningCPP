
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

## Errors
1. Heap buffer overflow
nums = [1];

Solution: Instead of checking next value, check previous value

## Improvements
1. Overwrite instead of vector.erase()
- instead of using erase to delete the element, it is more efficient to overwrite it

WARNING: This does not remove the duplicates! This is an approach that takes advantage of the vulnerability in the check function.
  This only pushes the unique numbers to the front, which are the only ones checked.


