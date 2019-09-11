#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    ListNode *p = head;
    cout << "List: [";
    while (p->next) {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << p->val << "]" << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
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
    printList(head);
    s.removeNthFromEnd(head, n);
    
}
