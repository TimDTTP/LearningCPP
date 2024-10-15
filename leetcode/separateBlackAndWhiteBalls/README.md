
# Problem
Given...
- string, s

Return...
- long long

Where...
The return value is the numbers of move in order to move all black balls to the
right and all the white balls to the left.
- Moves can only be two adjacent balls at a time
- 's' will only have 1 or 0, black and white balls respectively

[#2938 Separate Black and White Balls](https://leetcode.com/problems/separate-black-and-white-balls/description/)

## Constraints
- 1 <= n == s.length <= 10^5
- s\[i] is either '0' or '1'

## Approach
- Traverse through string
- Count number of black balls whilst traversing
- If white ball, add number of black balls to move counter

Runtime 31ms Beats 73.43%
Memory 15.58mB Beats 76.03%

## Online Solutions
Little to no significant improvements.

Such a simple problem, many online solutions are almost identical to personal 
solution.

