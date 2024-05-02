
# Problem
Given...
- A vector of ints, nums

Return...
- An int

Which is the value of the largest value that has a negative equivalent.

[\#2441 Largest positive integer that exists with its negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02)

## Constraints
- 1 <= nums.length <= 1000
- -1000 <= nums[i] <= 1000
- nums[i] != 0

## Approach
1. Sort array from lowest to highest
2. Use 2 pointer to navigate array from each end
3. If 0 + (0 - ptr1) > ptr2
    ++ptr1
4. If 0 + (0 - ptr1) == ptr2
    return ptr2
5. If 0 + (0 - ptr1) < ptr2
    --ptr2
6. Else return -1

## Submission
Time: 15ms Beats 79.95%
Memory: 22.94MB Beats 51.86%
