#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *down_head = new ListNode(-1), *down = down_head,
                 *up_head = new ListNode(1), *up = up_head,
                 *p = head;

        while (p) {
            if (p->val < x) {
                down->next = p;
                down = down->next;
            } else {
                up->next = p;
                up = up->next;
            }
            p = p->next;
        }

        down->next = up_head->next;
        up->next = NULL;
        return down_head->next;
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
        n--;
    }
    cin >> n;

    printList(head->next);
    p = s.partition(head->next, n);
    printList(p);
}
