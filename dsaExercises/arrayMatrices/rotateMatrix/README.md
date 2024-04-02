
# Problem
Given an array matrix, rotate the array

[Link:](https://www.geeksforgeeks.org/rotate-matrix-elements/)

## Approaches
1. Clockwise
    - Move top row elements
        - Pull first element of next row
        - Shift one down
        - Hold onto last element
        - Increment row lower limit
    - Move last column elements
        - Apply last element of above
        - Shift one down
        - Hold onto last element
        - Decrement column upper limit
    - Move last row elements
        - Apply last element of above
        - Shift one up
        - Hold onto last element
        - Decrement row upper limit
    - Move first column elements
        - Apply last element of above
        - Shift one up
        - Increment column lower limit
2. Counter-Clockwise
    - Same as above
