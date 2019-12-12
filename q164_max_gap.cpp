#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int> &nums) {
		int max_gap = 0;

		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			max_gap = max(nums[i] - nums[i - 1], max_gap);
		}
		return max_gap;
	}
};

int main(int argc, char **argv) {
	int n;
	Solution s;
	vector<int> nums;

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	n = s.maximumGap(nums);
	cout << n << endl;
}
