//
//  main.cpp
//  2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode;
        auto res_head = res;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr) {
            sum = sum / 10 + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            
            res->next = new ListNode(sum % 10);
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
            res = res->next;
        }
        
        if (sum / 10 != 0) {
            res->next = new ListNode(sum / 10);
        }
        
        res = res_head->next;
        delete res_head;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    std::cout << endl;
    return 0;
}
