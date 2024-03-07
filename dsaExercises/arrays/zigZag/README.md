# Problem

Given an array, rearrange the elements so that it alternates greater/lower than

i.e.
arr\[i\] \< arr\[i + 1\] > arr\[i + 2\] \< ... > ... \< ... > ...

[Link:](https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/)

## Approaches

1. Sort + swap

   - Start off by sorting the array
   - Starting with index 2, swap in form of pairs
     - 2~3
     - 4~5

1. Traverse + flag

   - Traverse the array with a flag alternating true/false each iteration
   - If flag == true, make sure next element is less than current
     - else, swap
   - If flag == false, ensure element is greater than
     - else, swap

## Analysis

1. Approach 1
   Because we used std::sort, it is by nature O(n*logn).
   Time complexity: O(n*logn)

   Spacewise, we could've made it constant space O(1), if we didn't use it to initialize a second array object.
   However this must be done in order to solve both approaches because arrays in C++ are implicitly passed by reference.
   O(n) because we initialize a second object with array.
   Space complexity: O(n)
