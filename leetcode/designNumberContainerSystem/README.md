
# Problem
Given...
- An group of calls

Return...
- A properly modified, container
- A int

Where...
The group of call will consist of either a...
- Instantiation of the number container
- A single int argument
- Two int arguments

If there is a single argument, that will invoke the function find\() where it 
requires a integer return value which is the index of which that number is 
found. If there is two arguments, the first number is the index, the second is 
the value. If the position of that index is already occupied, replace it with 
the new value. Else, insert the value at that position.

[#2349 Design a number container system](https://leetcode.com/problems/design-a-number-container-system/description/)

## Constraints
- 1 <= index, number <= 10^9
- At most 10^5 calls will be made in total to "change\()" and "find\()"

## Approach


