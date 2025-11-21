
# Problem
Given...
    - Vector\<int>, stations
    - Integer, r
    - Integer, k

Return...
    - long long

Where...
Stations as a array of cities where stations\[i] represents the number of power 
stations in i city. Each city's power stations have the range r. Thus, a city's
total power is equivalent to the sum of the number of power stations +-r and 
its own power stations. With the allowance of the ability to add k number of
additional power stations to any city; return the minimum power available if 
the distribution of power stations are built optimally.

[#2528 Maximize the Minimum Powered City](https://leetcode.com/problems/maximize-the-minimum-powered-city/description/?envType=daily-question&envId=2025-11-07)

## Constraint
- n == stations.length
- 1 <= n <= 10^5
- 0 <= stations\[i] <= 10^5
- 0 <= r <= n - 1
- 0 <= k <= 10^9

## Approach
- Create a map\<int, int>, ascending order of key
- Populate map with total power to city index

## Improvements
TLE: Too long to come up with valid solution
Hint: Difference table \(Greedy sliding window)
