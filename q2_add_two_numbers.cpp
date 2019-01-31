#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int present, carry = 0;
        ListNode *templ1 = l1, *templ2 = l2;
        ListNode *node = new ListNode(0);
        ListNode *start = node;
        while (templ1 != NULL || templ2 != NULL) {
            if (templ1 != NULL) {
                node->val += templ1->val;
                templ1 = templ1->next;
            }
            if (templ2 != NULL) {
                node->val += templ2->val;
                templ2 = templ2->next;
            }
            if (node->val / 10 == 1) carry = 1;
            else carry = 0;
            node->val = node->val % 10;
            cout << node->val << endl;
            if (templ1 != NULL || templ2 != NULL || carry == 1) {
                node->next = new ListNode(carry);
                node = node->next;
            }
        }
        return start;
    }
};


int main() {
    int n, m, value;
    ListNode *p = new ListNode(0), 
            *s1 = NULL, *s2 = NULL;
    cin >> n;
    s1 = p;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        p->val = value;
        if (i != n - 1) {
            p->next = new ListNode(0);
            p = p->next;
        }
    }
    p = new ListNode(0);
    cin >> m;
    s2 = p;
    for (int i = 0; i < m; ++i) {
        cin >> value;
        p->val = value;
        if (i != m - 1) {
            p->next = new ListNode(0);
            p = p->next;
        }
    }
    Solution s;
    ListNode *output = s.addTwoNumbers(s1, s2);
    while (output != NULL) {
        cout << output->val << "->";
        output = output->next;
    }
    cout << endl;
    return 0;
}