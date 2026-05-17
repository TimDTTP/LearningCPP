
# Problem
Given...
    - Vector\<int> nums

Return...
    - Integer

Where...
An array of length n is sorted in ascending order and rotated between 1 and n
times. Given that the sorted array are exclusively unique elements, return the
minimum element of that array. Algorithm must run in O\(log n) time.

[#153 Find minimum in rotated sorted array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-15)

## Constraint
- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums\[i] <= 5000
- All the integers of nums are unique
- nums is sorted and rotated between 1 and n times

## Approach
- Perform binary search
- Instead of finding exact value, find when value -1 is greater

Runtime:
0ms beats 100%
Memory:
14.21mB beats 9.70%

## Improvements

