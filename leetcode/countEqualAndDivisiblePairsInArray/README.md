
# Problem
Given...
- A vector of integers, nums
- An integer, k

Return...
- An integer

Where...
Return the number of pairs i, j. Where i and j are distinct indexes of nums and 
are equal to each other and the product of the two indices is divisible by k.

[#2176 Count equal and divisible pairs in an array](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/?envType=daily-question&envId=2025-04-17)

## Constraint
- 1 <= nums.length <= 100
- 1 <= nums\[i], k <= 100

## Approach
- Refine nums into a map\<int, set\<int>>
- Loop through map
    - If table\[i].length == 1; continue
    - Loop through set; while index * j < set.max
        - j = k * a
        - If set.find\(index * j); ++counter
