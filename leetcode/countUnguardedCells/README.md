
# Problem
Given...
- An integer, 'm'
- An integer, 'n'
- A vector of vectors of integers, "guards"
- A vector of vectors of integers, "walls"

Return...
- An integer

Where...
`m` and `n` represent a 0-indexed grid and `guards` and `walls` are location on
the grid where they exist. A guard can see every cell in the four cardinal 
directions unless obstructed by another guard or wall. Return the number of
unoccupied cells that are not guarded.

[#2257 Count Unguarded Cells in the Grid](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2024-11-21)

## Constraints
- 1 <= m,n <= 10^5
- 2 <= m*n <= 10^5
- 1 <= guards.length, walls.length <= 5*10^4
- 2 <= guards.length + walls.length <= m*n
- guards\[i].length == walls\[j].length == 2
- 0 <= rowi, rowj < n
- 0 <= coli, colj < n
- All positions in `guards` and `walls` are unique

## Approach
- Create array to track guarded nodes
- Iterate through walls and remove positions
- Iterate through guards and traverse each direction if possible
- If encounter wall or guard, stop
- Else remove from array
- Count unguarded pos in array and return

Runtime 742ms Beats 5.82%
Memory 338.92mB Beats 5.10%
