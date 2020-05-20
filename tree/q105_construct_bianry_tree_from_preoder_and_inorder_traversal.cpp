#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree.h"

using namespace std;

class Solution
{
private:
	unordered_map<int, int> inmap;

public:
	//先序遍历的一个变形
	TreeNode *build(vector<int> &preorder, int preStart, int preEnd, 
			vector<int> &inorder, int inStart, int inEnd)
	{
		if (preStart > preEnd || inStart > inEnd) return nullptr;

		TreeNode *root = new TreeNode(preorder[preStart]);
		auto got = inmap.find(root->val);
		if (got == inmap.end()) {
			cerr << "ERROR: Not found element [" << root->val << "] in inmap!" << endl;
			exit(-1);
		}
		int inRoot = got->second;
		int leftCount = inRoot - inStart;

		root->left = build(preorder, preStart + 1, preStart + leftCount, 
				inorder, inStart, inRoot - 1);
		root->right = build(preorder, preStart + leftCount + 1, preEnd, 
				inorder, inRoot + 1, inEnd);

		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		for (int i = 0; i < inorder.size(); ++i) {
			inmap[inorder[i]] = i;
		}
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};

int main(int argc, char **argv)
{
	int n;
	vector<int> preorder, inorder;

	cin >> n;
	preorder.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> preorder[i];
	}
	inorder.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
	}

	Solution s;
	TreeNode *root = s.buildTree(preorder, inorder);

	cout << treeNodeToString(root) << endl;
	return 0;
}
