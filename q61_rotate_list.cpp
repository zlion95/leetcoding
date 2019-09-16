#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode *l1 = head, *l2 = l1;
        
        if (!head) return head;
        while (k && l2) {
            l2 = l2->next;
            --k;
            ++count;
        }
        if (k == 0 && !l2) return head;
        else if (k > 0) {
            k %= count;
            l2 = l1;
            while (k) {
                l2 = l2->next;
                --k;
            }
        }

        while (l2->next != NULL) {
            l1 = l1->next;
            l2 = l2->next;
        }
        
        l2->next = head;
        head = l1->next;
        l1->next = NULL;

        return head;
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
    p = s.rotateRight(head->next, n);
    printList(p);
}
