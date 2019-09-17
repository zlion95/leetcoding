#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    void reverseLinkedList(ListNode *prev, ListNode *end_elem) {
        ListNode *s = prev->next, *swap_end = end_elem->next, *end = swap_end;
        while (s != swap_end) {
            prev->next = s->next;
            s->next = end;
            end = s;
            s = prev->next;
        }
        prev->next = end;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) return head;

        ListNode *newhead = new ListNode(0), 
                 *p = newhead, *start = head, *end = NULL;
        int k = 0;
        newhead->next = head;
        
        while (p->next) {
            ++k;
            if (k == m) start = p;
            if (k == n) end = p->next;
            p = p->next;
        }
        reverseLinkedList(start, end);
        return newhead->next;
    }
};

int main(int argc, char **argv) {
    int m, n, value;
    Solution s;
    ListNode *head = new ListNode(-1), *p = head;
    
    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        n--;
    }
    cin >> m;
    cin >> n;

    printList(head->next);
    p = s.reverseBetween(head->next, m, n);
    printList(p);
}
