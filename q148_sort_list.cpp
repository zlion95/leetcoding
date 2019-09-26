#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
    ListNode *head = new ListNode(-1);
public:
    ListNode* merge(ListNode *p1, ListNode *p2) {
        ListNode *p = head;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1) p->next = p1;
        if (p2) p->next = p2;
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *prev;

        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev) prev->next = NULL;
        
        prev = sortList(head);
        fast = sortList(slow);
        head = merge(prev, fast);
        return head;
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
    p = s.sortList(head->next);
    printList(p);
}
