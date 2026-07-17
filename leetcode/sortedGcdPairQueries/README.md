
# Problem
Given...
    - Vector\<int> nums
    - Vector\<long long> queries

Return...
    - Vector\<int>

Where...
- A vector\<int> gcdPairs is an array which denotes all GCD of all possible
pairs \(nums\[i], nums\[j]) where 0 <= i < j < n.
- This vector will then be sorted in ascending order
- For the resultant array, for the element at result\[i] will equate to 
gcdPairs\[queries\[i]]

[#3312 Sorted GCD pair queries](https://leetcode.com/problems/sorted-gcd-pair-queries/description/?envType=daily-question&envId=2026-07-17)

## Constraint
- 2 <= n == nums.length <= 10^5
- 1 <= nums\[i] <= 5 * 10^4
- 1 <= queries.length <= 10^5
- 0 <= queries\[i] < n * \(n - 1) / 2

## Approach
- Brute force find all GCD
- Sort that array
- Run regular queries into resultant

As expected, approach led to memory exceeded. Fix will most likely lie in 
finding a better way than O\(n^2) due to finding all GCDs.
- Cannot find solution, will consult online solutions

## Improvements

