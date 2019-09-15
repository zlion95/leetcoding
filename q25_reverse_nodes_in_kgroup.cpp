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

    // Solution 1: Use k-1 times two-pair swap instead of kgroup swap.
    void kswap1(ListNode *prev, int k) {
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

    ListNode* knext(ListNode *start, int k) {
        ListNode *p = start;
        while (k > 0 && p != NULL) {
            p = p->next;
            --k;
        }
        if (k == 0) return p;
        else return NULL;
    }

    void kswap(ListNode *prev, ListNode *end_elem, int k) {
        ListNode *s = prev->next, *swap_end = end_elem->next, *end = swap_end;
        while (s != swap_end) {
            prev->next = s->next;
            s->next = end;
            end = s;
            s = prev->next;
        }
        prev->next = end;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tempHead = new ListNode(0), *p = tempHead, *p_knext, *temp_next;

        if (head == NULL) return head;
        tempHead->next = head;
        p_knext = knext(p, k);
        while (p_knext != NULL && p != NULL) {
            temp_next = p->next;
            kswap(p, p_knext, k);
            p = temp_next;
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

