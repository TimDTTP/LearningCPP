
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
- Separate land pieces on grid2 by "island"
    - Init vector<vector<\int>> to track visited units
    - Iterate through unvisited units till unit == 1
    - Increment counter, add to a vector of islands
    - Perform BFS on ONLY unvisited nodes, and add as coordinates to initial point
    - Any "land" founds through BFS should also be marked as visited 
- Iterate through and find if islands on grid2 match up with land on grid1
    - Set a flag to track all comparisons
    - Iterate through grid2's islands
    - If grid1[\m][\n] != grid2[\m][\n]
        - flip flag
        - continue to next island
    - At the end if flag is still true, increment counter
- For every island increment count

## Problems
- BFS not recognizing land; 1
- Memory limit exceeded

## Revised Approach v1.1
- Instead of storing all coordinates in a matrix, we implement sub-island check
for each island during BFS

Reasoning:
This should provide significant improvement as this eliminates a large matrix;
vector<vector<pair<int>>>. This comes at the cost of losing modularity of
having separated island coordinates and sub-island checking function. A 
feasible exchange due to lack of necessity for island coordinates.

## Online Solutions
- Instead of instantiating another vector<vector<int>>, just use value '2' to indicate unit has been visited
- Optimally, should've used union find to solve problem
