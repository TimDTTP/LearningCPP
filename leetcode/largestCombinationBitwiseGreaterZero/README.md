
# Problem
Given...
- A vector of integers, "candidates"

Return...
- An integer

Where...
the return value is the largest number of nums in "candidates" which after 
performing bitwise AND, is still greater than 0.

[#2275 Largest Combination With Bitwise AND Greater Than Zero](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/?envType=daily-question&envId=2024-11-07)

## Constraints
- 1 <= candidates.length <= 10^5
- 1 <= candidates\[i] <= 10^7

## Approach
- Create array matrix of size, 24 x  candidates.size
- Occupy table with 0
- Iterate through candidates and for each value add binary value to table
    - Starting at the right hand side = num % 2
    - num /= 2
- Iterate through each column in matrix and count number of 1's
- Return count

Passed but slow and inefficient.
Runtime 321ms Beats 5.13%
Memory 201.49mB Beats 5.12%

## Online Solution
Massive performance improvments
- Instead of instantiating a full matrix, use one vector of max size and 
increment index position of binary that is equal to 1
- Instead of calculating bits manually, just use '&' operator to get first 
bit and ">>=" operator to shift bit to the left
- Use "std::max_element" to get max element in array instead of manually 
iterating over array
