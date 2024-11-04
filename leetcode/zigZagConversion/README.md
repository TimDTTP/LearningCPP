
# Problem
Given...
- A string, 's'
- A int, "numRows"

Return...
- A string

Where...
the return value is the string read left to right, top to bottom after 
converting the string into a zig zag patter with "numRows" number of rows.

[#6 Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/)

## Constraints
- 1 <= s.length <= 1000
- 's' consists of English letters (upper and lower), ',' and '.'
- 1 <= numRows <= 1000

## Approach
- If "numRows" is 1, return 's'
- For "numRows" to get each of first 5 values
    - DB is distance from bottom \(row - 0)
    - DT is distance from top \(numRows - row)
    - ALternate between formula DB * 2 and DT * 2
    - Top and bottom most row is \(numRows - 1) * 2
- Append until index is out of scope

Runtime 0ms Beats 100%
Memory 10.83mB Beats 80.22%
