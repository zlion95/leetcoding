#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>

using namespace std;

//错误条件：1. 环   2. 节点入度大于1   3.节点出度大于2
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<int> root(edges.size() + 1, 0), parent(edges.size() + 1, 0);
		vector<int> e1, e2, last_circle_edge;
		for (auto &edge : edges) {
			int &u = edge[0], &v = edge[1];
			if (root[u] == 0) root[u] = u;
			if (root[v] == 0) root[v] = v;

			if (parent[v] != 0) {
				e1 = {parent[v], v};
				e2 = edge;
			} else {
				parent[v] = u;
				int rootu = find_root(root, u);
				//int rootv = find_root(root, v);  //找v的root是没有意义的，因为parent[v] == 0说明v入度为0，没有父节点自然root自己
				if (rootu != v) root[v] = rootu;
				else last_circle_edge = edge;//当前edge放入图之后，就会构成环，因此当前边就是最后出现的环中的边
			}
		}
		//对于condition 2: 由于不够成环，且不是根节点，可以随便破坏e1 e2中一条即可，本题删除后出现的e2
		//对于condition 3:
		//1. 先祖先链，后多余边，最后环上其他边	==>	e1=祖先链边, e2=多余边, last_circle_edge=NULL[e2不被放入到root集合中，构不成环] ====>	删除 e2
		//2. 先祖先链，后环上其他边，最后多余边	==>	e1=祖先链边，e2=多余边，last_circle_edge=NULL[e2不被放入到root集合中，构不成环] ====>	删除 e2
		//3. 先多余边, 后祖先链，最后环上其他边	==>	e1=多余边，e2=祖先链边，last_circle_edge=环上其他边								====>	删除 e1
		//4. 先多余边，后环上其他边，最后祖先链	==>	e1=多余边，e2=祖先链边，last_circle_edge=环上其他边								====>	删除 e1
		if (e1.size()) return (last_circle_edge.empty()) ? e2 : e1;//condition 2: 没有构成环，指向了非祖先链上的节点	or		condition 3: 存在环，指向了祖先链上非根节点
		return last_circle_edge;	//condition 1: 指向根节点: 删除构成环上的任意边都可以，本题删除访问到的环上最后一条边
    }

	int find_root(vector<int> &root, int node) {
		if (root[node] == node) return node;
		root[node] = find_root(root, root[node]);
		return root[node];
	}
};


int main(int argc, char **argv)
{
	int n, v1, v2;
	vector<vector<int>> edges;

	cin >> n;
	while (n > 0) {
		cin >> v1 >> v2;
		edges.push_back({v1, v2});
		--n;
	}
	Solution s;
	vector<int> res = s.findRedundantDirectedConnection(edges);
	cout << "[" << res[0] << ", "<< res[1] << "]" << endl;
}
