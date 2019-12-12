#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

struct Node {
	int val;
	int left_count, self_count;
	Node *left, *right;

	Node (int value) {
		val = value;
		left = NULL;
		right = NULL;
		left_count = 0;
		self_count = 1;
	}
};

// BST
class Solution {
public:
	void bst_search_and_insert(Node *root, int val, int &count) {
		if (val == root->val) {
			++root->self_count;
			count += root->left_count;
		} else if (val < root->val) {
			++root->left_count;
			if (root->left) bst_search_and_insert(root->left, val, count);
			else root->left = new Node(val);
		} else {
			count += root->left_count + root->self_count;
			if (root->right) bst_search_and_insert(root->right, val, count);
			else root->right = new Node(val);
		}
	}

	vector<int> countSmaller(vector<int> &nums)
	{
		vector<int> count(nums.size(), 0);

		if (!nums.size()) return nums;
		Node *root = new Node(nums[nums.size() - 1]);
		
		for (int i = nums.size() - 2; i >= 0; --i) {
			bst_search_and_insert(root, nums[i], count[i]);
		}
		return count;
	}
};

int main (int argc, char **argv)
{
	int n;
	Solution s;
	vector<int> nums, outputs;

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	
	outputs = s.countSmaller(nums);
	for (int i = 0; i < n; ++i) {
		cout << outputs[i] << " ";
	}
	cout << endl;
}
