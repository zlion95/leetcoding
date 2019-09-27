#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *fake_head = new ListNode(-1), *p = head, *prev = fake_head;

        fake_head->next = head;
        while (p) {
            if (p->val == val) prev->next = p->next;
            else prev = p;
            p = prev->next;
        }

        return fake_head->next;
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

    cout << "val = " << n << " ";
    printList(head->next);
    p = s.removeElements(head->next, n);
    printList(p);
}
