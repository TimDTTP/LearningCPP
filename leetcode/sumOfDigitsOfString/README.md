
# Problem
Given...
- String, s
- Integer, k

Return...
- Int

Where...
S is composed of letters whose integer equivalent if their position in the alphabet.
Return the sum of the letters after k number of transforms

[\#1945 Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03)

## Constraints...
- 1 <= s.length <= 100
- 1 <= k <= 10
- s consists of lowercase English letters

## Approach
- Convert letters into values
- Push values into vector
- For k, iterate over and add values
- Take value and split into digits
- Push values into vector
