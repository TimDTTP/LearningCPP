
# Problem

Given an array, find the majority element.
    Majority element is an element which appears more then n/2 times, where n is the size of the array.

[Link](https://www.geeksforgeeks.org/majority-element/)

## Approaches
1. Nest loop
    - Loop 1 to iterate through array
    - Loop 2 iterates through the rest of the list
    - If elements match, increment count
    - If count > (n/2)
        - return

2. Binary search tree
    - Construct a BST
    - If value is already in tree, increment frequency
        - If frequency > n/2; return
    - If value is NOT in tree, add to tree

3. Boyer Moore's voting algorithm
    - Iterate through array
    - Arr[1] is first candidate
        - If next element is same, increment count
        - If not, decrement
            - If count == 0 take new current element as new candidate

4. Hash table
    - Create hashmap for key, value pair
    - If new element, add to hashmap
    - If pre-existing, increment value which is associated with key
        - If value > n/2, return

5. Sorting
    - Sort array
    - Iterate through array
        - Track if current element > n/2; return
