
# Problem
Given...
- A vector of vector of ints, grid1
- A vector of vector of ints, grid2

Return...
- A int

Where...
the return value is the number of "sub island(s)" on grid2.

Context
1 = land
0 = water

An island is a unit where 1's are connected 4-directionally (up, down, left, right)

A sub island is where all pieces of land of a given island on grid 2 is simutaneously taken up as land on grid 1.

[\#1905 Count Sub Islands](https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28)

## Constraints
- m == grid1.length == grid2.length
- n == grid1[\i].length == grid2[\i].length
- 1 <= m,n <= 500
- grid[\m][\n] are either 1 or 0

## Approach
