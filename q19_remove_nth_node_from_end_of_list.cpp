#include <iostream>
#include "linked_list.h"

using namespace std;


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *prev = head, *last = NULL;
        while (n - 1 > 0 && p->next != NULL) {
            p = p->next;
            n--;
        }

        while (p->next) {
            p = p->next;
            last = prev;
            prev = prev->next;
        }

        if (last != NULL)
            last->next = prev->next;
        else
            head = prev->next;

        delete prev;
        return head;
    }
};

int main(int argc, char **argv) {
    int size, n, value;
    ListNode *head, *p, *temp;
    Solution s;

    cin >> size;
    if (size) {
        cin >> value;
        head = new ListNode(value);
        size--;
    }
    p = head;

    while (size) {
        cin >> value;
        temp = new ListNode(value);
        p->next = temp;
        p = p->next;
        size--;
    }
    
    cin >> n;
    cout << "n: " << n << endl;
    printList(head);
    head = s.removeNthFromEnd(head, n);
    printList(head);
    
}
