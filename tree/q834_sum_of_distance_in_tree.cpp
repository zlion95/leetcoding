#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<unordered_set<int>> links;
    vector<int> count, res;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        links.resize(N);
        count.assign(N, 1);
        res.assign(N, 0);
        
        for (auto &edge : edges) {
            links[edge[0]].insert(edge[1]);
            links[edge[1]].insert(edge[0]);
        }
        
        post_dfs(0, -1);//题目中没有明确保证 0 为根节点，这样做是否存在问题?
        pre_dfs(0, -1);
        return res;
    }
    
    void post_dfs(int root, int pre) {
        for (auto &i : links[root]) {
            if (i == pre) continue;
            post_dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i]; //res[i]代表子树中节点到子树根节点的距离和，+count[i]是因为子树所有节点到root节点需要+子树节点数大小的距离
        }
    }
    
    void pre_dfs(int root, int pre) {
        for (auto &i : links[root]) {
            if (i == pre) continue;
            //这条式子的含义：
            //res[root]是从当前子树节点[root]开始到所有子树节点的距离和；有links[root].size()个子树，其中第i个子树[i]就是当前要更新的目标res[i]
            //填补：N - count[i] 代表除开[i]子树上所有节点  =》 这里的含义是i到非子树的其他节点的距离 + 1；
            //多余：count[i] 代表子树节点数，由于res[root] 是包含了 res[i]的 =》 【root->i的距离为1】，共i子树上共count[i]个节点，因此减count[i]即可
            // res[root] = res[i] + count[i] - (N - count[i])
            res[i] = res[root] - count[i] + links.size() - count[i];
            pre_dfs(i, root);
        }
    }
};

int main(int argc, char **argv) 
{
	return 0;
}
