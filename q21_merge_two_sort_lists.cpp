#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0), *result = &head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                result->next = l1;
                l1 = l1->next;
            } else {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        if (l1) result->next = l1;
        if (l2) result->next = l2;
        return head.next;
    }
};


int main(int argc, char **argv) {
    int n, value;
    ListNode *a = NULL, *b = NULL, *p = NULL;
    Solution s;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        if (a == NULL) {
            a = new ListNode(value);
            p = a;
        } else {
            p->next = new ListNode(value);
            p = p->next;
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        if (b == NULL) {
            b = new ListNode(value);
            p = b;
        } else {
            p->next = new ListNode(value);
            p = p->next;
        }
    }

    printList(a);
    printList(b);
    p = s.mergeTwoLists(a, b);
    printList(p);

}
