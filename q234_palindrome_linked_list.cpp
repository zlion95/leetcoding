#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    bool is_match(ListNode *p1, ListNode *p2) {
        while (p1 && p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == p2) return true;
        else return false;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *cur = head, *prev = NULL, *next;
        while (cur) {
            if (is_match(prev, cur) || is_match(prev, cur->next)) return true;

            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return false;
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
    cout << s.isPalindrome(head->next) << endl;
}
