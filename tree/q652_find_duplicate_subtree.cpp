#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include "tree.h"

using namespace std;

/* 
 * 本质是一个后序遍历，先扫描好子树的结构后再构造当前树结构的key
 * 通过一个string序列化子树节点的值，从而生成唯一标志子树结构的字符串，将这个字符串作为key值，就能在map快速确定是否有相同子树结构
 * 缺点：字符串拼接操作非常耗时，并且存在大量字符串拷贝操作，内存占用也非常大，树的层次越深，字符串key值越长
 */
class Solution1 {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> dups;
        serialize(root, map);
        for (auto it = map.begin(); it != map.end(); it++)
            if (it->second.size() > 1) dups.push_back(it->second[0]);
        return dups;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
        if (!node) return "";
        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};

/*
 * 优点：通过使用固定长度的key值，和去除字符串操作大大减少了运行时间，也减少了内存使用
 * 缺点：只能容纳一定数目的子树，超过1<<16个子树结构，key值的碰撞概率就会上升【思考：是否可以通过char型数组来拓展key值位数，从而实现更加通用性？】
 */
class Solution2 {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<long, pair<int,int>> counts;    
    vector<TreeNode*> ans;
	/* 
	 * getId函数本质是一个后序遍历，先扫描好子树的结构后再构造当前树结构的key
	 * 重点在于key值的设计，不同于直接将node->val序列化为字符串作为key值的方法。采用了bit位区分，由于避免了string操作，可以大大减少运行时间
	 * 这个key值设计很巧妙：
	 *	1. 首先假设前提目标树不会有超过1<<16 = 65536这么多的子树【如果树大小超过这个数目的测试用例，可能会出错】
	 *	2. key值由64bit大小的long型变量来存储
	 *	3. key值的构成：
	 *		a. root->val << 32 当前子树的根节点值占用63 ~ 32位
	 *		b. getId(root->left) << 16 左子树的id占用16 ~ 31位
	 *		b. getId(root->right) << 16 右子树的id占用0 ~ 16位
	 *	4. 也就是说为了使key值不出现碰撞，最多能容纳的子树结构共有 1 << 16 = 65536个
	 *	5. 所谓的id由当前map中含有的子树结构数目生成，当插入新的隐射就会将当前数目作为id【最多容纳65536以内不发生碰撞】
	 * 	6. pair<int, int> first为id，second为该子树结构出现的次数
	 */
    function<int(TreeNode*)> getId = [&](TreeNode* r) {
      if (!r) return 0;
      long key = (static_cast<long>(static_cast<unsigned>(r->val)) << 32) |
                 (getId(r->left) << 16) | getId(r->right);    
      auto& p = counts[key];
      if (p.second++ == 0)
        p.first = counts.size();
      else if (p.second == 2)
        ans.push_back(r);
      return p.first;  
    };
    getId(root);
    return ans;
  }
};

class Solution3 {//和Solution2完全一样的思路，稍微写得更好理解一点
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        vector<TreeNode*> res;
        unordered_map<unsigned long, pair<int, int>> st;
        traversal(root, res, st);
        return res;
    }

    int traversal(TreeNode *root, vector<TreeNode*> &res, unordered_map<unsigned long, pair<int, int>> &st)
    {
        if (!root) return 0;
        
        unsigned long key = (static_cast<unsigned long>(root->val) << 32)
            | (traversal(root->left, res, st) << 16)
            | traversal(root->right, res, st);
        auto &p = st[key];
        if (p.first == 0) p.first = st.size();
        else if (p.second == 1) res.push_back(root);
        p.second++;
        return p.first;
    }
};

int main(int argc, char **argv)
{
	return 0;
}
