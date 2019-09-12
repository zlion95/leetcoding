#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* swap(ListNode *prev, ListNode *cur, ListNode *next) {
        if (prev) prev->next = next;
        cur->next = next->next;
        next->next = cur;
        return next;
    }

    bool has_pair_next(ListNode *p) {
        if (p->next != NULL && p->next->next != NULL)
            return true;
        return false;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode *p1 = NULL, *p2 = head, *p3 = head;

        if (head == NULL || head->next == NULL) return head;
        p3 = head->next;
        head = head->next;
        while(1) {
            p2 = swap(p1, p2, p3);
            p3 = p2->next;
            if (has_pair_next(p3)) {
                p1 = p3;
                p2 = p3->next;
                p3 = p2->next;
            } else {
                break;
            }
        }
        return head;
    }
};

int main(int argc, char **argv) {
    int n, value;
    Solution s;
    ListNode *head = new ListNode(0), *p = head;

    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        n--;
    }

    p = head->next;
    delete head;
    printList(p);
    p = s.swapPairs(p);
    printList(p);
}
