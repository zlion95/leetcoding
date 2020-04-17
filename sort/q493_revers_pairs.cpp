#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int val;
	int left_count, right_count, count;
	Node *left, *right;

	Node (int value) {
		val = value;
		left = NULL;
		right = NULL;
		left_count = 0;
		right_count = 0;
		count = 1;
	}
};

class Solution {
private:
	vector<int> copy;
public:
	//BST 最坏也是要O(n^2) 最好为完全二叉树的情况O(log n)
	/*
	void bst_search_and_insert(Node *root, int val, bool &insert, int &count) {
		cout << val << "\t" << root->val << "\tcount:" << root->count << " right:" << root->right_count 
			<< "\t" << insert << "\t" << count << endl;
		if (val == root->val) {
			++root->count;
			insert = true;
			if (root->right) bst_search_and_insert(root->right, val, insert, count);
		} else if (val < root->val) {
			if (!insert) {
				++root->left_count;
				if (root->left) bst_search_and_insert(root->left, val, insert, count);
				else {
					root->left = new Node(val);
					insert = true;
				}
				if (root->val > val * 2) {
					count += (root->right_count + root->count);
				} else {
					if (root->right) bst_search_and_insert(root->right, val, insert, count);
				}
			} else {
				if (root->val > val * 2) {
					count += (root->right_count + root->count);
					if (root->left) bst_search_and_insert(root->left, val, insert, count);
				} else {
					if (root->right) bst_search_and_insert(root->right, val, insert, count);
				}

			}

		} else {
			if (!insert) {
				++root->right_count;
			}
			if (root->right) bst_search_and_insert(root->right, val, insert, count);
			else {
				root->right = new Node(val);
				insert = true;
			}
		}
	}
	int reversePairs(vector<int>& nums) {
		if (!nums.size()) return 0;

		int count = 0;
		bool insert;
		Node *root = new Node(nums[0]);

		for (int i = 1; i < nums.size(); ++i) {
			insert = false;
			bst_search_and_insert(root, nums[i], insert, count);
			cout << "==============================" << endl;
		}
		return count;
	}
	*/
	void merge(vector<int> &nums, int s, int m, int e) {
		int i = s, j = m+1, p = s;
		while (i <= m && j <= e) {
			if (nums[i] <= nums[j]) {
				copy[p++] = nums[i++];
			} else {
				copy[p++] = nums[j++];
			}
		}
		while (i <= m) copy[p++] = nums[i++];
		while (j <= e) copy[p++] = nums[j++];
		for (i = s; i <= e; ++i) nums[i] = copy[i];
	}

	int merge_sort(vector<int> &nums, int s, int e) {
		if (s >= e) return 0;
		int count = 0, m = s + (e - s)/2, i, j;

		count = merge_sort(nums, s, m) + merge_sort(nums, m + 1, e);

		for (i = s, j = m+1; i <= m; ++i) {
			while (j <=e && nums[i]/2.0 > nums[j]) ++j;
			count += j - (m+1);
		}
		merge(nums, s, m, e);

		return count;
	}

	int reversePairs(vector<int> &nums) {
		if (!nums.size()) return 0;
		copy.resize(nums.size());
		return merge_sort(nums, 0, nums.size() - 1);
	}
};

int main(int argc, char **argv) {
	int n;
	Solution s;
	vector<int> nums;

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < nums.size(); ++i) {
		cin >> nums[i];
	}
	cout << s.reversePairs(nums) << endl;
}
