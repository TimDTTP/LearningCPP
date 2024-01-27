
# Problem

Given an array A[] of n numbers and another number x, the task is to check whether or not there exist two elements in A[] whose sum is exactly x.

[Link](https://www.geeksforgeeks.org/check-if-pair-with-given-sum-exists-in-array/#)

## Approaches
1. Nested loop
    - Loop 1 iterate through array
    - Loop 2 check if val1 + val2 == target

2. Sorting + 2 Pointer
    - Sort increasing order
    - Sum first and last element
    - Sum greater...
        - Decrement upper index
    - Sum lesser...
        - Increment lower index
    - When increment < decrement 
        - No pair == sum

3. Hashing
    - Iterate through array
    - If target - value is in hash map, return
    - Else add value to hash map
    - If end list, return no valid pair