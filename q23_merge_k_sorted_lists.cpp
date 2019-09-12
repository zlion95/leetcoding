#include <iostream>
#include <vector>
#include <climits>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0), *cur = &head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int KS = lists.size(), k;
        
        while (KS > 1) {
            k = KS / 2;
            for (int i = KS % 2 ? 1 : 0; i < ((KS % 2) ? k + 1 : k); ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            KS = k + KS % 2;
        }
        if (KS == 0) return NULL;
        else return lists[0];
    }
};


int main(int argc, char **argv) {
    int m, n, value;
    ListNode *head = new ListNode(0), *p;
    vector<ListNode*> lists;
    Solution s;

    cin >> m;
    while (m) {
        cin >> n;
        head->next = NULL;
        p = head;
        while (n) {
            cin >> value;
            p->next = new ListNode(value);
            p = p->next;
            n--;
        }
        p = head->next;
        lists.push_back(p);
        m--;
    }
    delete head;

    for (int i = 0; i < lists.size(); ++i) {
        printList(lists[i]);
    }
    p = s.mergeKLists(lists);  
    printList(p);
}
