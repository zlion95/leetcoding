#include <iostream>
#include "linked_list.h"
#include "tree.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root = new TreeNode(0);
        return root;
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
    TreeNode *root = s.sortedListToBST(head->next);
    string str = treeNodeToString(root);
    cout << "tree: " << str << endl;
}
