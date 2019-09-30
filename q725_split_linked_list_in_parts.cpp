#include <iostream>
#include <vector>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    int count = 0, n_parts, reverse_level = 1, low_parts = 1;
    vector<ListNode *> splitParts;

    void split(ListNode *head) {
        if (!head && count >= n_parts) return;
        
        count++;
        if (head) {
            split(head->next);
            int barrier = low_parts > (n_parts - count % n_parts) ? 
                        (count / n_parts) + 1 : count / n_parts;
            if (reverse_level > barrier) {
                splitParts.insert(splitParts.begin(), head->next);
                head->next = NULL;
                reverse_level = 1;
                low_parts++;
            }
            reverse_level++;
        } else {
            split(head);
            int barrier = low_parts > (n_parts - count % n_parts) ? 
                        (count / n_parts) + 1 : count / n_parts;

            if (reverse_level > barrier) {
                splitParts.insert(splitParts.begin(), NULL);
                reverse_level = 1;
                low_parts++;
            }
            reverse_level++;
        }
    }

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        n_parts = k;
        split(root);
        splitParts.insert(splitParts.begin(), root);
        return splitParts;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int n, value;
    ListNode *head = new ListNode(0), *p = head;

    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        --n;
    }
    cin >> n;
    
    printList(head->next);
    cout << "k: " << n << endl;
    vector<ListNode *> list_parts = s.splitListToParts(head->next, n);
    for (int n = 0; n < list_parts.size(); ++n) {
        p = list_parts[n];
        printList(p);
    }
    return 0;
}
