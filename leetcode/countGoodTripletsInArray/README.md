
# Problem
Given...
- A vector of ints, nums1
- A vector of ints, nums2

Return...
- A long long

Where...
nums1 and nums2 are permutations of n - 1. Return the number of "good triplets".
A "good triplet" is a set of 3 distinct values which are present in increasing 
order in both vectors.

[#2179 Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/description/?envType=daily-question&envId=2025-04-15)

## Constraint
- n = nums1.length = nums2.length
- 3 <= n <= 10^5
- 0 <= nums1\[i], nums2\[i] <= n - 1

## Approach
Brute force
- For each vector, add every permutation into a set
- Compare each set and count number of similarities

Map lookup
- Add all values in nums2 to a map value:index
- Loop through nums1 until n - 3
- Go through every permutation of nums1
- Check if values in nums2 match requirements
- Count number that do

Note:
Seemingly works upto testcase 102/143. Hits error "Time Limit Exceeded".

Failed: Surpassed alotted time

