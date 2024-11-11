
# Problem
Given... 
- A vector of integers, "nums"

Return...
- A boolean value

Where...
the return value is if you are able to convert "nums" to a strictly increasing 
array. Conversions must follow the following...
- At any index, 'i', (that hasn't been picked before) pick a prime number, 'p', 
strictly less than nums\[i], then subtract 'p' from nums\[i]
- This can be done any amount of times

[#2601 Prime Subtraction Operation](https://leetcode.com/problems/prime-subtraction-operation/description/)

## Constraints
- 1 <= nums.length <= 1000
- 1 <= nums\[i] <= 1000
- nums.length == n

## Approach

