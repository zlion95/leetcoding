#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = new ListNode(0), *odd = odd_head, *p = head,
                 *even_head = new ListNode(0), *even = even_head;
        bool reverse = false;
        while (head) {
            if (reverse) {
                even->next = head;
                head = head->next;
                even = even->next;
            } else {
                odd->next = head;
                head = head->next;
                odd = odd->next;
            }
            reverse = !reverse;
        }
        even->next = NULL;
        odd->next = even_head->next;
        return odd_head->next;
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
    p = s.oddEvenList(head->next);
    printList(p);
}
