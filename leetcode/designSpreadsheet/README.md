
# Problem
Given...
    - An int, rows

Return...
    - int

Where...
there are 4 different functions:
- Spreadsheet\(int rows)
    - Class constructor
- void setCell\(string cell, int value)
    - Sets the value of specified cell to the value
- void resetCell\(string cell)
    - Reset value of cell to 0
- int getValue(string formula)
    - Given in the form "=X+Y"
    - X or Y can either reference a cell or a non-negative number
    - Return sum

[\#3484 Design Spreadsheet](https://leetcode.com/problems/design-spreadsheet/description/?envType=daily-question&envId=2025-09-19)

## Constraint
- 1 <= rows <= 10^3
- 0 <= value <= 10^5
- Each cell reference consist of capital letters from 'A' to 'Z' followed by a
number 1 to rows
- At most 10^4 calls total to setCell, resetCell, and getValue

## Approach
- Initialize matrix of size 26 by rows using vectors
- Set private function to interpret string to cell indices
- setCell\(string cell, int value)
    - pass through interpreter and store value in location
- resetCell\(string cell)
    - interpreter\(location) = 0
- getValue(string formula)
    - break down to 2 substrings
    - check if cell or value
    - add and return

Runtime:
46ms beats 93.88%
Memory:
162.51mB beats 65.96%

## Improvements

