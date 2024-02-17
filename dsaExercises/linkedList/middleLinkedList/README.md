
# Problem

Given a linked list, return the value that returns in the middle. If there are 2 values in the middle, return the second value.

[Link:](https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/)

## Approaches
1. Brute force
    - Traverse linked lists
    - Add value to a vector
    - Return the middle value in vector

2. Counting values
    - Traverse once to count values
    - Re-traverse to size/2
    - Return that value

3. Two pointer
    - One pointer traverses linked list by 1
    - One pointer traverses linked list by 2
    - When the fast pointer hits the end, the slow pointer is at the middle

