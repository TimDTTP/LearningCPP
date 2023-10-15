
# Leetcode 2
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

10/04/23 13:12
First submission
Error on case #34 "
terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi
"

Reason:
Improper assumption that all values in linked list were able to fit in data type "int".

Solution:
Measure size of value and use overloaded functions accordingly.