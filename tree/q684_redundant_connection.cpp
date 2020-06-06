#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


//问题的关键在于找到错误情况： 
//1. u < v可以保证不会出现两点之间有重叠边
//2. 总共有N条边，N个节点，说明必定存在且只有1个环
//3. 如果成环上有节点度数为3，则必定需要破除的为该点上成环的边【两条中后出现的一条】
//4. 不能断开连通性

//方法一：建立邻接表，每加入一条边，就进行递归环检测，一旦发现了环，就返回当前边
class Solution1 {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if (edges.size() < 2) return {};
        unordered_map<int, unordered_set<int>> links;
        for (auto edge : edges) {
            if (check_cycle(links, edge[0], edge[1], -1)) return edge;
            links[edge[0]].insert(edge[1]);
            links[edge[1]].insert(edge[0]);
        }
        return {};
    }
    //DFS
    bool check_cycle(unordered_map<int, unordered_set<int>> &links, int cur, int target, int pre) {
        if (links[cur].count(target)) return true;
        for (int next : links[cur]) {
            if (next == pre) continue;
            if (check_cycle(links, next, target, cur)) return true;
        }
        return false;
    }
};

// 方法2：基本思想也是要检查环，不过遍历方式改成BFS，实现上用队列，从递归转换成迭代
class Solution2 {
public:
    //BFS
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> links;
        for (auto edge : edges) {
            queue<int> q{{edge[0]}};
            unordered_set<int> s{{edge[0]}};
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                if (links[cur].count(edge[1])) return edge;
                for (int next : links[cur]) {
                    if (s.count(next)) continue;
                    q.push(next);
                    s.insert(next);
                }
            }
            links[edge[0]].insert(edge[1]);
            links[edge[1]].insert(edge[0]);
        }
        return {};
    }
};

//方法三：最优解法是采用Union Find
//核心思想：建立节点数大小的数组，让数组的索引和值，与节点建立关系
//比如 root[1] = 2，就表示结点1和结点2是相连的，如果root[2] = 3 表示结点2和结点3是相连的
//可以通过一层一层的递进 1 => root[1] => 2 => root[2] => 3 这种方式最终是否会回到1，就能检查是否有环
class Solution {
public:
    //Union find
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int root[2001];
        for (int i = 0; i < 2001; ++i) root[i] = i;
        
        for (auto edge : edges) {
            int n1 = edge[0], n2 = edge[1];
            //union find这种方式非常奇特，会构建最长连通路线，
            //比如6->7 6->8  =>>>  [6] = 7 [7] = 8，会把最新加入的联通关系构建到最后的节点上
            //如果两个节点各自联通链末端的节点重合，就说明两条链中间有重合的节点，如果这两节点连接就会形成环
            while (n1 != root[n1]) n1 = root[n1];//因为没有两个节点一样的边，因此root[i] = i不会存在；
            while (n2 != root[n2]) n2 = root[n2];
            if (n1 == n2) return edge;
            root[n1] = n2;
        }
        return {};
    }
};

int main(int argc, char **argv)
{
	return 0;
}
