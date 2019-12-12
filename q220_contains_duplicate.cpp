#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		vector<pair<int, int>> dup(nums.size());

		for (int i = 0; i < nums.size(); ++i) dup[i] = make_pair(nums[i], i);
		sort(dup.begin(), dup.end());
		
		for(int i = 0; i < nums.size();i++) {
			for(int j = i + 1; j < nums.size() && dup[i].first + t >= dup[j].first; j++) {
				if(abs(dup[i].second - dup[j].second) <= k) return true; 
			}
		}
		return false;
	}
};

int main(int argc, char **argv) {
	Solution s;
	int n, k, t;
	vector<int> nums;

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> k;
		nums[i] = k;
	}
	cin >> k >> t;
	cout << s.containsNearbyAlmostDuplicate(nums, k, t) << endl;
}
