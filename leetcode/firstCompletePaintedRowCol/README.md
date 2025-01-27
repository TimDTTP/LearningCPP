
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
Since we need to search for values in a matrix, we will first need to 
pre-process the data so that we can lookup and retrieve it easier.
- Convert matrix into a vector of pairs of size m * n; the pairs will be 
\<col, row> located at index mat\[r]\[c]
- 2 arrays will represent row and col of length m and n respectively. This
will track the frequency of each row and col
- Iterate through arr and access coordinates at lookup\[arr\[i]], decrement the
values of the 2 arrays at the index that corresponds with the col, row
- At the end, check if either coordinates now equals 0; return index if true

Runtime: 0ms Beats 100%
Memory: 133.78mB Beats 94.73%
