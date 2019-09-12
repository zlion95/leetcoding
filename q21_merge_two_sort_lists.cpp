#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *result = head;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val <= p2->val) {
                result->next = p1;
                p1 = p1->next;
            } else {
                result->next = p2;
                p2 = p2->next;
            }
            result = result->next;
            result->next = NULL;
        }
        if (p1 != NULL) {
            result->next = p1;
        }
        if (p2 != NULL) {
            result->next = p2;
        }
        result = head->next;
        delete head;
        return result;
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
