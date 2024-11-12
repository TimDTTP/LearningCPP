
# Problem
Given... 
- A vector of integers, "nums"

Return...
- A boolean value

Where...
the return value is if you are able to convert "nums" to a strictly increasing 
array. Conversions must follow the following...
- At any index, 'i', (that hasn't been picked before) pick a prime number, 
'p', strictly less than nums\[i], then subtract 'p' from nums\[i]
- This can be done any amount of times

[#2601 Prime Subtraction Operation](https://leetcode.com/problems/prime-subtraction-operation/description/)

## Constraints
- 1 <= nums.length <= 1000
- 1 <= nums\[i] <= 1000
- nums.length == n

## Approach
- Traverse array backwards till found a value is that is not descending
- From there, find a prime value to subtract by that will be less than 
previous value.
- Use a separate array to use as memoization to track found prime numbers
- If not already in prime array, traverse until another prime number is found
- Exit conditions:
    - No prime number below num\[i] that will be less than num\[i + 1]

Runtime 0ms Beats 100%
Memory 27.46mB Beats 67.12%
