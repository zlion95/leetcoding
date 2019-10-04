#include <iostream>
#include <vector>
#include <stack>
#include "linked_list.h"

using namespace std;

//Solution 2:
class Solution {
public:
    
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans(10000, 0);
        stack<pair<int,int>> st;
        int c = 0;
        if(!head)
            return {};
        while(head)
        {
            while( !st.empty() && st.top().first < head->val)
            {
                ans[st.top().second] = head->val;
                st.pop();
            }
            st.push(make_pair(head->val, c));
            c++;
            head = head->next;
        }
        ans.resize(c);
        return ans;
    }
};

#if 0
//Solutiion 1: weak method
class Solution {
public:
    int max;

    int get_next_large(ListNode* head) {
        max = head->val;
        while (head) {
            if (head->val > max) return head->val;
            head = head->next;
        }
        return 0;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;

        while (head) {
            values.push_back(get_next_large(head));
            head = head->next;
        }
        return values;
    }
};
#endif


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

    printList(head->next);
    vector<int> list = s.nextLargerNodes(head->next);
    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << ", ";
    }
    cout << endl;
}

