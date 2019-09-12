#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    /* 
     *  0  1  2
     * [x, y, z]
     * [x, z, y]
     * return index=1
     */
    ListNode* swap(ListNode *prev, ListNode *cur, ListNode *next) {
        if (prev) prev->next = next;
        cur->next = next->next;
        next->next = cur;
        return next;
    }

    ListNode* knext(ListNode *p, int k) {
        while (k > 0 && p != NULL) {
            p = p->next;
            --k;
        }
        if (k == 0) return p;
        else return NULL;
    }


    void kswap(ListNode *prev, int k) {
        ListNode *l1, *l2;
        for (int i = k - 1; i > 0; --i) {
            l1 = prev;
            l2 = prev->next;
            for (int j = 0; j < i; ++j) {
                l1 = swap(l1, l2, l2->next);
                l2 = l1->next;
            }
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tempHead = new ListNode(0), *p = tempHead, *p_knext;

        if (head == NULL) return head;
        tempHead->next = head;
        p_knext = knext(p, k);
        while (p_knext != NULL && p != NULL) {
            kswap(p, k);
            p = knext(p, k);
            p_knext = knext(p, k);
        }
        p = tempHead->next;
        delete tempHead;
        return p;
    }
};


int main(int argc, char **argv) {
    int n, value, k;
    Solution s;
    ListNode *head = new ListNode(0), *p = head;

    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;     
        n--;
    }
    cin >> k;
    
    printList(head->next);
    p = s.reverseKGroup(head->next, k);
    printList(p);
    delete head;
}
