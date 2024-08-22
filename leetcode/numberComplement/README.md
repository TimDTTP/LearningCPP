
# Problem
Given...
- An int, num

Return...
- An int

Where...
The return is the binary complement of num.

[\#476 Number Complement](https://leetcode.com/problems/number-complement/description/)

## Constraints
1 <= num < 2^31

## Approach
Brute force
- Convert number to binary
- Flip bits
- Convert back to numerical

Bitwise AND
- Return bitwise num AND 0
- Any shared 0 is flipped to 1
- Non-zero are flipped to zero
