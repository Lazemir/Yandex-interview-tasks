//
//  main.cpp
//  21. Merge Two Sorted Lists
//
//  Created by Артём Lazemir on 11.12.2022.
//

#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val > l2->val) swap(l1, l2);
        auto head = l1;
        
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            if (!l1->next || l2->val < l1->next->val) {
                auto temp = l1->next;
                l1->next = l2;
                l2 = temp;
            } else {
                l1 = l1->next;
            }
        }
        
        if (l2) {
            l1->next = l2;
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
