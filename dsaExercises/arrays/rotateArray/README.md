
# Problem

Write a program to cyclically rotate an array by 1

[Link:](https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/)

# Approach
1. Traversal + 1
    - Traverse array in reverse
    - Assign current element with sequentially previous element
    - If .end() assign to arr[0]
2. 2 Pointer
    - One pointer pointing to beginning
    - One pointer pointing to end
    - Swap both pointer, and traverse first pointer to last
3. Reversal algorithm
    - n = number of rotations
    - Split array into 2 groups
        - One being equal to the number of rotations
            - Last element for clockwise rotation
            - First element for counter-clockwise rotations
        - One being the rest
    - Reverse both arrays, independent of each other
    - Append and reverse once more
