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
        ListNode *cur = head, *next;

        if (!head) return head;
        next = head->next;
        while (next) {
            if (cur->val == next->val) cur->next = next->next;
            else cur = next;
            next = next->next;
        }
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
    p = s.deleteDuplicates(head->next);
    printList(p);
}
