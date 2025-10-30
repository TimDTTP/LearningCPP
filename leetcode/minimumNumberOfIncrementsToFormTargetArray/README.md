
# Problem
Given...
    - Vector\<int>, target

Return...
    - Integer

Where...
The return value is the number of operations needed to be performed to form 
target array.

Operation starts off with an array the same size as target with all elements 
initially zeros. Each operation you can choose any subarray from initial and 
increment all elements by 1.

[#1526 Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/?envType=daily-question&envId=2025-10-30)

## Constraint
- 1 <= target.length <= 10^5
- 1 <= target\[i] <= 10^5

## Approach
Count peaks
- Traverse through vector
- Init count with first value
- If next value is greater than current...
    - Count += difference
- Return count

## Improvements
