#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


class BSTIterator1 {//将BST转化为Tread tree，使得next操作完全O(1); 适用于数据量大，next操作频繁的情况，构建之后，所有next操作都是O(1)
private:
    TreeNode *root;
    bool empty = false;
public:
    TreeNode *build(TreeNode *root, TreeNode *to_insert)
    {
        if (!root) return to_insert;
        TreeNode *left = root->left, *right = root->right, *temp;
        temp = build(left, to_insert);
        root->left = NULL;
        temp->right = root;
        temp = build(right, root);
        return temp;
    }
    TreeNode *flatten(TreeNode* root) {
        if (!root) return root;
        TreeNode *left = root->left, *right = root->right, *fake_head = new TreeNode(0);
        build(root, fake_head);
        return fake_head->right;
    }
    BSTIterator1(TreeNode* root) {//先将BST转化为Thread tree，这样next跳转节点等都比较简单
        this->root = flatten(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int value = root->val;
        if (root->right) root = root->right;
        else empty = true;
        return value;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return root != nullptr && !empty; 
    }
};


class BSTIterator2 {//使用morris traversal，适用于数据量小的情况，树深度比较浅，next时间相对不明显
private:
    TreeNode *p;
public:
    BSTIterator2(TreeNode* root) {
		p = root;
    }
    
    /** @return the next smallest number */
    int next() {
		TreeNode *temp, *t1;
		int ret;
		while (p) {
			if (!p->left) {
				ret = p->val;
				p = p->right;
			} else {
				temp = p->left;
				while (temp->right && temp->right != p) temp = temp->right;
				if (!temp->right) {
					temp->right = p;
					t1 = p;
					p = p->left;
					t1->left = NULL;
				} else {
					ret = p->val;
					temp->right = NULL;
					p = p->right;
					break;
				}
			}
		}
		return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
		return p != NULL;
    }
};

int main(int argc, char **argv)
{
	return 0;
}
