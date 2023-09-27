
#include <algorithm>
#include <iostream>
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // getValue() -> linked list to reversed int 
        int added{ getValue(l1) + getValue(l2) };

        // convert to string
        std::string sAdded = std::to_string(added);

        // iterate through string and add to linked list
        LinkedList ll;
        for (int i{0}; i < static_cast<int>(std::size(sAdded)); ++i) {
            ll.insert(static_cast<int>(sAdded[i]));
        }

        return ll.getHead();
    }

    
    // return int of linked list + reversed
    int getValue(ListNode* node) {
        std::string tempVal;

        while (node != nullptr) {
            // concatenate via string
            tempVal += (std::to_string(node->val));
            node = node->next;
        }

        // reverse string 
        std::reverse(std::begin(tempVal), std::end(tempVal));

        // convert to int
        int answ{std::stoi(tempVal)};
        
        return answ;
    }
};


int main() {
    // [2, 4, 3]
    LinkedList l1;
    l1.insert(3);
    l1.insert(4);
    l1.insert(2);

    // [5, 6, 4]
    LinkedList l2;
    l2.insert(4);
    l2.insert(6);
    l2.insert(5);
    
    Solution ans;
    print(ans.addTwoNumbers(l1.getHead(), l2.getHead()));

    return 0;
}