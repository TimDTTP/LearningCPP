
# Problem
Given...
    - A vector\<vector\<int>>, triangle

Return...
    - An int

Where...
triangle is a array shaped like a triangle. Find the minimum path from top to 
bottom adding values on the way down. AKA each move needs to be i + 1.

[\#120 Triangle](https://leetcode.com/problems/triangle/description/?envType=daily-question&envId=2025-09-25)

## Constraint
- 1 <= triangle.length <= 200
- triangle\[0].length == 1
- triangle\[i].length == triangle\[i-1].length + 1
- -10^4 <= triangle\[i]\[j] <= 10^4

## Approach
- Work bottom to top of triangle
- Starting from levels - 2, iterate through vector
- Change value to min\(i + 1, j + 1)
- Continue to the top, which will be the result

Runtime:
0ms beats 100%
Memory:
12.42mB beats 92.51%

## Improvements
Matches same logic as online solutions
