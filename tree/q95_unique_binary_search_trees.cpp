#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution1	// device and conquer: F(i) = G(i-1) * G(n-i)
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		if (n == 0) return vector<TreeNode*> ();
		return generateSubtrees(1, n);
	}

	vector<TreeNode*> generateSubtrees(int start, int end)
	{
		vector<TreeNode*> output;
		if (start > end) {
			output.push_back(NULL);
			return output;
		}
		if (start == end) {
			output.push_back(new TreeNode(start));
			return output;
		}

		for (int i = start; i <= end; ++i) {
			vector<TreeNode*> left_subtrees = generateSubtrees(start, i - 1),
				right_subtrees = generateSubtrees(i + 1, end);

			for (auto left : left_subtrees) {
				for (auto right : right_subtrees) {
					TreeNode *root = new TreeNode(i);
					root->left = left;
					root->right = right;
					output.push_back(root);
				}
			}
		}
		return output;
	}
};

/*
class Solution2 //DP1: [1, 2] 和 [4, 5] 这些区间其实具有一样的结构性质，那么其实可以通过加上偏差值就能求得对应的子树 + D&C的思路
{//这种方法可以复用部分子树的内存，巧妙在利用了区间大小一致时，树结构其实相同，只需要修改数值即可复用这个性质。
public:
	vector<TreeNode*> generateTrees(int n)
	{
		vector<vector<TreeNode *> *> dp(n + 1);
		dp[0] = new vector<TreeNode *> ();
		if (n == 0) return &dp[0];

		dp[0]->push_back(NULL);

		for (int len = 1; len <= n; ++len) {
			dp[i] = new vector<TreeNode *> ();
			for (int root = 1; root <= len; ++root) {
				int left = root - 1;
				int right = i - root;
				for (TreeNode left_tree : &dp[left]) {
					for (TreeNode right_tree : &dp[right]) {
						TreeNode tree_root = new TreeNode(root);
						tree_root->left = left_tree;//左子树和dp表的范例子树结构数据一样，因此不需要重新拷贝一份，只需要将指针指向它即可
						tree_root->right = clone(right_tree, root);//右子树与dp表的范例子树结构一样，但数值不同，不可复用，因此需要拷贝
						dp[len]->push_back(tree_root);
					}
				}
			}
		}
		return *dp[n];
	}

	TreeNode *clone(TreeNode *root, int offset)
	{
		if (root == NULL) return NULL;
		TreeNode *node = new TreeNode(root->val + offset);
		node->left = clone(root->left, offset);
		node->right = clone(root->right, offset);
		return node;
	}
};
*/

class Solution3 //DP2: [1...m] => [1...m+1] 时可以插入节点的位置 T(n) = f1(T(n-1)) + f2(T(n-1));	T(1) = 1;
{//递推公式中f1代表1型插入，f2代表2型插入
public:
	vector<TreeNode *> generateTrees(int n)
	{
		vector<TreeNode*> pre;
		if (n == 0) return pre;

		pre.push_back(NULL);
		for (int i = 1; i <= n; ++i) {
			vector<TreeNode*> cur;
			for (TreeNode *root : pre) {
				// 1型插入，作为根节点，子树在left
				TreeNode *insert = new TreeNode(i);
				insert->left = root;
				cur.push_back(insert);

				// 2型插入：作为右节点，将原来的右子树替换到插入节点的左子树处
				for (int j = 0; j <= n; ++j) {
					TreeNode *root_copy = tree_copy(root);
					TreeNode *right = root_copy;//从根节点开始往右子树逐层往下找能插入的地方
					for (int k = 0; k < j; ++k) {
						if (!right) break;
						right = right->right;
					}
					if (!right) break;
					TreeNode *right_tree = right->right;//找到目标插入位置为right->right, 原来的right->right作为insert->left
					insert = new TreeNode(i);
					right->right = insert;
					insert->left = right_tree;
					cur.push_back(root_copy);
				}
			}
			pre = cur;
		}
		return pre;
	}

	TreeNode *tree_copy(TreeNode *root)
	{
		if (!root) return root;
		TreeNode *newRoot = new TreeNode(root->val);
		newRoot->left = tree_copy(root->left);
		newRoot->right = tree_copy(root->right);
		return newRoot;
	}
};

int main(int argc, char **argv)
{
	return 0;
}
