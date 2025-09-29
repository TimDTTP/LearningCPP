
# Problem
Given...
    - vector\<int>, values

Return...
    - int

Where...
values is a list of vertices of a polygon in clockwise manner whose values is 
weight of the point. Polygon triangulation is a process in which you divide the
polygon into a set of triangles whose vertices cooicide with the vertices of
the original polygon. This process will result in n - 2 triangles. The weight
of the triangle will be the product of the 3 points of the triangle. Return 
the minimum weight of the sum of triangles after performing polygon 
triangulation. Splitting the triangle cannot have overlaps.

[\#1039 Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-29)

## Constraint
- n == values.length
- 3 <= n <= 50
- 1 <= values\[i] <= 100

## Approach

## Improvements
Failed: TLE
Dynamic programming problem.

Runtime:
0ms beats 100%
Memory: 
10.47mB beats 96.91%

