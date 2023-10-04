
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr) {}

    ListNode(int x) 
        : val(x)
        , next(nullptr) {}
    
    ListNode(int x, ListNode *next)
        : val(x)
        , next(next) {}
};

class LinkedList {
    ListNode* head;

public:
    LinkedList()
        : head(nullptr) {}
    
    void insert(int val) {
        ListNode* newNode = new ListNode(val);

        // if head is empty, val is now the head
        if (head == nullptr) {
            head = newNode;
        }
        // else set val to the next val in linked list
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    ListNode* getHead() {return head;}
};


void print(ListNode* list) {
    while (list != nullptr) {
        std::cout << list->val << ' ';
        list = list->next;
    }
    std::cout << '\n';
}

 
class Solution {
    LinkedList l3;
    std::stack<int> stack;
    bool carryOver{ false };
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool statL1{true};
        bool statL2{true};
        while (statL1 || statL2) {
            if (statL1 && statL2) {
                int add{ (l1->val) + (l2->val) + carryOver };
                carryOver = false;
                if (add >= 10) {
                    carryOver = true;
                    add -= 10;
                }
                stack.push(add);
                l1 = l1->next;
                l2 = l2->next;
            }

            if (statL1 && !statL2) {
                int add{ (l1->val) + carryOver };
                carryOver = false;
                if (add >= 10) {
                    carryOver = true;
                    add -= 10;
                }
                stack.push(add);
                l1 = l1->next;
            }

            if (!statL1 && statL2) {
                int add{ (l2->val) + carryOver };
                carryOver = false;
                if (add >= 10) {
                    carryOver = true;
                    add -= 10;
                }
                stack.push(add);
                l2 = l2->next;
            }

            if (l1 == nullptr) { statL1 = false; }
            if (l2 == nullptr) { statL2 = false; }
        }

        if (carryOver) { stack.push(1); }

        while ((stack.empty()) == false) {
            l3.insert(stack.top());
            stack.pop();
        }

        return l3.getHead();
    }
};


int main() {
    // [2, 4, 3]
    LinkedList l1;
    l1.insert(2);
    l1.insert(4);
    l1.insert(3);

    // [5, 6, 4]
    LinkedList l2;
    l2.insert(5);
    l2.insert(6);
    l2.insert(4);
    
    print(l1.getHead());
    print(l2.getHead());
    Solution ans;
    print(ans.addTwoNumbers(l1.getHead(), l2.getHead()));

    return 0;
}