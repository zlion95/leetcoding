#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *p = head, *next;
        while (p) {
            next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
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
    p = s.reverseList(head->next);
    printList(p);
}
