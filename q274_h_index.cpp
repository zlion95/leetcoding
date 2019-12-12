#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * H-index:
 * A scientist has index h if h of his/her N papers have at least h citations each, 
 * and the other N − h papers have no more than h citations each.
 */
class Solution {
public:
	int hIndex(vector<int> &citations) {
		int i;

		sort(citations.begin(), citations.end(), greater<int>());
		for (i = 0; i < citations.size(); ++i) if (citations[i] < i + 1) break;
		return i;
	}
};


int main (int argc, char **argv)
{
	int n;
	Solution s;
	vector<int> citations;

	cin >> n;
	citations.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> citations[i];
	}

	cout << s.hIndex(citations) << endl;
}
