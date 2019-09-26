#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *p1 = head, *p2 = head, *p3 = head, *prev;
        if (!head) return;

        while (p2 && p2->next) {
            p2 = p2->next->next;
            prev = p1;
            p1 = p1->next;
            prev->next = p3;
            p3 = prev;
        }

        if (p2 == NULL) {
            prev = p1;
            p1 = p1->next;
            prev->next = NULL;
        } else {
            prev = p3;
            p3 = p1;
            p1 = p1->next;
            p3->next = prev;
            prev = NULL;
        }

        while (p3 != head) {
            p2 = p1;
            p1 = p1->next;

            p2->next = p3;
            p3 = p3->next;

            p2->next->next = prev;
            prev = p2;
        }
        head->next = prev;
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
    s.reorderList(head->next);
    printList(head->next);
}
