#include <iostream>
#include "linked_list.h"
#include "tree.h"

using namespace std;

//Solution 1: recursion method
class Solution {
public:
    TreeNode* sortedListToBSTWithSize(ListNode *head, int count) {
        TreeNode *root;
        ListNode *p = head, *left = NULL, *right;
        int mid = count / 2;

        if (head == NULL) return NULL;
        while (mid) {
            left = p;
            p = p->next;
            --mid;
        }
        if (left)
            left->next = NULL;
        right = p->next;
        p->next = NULL;
        root = new TreeNode(p->val);
        //delete p;

        if (head != p) {
            root->left = sortedListToBSTWithSize(head, count / 2);
            root->right = sortedListToBSTWithSize(right, (count - 1) / 2);
        }
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        int count = 0;

        while (p) {
            ++count;
            p = p->next;
        }
        return sortedListToBSTWithSize(head, count);
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
