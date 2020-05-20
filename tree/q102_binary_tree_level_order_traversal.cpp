#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"

using namespace std;

class Solution {//二叉树层次遍历: 两个queue实现树层次的区分
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q1, q2;
        q1.push(root);
        bool flag = true;
        while (!q1.empty() || !q2.empty()) {
            queue<TreeNode*> *p = &(flag?q1:q2), *p2 = &(!flag?q1:q2);
            vector<int> lines;
            while (!p->empty()) {
                TreeNode *node = p->front();
                p->pop();
                if (!node) continue;
                lines.push_back(node->val);
                p2->push(node->left);
                p2->push(node->right);
            }
            if (!lines.empty()) res.push_back(lines);
            flag = !flag;
        }
        
        return res;
    }
};

int main(int argc, char **argv)
{
	return 0;
}
