#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution1
{//正常的递归::递归比较慢，而且层次不能太深	O(n) |  O(1)
public:
    void traversal(TreeNode *root, vector<int> &output)
	{
        if (!root) return;
        traversal(root->left, output);
        output.push_back(root->val);
        traversal(root->right, output);
    }
    
    vector<int> inorderTraversal(TreeNode* root)
	{
        vector<int> output;
        traversal(root, output);
        return output;
    }
};

class Solution2
{//栈迭代::栈迭代无需递归函数栈，比较快，但需要n大小的栈 O(n) | O(n)
public:
    vector<int> inorderTraversal(TreeNode* root)
	{
        vector<int> output;
        return output;
    }
};

class Solution3
{//morris method: structure-Threaded Binary Tree ::morris方法无需递归，块，但会破坏树结构，用于读一次的情况比较合适 O(n) | O(1)
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> output;
		TreeNode *cur = root, *pre, *temp;
		while (cur) {
			if (!cur->left) {
				output.push_back(cur->val);
				cur = cur->right;
			} else {
				pre = cur->left;
				while (pre->right) pre = pre->right;
				pre->right = cur;
				temp = cur;
				cur = cur->left;
				temp->left = NULL;
			}
		}
		return output;
	}
};

int main(int argc, char **argv)
{
	return 0;
}
