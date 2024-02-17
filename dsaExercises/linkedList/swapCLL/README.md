
# Problem

In a circular linked list, exchange the first and last nodes

[Link](https://www.geeksforgeeks.org/exchange-first-last-node-circular-linked-list/)

## Approaches
1. Swap pointers
    - Get to the penultimate node, change pointer to the first node
    - Change first node pointer to last node
    - Change last node pointer to 2nd pointer

2. Swap values
    - Take value of first node
    - Emplace with last node, take value from last
    - Emplace with first node