//
//  main.cpp
//  Reverse Linked List
//
//  Created by Артём Lazemir on 10.12.2022.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = head;
        if (head && head->next) {
            if (head->next->next) {
                new_head = reverseList(head->next);
            } else {
                new_head = head->next;
            }
            
            head->next->next = head;
            head->next = nullptr;
        }
            
        return new_head;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    ListNode* origin = new ListNode(1);
    auto head = origin;
    for (int i = 2; i <= 5; ++i) {
        head->next = new ListNode(i);
        head = head->next;
    }
    
    origin = sol.reverseList(origin);
    
    return 0;
}
