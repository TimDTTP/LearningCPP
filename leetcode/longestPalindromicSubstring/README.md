
# Problem
Given...
- A string

Return...
- The longest palindromic substring

[\#5 Longest palindromic substring](https://leetcode.com/problems/longest-palindromic-substring/description/)

## Constraints
- string only consists of letters and digits

## Approach
- 2 pointer
1. Slow pointer increments a character at a time
2. Fast pointer finds next occurence of char
3. Continues slow pointer until the end

## Online Solutions
- Best method is to use Manacher's Algorithm
Algorithm is used to find the longest palindromic substring
