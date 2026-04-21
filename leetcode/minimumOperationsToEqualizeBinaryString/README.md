
# Problem
Given...
    - string, s 
    - int, k

Return...
    - int

Where...
In one operation you have to flip k number of 0's or 1's. Return the minimum 
number of operations required to make all characters in the string to '1'. If 
not possible return -1.

[#3666 Minimum Operations to Equalize Binary String](https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/description/?envType=daily-question&envId=2026-02-27)

## Constraint
- 1 <= s.length <= 10^5
- s\[i] is either '0' or '1'
- 1 <= k <= s.length

## Approach
- Compile number of 0's and 1's into pair
- Find remainder 0's % k
- If k - remainder is even, there is a possible answer
    - Else return -1 \(impossible)
- Solution is 0's / k ceiling + 1

## Improvements

