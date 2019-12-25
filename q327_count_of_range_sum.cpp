#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		multiset<long long> sum;
		int i, dis = 0; 
		long long amount = 0;
		
		for (i = 0, sum.insert(0); i < nums.size(); ++i) {
			amount += nums[i];
			dis += distance(sum.lower_bound(amount - upper), sum.upper_bound(amount - lower));
			sum.insert(amount);
		}
		return dis;
    }
};


int main(int argc, char **argv) {
	int n, lower, upper;
	Solution s;
	vector<int> nums;

	cin >> n >> lower >> upper;
	nums.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	n = s.countRangeSum(nums, lower, upper);
	cout << n << endl;
}
