
# Problem
Given...
- A string, word

Return...
- A integer

Where the integer represents the number of wonderful substrings that can exist
in 'word'

A 'wonderful substring' is a substring which at MOST one char can appear an odd
number of times.

[\#1915 Number of wonderful substrings](https://leetcode.com/problems/number-of-wonderful-substrings/description/)

## Constraints
- 1 <= word.length <= 10^5
- word consists of lowercase English letters from 'a' to 'j'

## Approach
- Consider each combination
1. Loop through string
2. For each loop, loop through the remainder of the string
3. Each time increment occurence in a char set
4. If > 1 number of odd numbers in set, do NOT count
5. If <= 1 number of odd numbers in set, increment count
Time complexity O(n^2)
