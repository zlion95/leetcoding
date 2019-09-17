#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    void free(ListNode *start, ListNode *end) {
        ListNode *next;
        while (start != end) {
            next = start->next;
            delete start;
            start = next;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *new_head = new ListNode(0), *prev = new_head, *cur = head;
        bool is_dup = false;

        if (!head) return head;
        prev->next = head;
        
        while (cur->next) {
            if (prev->next->val == cur->next->val) {
                is_dup = true;
                cur = cur->next;
            } else if (is_dup) {
                is_dup = false;
                cur = cur->next;
                free(prev->next, cur);
                prev->next = cur;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        if (is_dup) {
            is_dup = false;
            cur = cur->next;
            free(prev->next, cur);
            prev->next = cur;
        }
        return new_head->next;
    }
};

int main(int argc, char **argv) {
    int n, value;
    Solution s;
    ListNode *head = new ListNode(-1), *p = head;

    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        --n;
    }
    
    printList(head->next);
    p = s.deleteDuplicates(head->next);
    printList(p);
}
