# Problem

Given an array containing both positive and negative integers; find the largest product of a subarray.

[Link:](https://www.geeksforgeeks.org/maximum-product-subarray/)

# Approaches

1. Nested for loops (Brute force)
- Loop across array, calculating product of each subarray
  - If iterated element is a 0, break out of loop
  - If product is greater than max, max = product

2. Kadane's Algorithm
   - We track the max and min value after each operation
     - This is to keep track of upper limit of each end in the chance of another negative number
   - One variable will keep the max thus far for the lifetime of the function
   - Return overall max
3. Traversal from both ends

