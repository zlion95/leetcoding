#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {//使用一个队列的层次遍历
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            res.push_back((q.front())->val);
            for (; len > 0; --len) {
                TreeNode *node = q.front();
                q.pop();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        
        return res;
    }
};

class Solution2 {//先序遍历，并增加层数计数，第一次进入下一层次的节点，必定是最右边的节点
public:
    void traversal(TreeNode *root, int level, vector<int> &res)
    {
        if (!root) return;
        if (res.size() < level) res.push_back(root->val);
        traversal(root->right, level+1, res);
        traversal(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        traversal(root, 1, res);
        return res;
    }
};

int main(int argc, char **argv)
{
	return 0;
}
