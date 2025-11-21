
# Problem
Given...
    - String, s

Return...
    - Integer

Where...
The return value is the number of unique palindromes of length three that are 
subsequences of s.

[#1930 Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-11-21)

## Constraint
- 3 <= s.length <= 10^5
- s consists of only lowercase English letters

## Approach
- String to vector
- Init a map to char to first occurence, last occurence
- Loop through and add to map
- Loop through map and between count unique in between and add to total

Runtime:
146ms beats 73.93%
Memory:
18.88mB beats 16.18%

## Improvements

