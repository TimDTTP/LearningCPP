
# Problem
Given...
    - vector\<vector\<int>>, heightMap

Return...
    - int

Where...
- heightMap is a matrix representing the height of each unit cell on a 2D 
elevation map. Return the volume of water it can trap after raining.

[\#407 Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-10-03)

## Constraint
- m == heightMap.length
- n == heightMap\[i].length
- 1 <= m, n <= 200
- 0 <= heightMap\[i]\[j] <= 2 * 10^4

## Approach
- Init another matrix to track already visited units. 
- Iterate through matrix starting from m = 1 and n = 1 to m.size - 2 and 
n.size - 2
- If visited\[m]\[n] -> continue
- Init a queue to track children
- 

## Improvements

