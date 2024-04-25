
# Problem
Given...
- An integer
Return...
- An integer

which the given value is the n'th number of the tribonacci sequence. Find the value.

[\#1137 N-th tribonacci number](https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24)

## Constraints
- Answer is guaranteed to fit with 32-bit integer
    Thus regular `int` will suffice

## Approach
- Array
1. Traverse through values and add tribonacci value to array
2. Add the previous 3 values to get next value of the sequence
3. Run loop +1 extra to get the answer
