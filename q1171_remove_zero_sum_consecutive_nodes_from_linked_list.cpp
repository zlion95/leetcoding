#include <iostream>
#include <stack>
#include <unordered_map>
#include "linked_list.h"

using namespace std;

// Method 1: stack method, too slow.
class Solution1 {
public:
    stack<ListNode *> s1, s2;
    void check_queue(ListNode *pre) {
        int sum = pre->val;

        cout << "stack: ";
        while (!s1.empty() && sum != 0) {
            sum += s1.top()->val;
            cout << s1.top()->val << " ";
            s2.push(s1.top());
            s1.pop();
        }
        cout << endl;

        if (sum != 0) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(pre);
        } else {
            while (!s2.empty()) s2.pop();
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *fake_head = new ListNode(0), *p = head;
        while (p) {
            if (p->val != 0) check_queue(p);
            p = p->next;
        }
        
        cout << "has break;" << endl;
        while (!s1.empty()) {
            p = s1.top();
            p->next = fake_head->next;
            fake_head->next = p;
            s1.pop();
        }
        return fake_head->next;
    }
};


class Solution2 {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum = 0;
        unordered_map<int, ListNode *> map;
        ListNode *begin = new ListNode(0), *prev = begin, *cur = head, *temp;

        map[0] = begin;
        begin->next = head;
        while (cur) {
            if (cur->val == 0) {
                prev->next = cur->next;
                cur = cur->next;
                continue;
            }

            //when cur->val != 0
            sum += cur->val;
            if (map.find(sum) != map.end()) {
                //Found
                prev = map[sum];
                temp = prev->next;
                prev->next = cur->next;
                while (temp != cur) {
                    sum += temp->val;
                    map.erase(sum);
                    temp = temp->next;
                }
                sum += cur->val;
            } else {
                //Not Found
                map[sum] = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        if (sum == 0) begin->next = cur;
        return begin->next;
    }
};

int main(int argc, char **argv) {
    int n, value;
    Solution2 s;
    ListNode *head = new ListNode(-1), *p = head;

    cin >> n;
    while (n) {
        cin >> value;
        p->next = new ListNode(value);
        p = p->next;
        --n;
    }
    
    printList(head->next);
    p = s.removeZeroSumSublists(head->next);
    printList(p);
}
