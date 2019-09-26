#include <iostream>
#include <cmath>
#include "linked_list.h"

using namespace std;


class Solution {
public:
    int count_list(ListNode *head) {
        int count = 0;
        while (head) {
            head = head->next;
            ++count;
        }
        return count;
    }

    ListNode* get_n_next(ListNode *head, int n) {
        while (n) {
            head = head->next;
            --n;
        }
        return head;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        int count = 0, n1, n2;
        
        n1 = count_list(headA);
        n2 = count_list(headB);
        count = n1 - n2;
        if (count > 0) p1 = get_n_next(p1, abs(count));
        else if (count < 0) p2 = get_n_next(p2, abs(count));

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(int argc, char **argv) {
    int n, value;
    Solution s;
    ListNode *A = new ListNode(-1), *B = new ListNode(-1), *C = new ListNode(-1),
             *p = A, *p2 = B, *p3 = C;
    
    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        n--;
    }
    cout << "A: ";
    printList(A->next);

    cin >> n;
    while (n) {
        cin >> value;
        p2->next = new ListNode(value);
        p2 = p2->next;
        n--;
    }
    cout << "B: ";
    printList(B->next);

    cin >> n;
    while (n) {
        cin >> value;
        p3->next = new ListNode(value);
        p3 = p3->next;
        n--;
    }
    p->next = C->next;
    p2->next = C->next;
    cout << "C: ";
    printList(C->next);


    p = s.getIntersectionNode(A->next, B->next);
    cout << "Found C: ";
    printList(p);
}
