#include <iostream>
#include <stack>
#include "linked_list.h"

using namespace std;


#if 0
//1. 纯指针操作的方法
class Solution {
public:
    ListNode* insertHead(ListNode *head, int value) {
        ListNode *to_add = new ListNode(value);
        to_add->next = head;
        return to_add;
    }

    ListNode* addTwoNode(ListNode* p1, ListNode* p2) {
        if (!p1) return NULL;

        ListNode *cur = addTwoNode(p1->next, p2->next),
                 *next = new ListNode(0);

        if (!cur) cur = new ListNode(0);
        cur->val = cur->val + p1->val + p2->val;
        next->val = cur->val / 10;
        cur->val %= 10;
        next->next = cur;
        return next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        int l1_size = 0, l2_size = 0;
        
        while (p1 || p2) {
            if (p1) p1 = p1->next;
            else l1 = insertHead(l1, 0);

            if (p2) p2 = p2->next;
            else l2 = insertHead(l2, 0);
        }
        p1 = addTwoNode(l1, l2);
        if (p1->val) return p1;
        else return p1->next;
    }
};
#endif

//2. 栈方法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *head = new ListNode(0);
        stack<int> l1_stack, l2_stack;
        
        while (p) {
            l1_stack.push(p->val);
            p = p->next;
        }
        p = l2;
        while (p) {
            l2_stack.push(p->val);
            p = p->next;
        }

        do {
            if (!l1_stack.empty()) {
                head->val += l1_stack.top();
                l1_stack.pop();
            }
            if (!l2_stack.empty()) {
                head->val += l2_stack.top();
                l2_stack.pop();
            }
            p = new ListNode(head->val / 10);
            p->next = head;
            head->val %= 10;
            head = p;
        } while (head->val || !l1_stack.empty() || !l2_stack.empty());
        return head->next;
    }
};

int main() {
    ListNode *s1 = new ListNode(-1), *s2 = new ListNode(-1), *p = s1;
    int value, n;

    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        --n;
    }
    cin >> n;
    p = s2;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        --n;
    }

    Solution s;
    cout << "s1 ";
    printList(s1->next);
    cout << "s2 ";
    printList(s2->next);
    p = s.addTwoNumbers(s1->next, s2->next);
    printList(p);
    return 0;
}
