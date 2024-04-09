
# Problem
Given...
1. A string of chars
Return...
2. An int

The int is the length of the longest substring without any repeating characters.

[\#3 Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

## Constraints
- string will contain letters, symbols, numbers, and spaces

## Approaches
- Unordered map
1. Initiate variable that keeps max length
2. Iterate through string
3. For each char, if it does not exist in map, add {char, index}
4. If char does exist in map, compare current index value and the previous index value
5. If it is greater than max, replace max
6. Lastly replace index value to new index value and continue
7. Return max
