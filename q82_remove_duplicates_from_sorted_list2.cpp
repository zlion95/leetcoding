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
        ListNode *prev = new ListNode(0), *cur = head, *next;
        bool is_dup = false;

        if (!head) return head;
        prev->next = head;
        next = cur;
        while (next) {
            if (next->val == cur->val && !is_dup) is_dup = true;
            else if (next->val != cur->val && is_dup) {
                free(cur, next);
                prev->next = next;
                cur = next;
                is_dup = false;
            }
            else if (next->val != cur->val && !is_dup) {
                prev = cur;
                cur = cur->next;
            }
            next = next->next;
        }
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
