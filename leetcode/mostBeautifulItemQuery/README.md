
# Problem 
Given...
- A vector of vectors of integers, "items"
- A vector of integers, "queries"

Return...
- A vector of integers

Where...
the return value is the maximum beauty of an item whose price is less than or
equal to the integer in "queries"

[#2070 Most Beautiful Item for Each Query](https://leetcode.com/problems/most-beautiful-item-for-each-query/description/?envType=daily-question&envId=2024-11-12)

## Constraints
- 1 <= items.length, queries.length <= 10^5
- items\[i].length == 2
- 1 <= price, beauty, queries\[j] <= 10^9

## Approach
Refine data, query
- Sort "items" by price in ascending order
- Traverse by price append to another array the price and highest beauty
- Traverse new array, if drag along highest beauty onto the next till not
- Append array to unordered_map for O\(1) lookup
- Begin query traversal
- For each query, traverse down price to find highest beauty, else return 0

Runtime 1477ms Beats 5.43%
Memory 425.09mB Beats 5.00%

## Online Solution
Had the correct overall approach and thought process but fell short when 
approaching the handling of data retrieval.
- Instead of searching each value independently, a better approach would 
be to dictate a range of values in which the maxBeauty is applicable.
- Ex. \{{0,0,2}, {2,5,9}, {9,8,INT_MAX}}
- Would result in a much shorter array to search through dramatically 
cutting time complexity
