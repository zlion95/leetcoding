#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *fake_head = new ListNode(0), *prev = fake_head, *cur = head, *match, *match_prev;

        fake_head->next = head;
        while (cur) {
            match_prev = fake_head;
            match = fake_head->next;
            while (match != cur && match->val < cur->val) {
                match_prev = match;
                match = match->next;
            }
            if (match != cur) {
                prev->next = cur->next;
                match_prev->next = cur;
                cur->next = match;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return fake_head->next;
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
    p = s.insertionSortList(head->next);
    printList(p);
}
