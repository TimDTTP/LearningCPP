
# Problem
Given...
- A vector of integers, arr
- A vector of vector of integers, mat

Return...
- An integer

Where...
mat is a viewed a matrixes. Starting at index 0 of arr, iterate through until 
either the first row or column will be completely filled in, return that index.

[#2661 First Completely Painted Row or Column](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

## Constraints
- m == mat.length
- n = mat\[i].length
- arr.length == m * n
- 1 <= m, n <= 10^5
- 1 <= m * n <= 10^5
- 1 <= arr\[i], mat\[r]\[c] <= m * n
- All integers of arr and mat are unique

## Approach

