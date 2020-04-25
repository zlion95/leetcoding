#include <iostream>
#include <vector>
#include <climits>
#include "tree.h"

using namespace std;

class Solution
{
public:
        int maxPath = INT_MIN;

        int findMax(TreeNode *root)
        {
                if (root == nullptr) return 0;
                int left = max(0, findMax(root->left));
                int right = max(0, findMax(root->right));
                maxPath = max(maxPath, left + right + root->val);
                return max(left, right) + root->val; 
        }
    
        int maxPathSum(TreeNode *root)
        {
                findMax(root);
                return maxPath;
        }

};
