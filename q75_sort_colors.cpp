#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) return;
		int pre = 0, last = nums.size() - 1, cur, temp;

		while (pre < nums.size() && nums[pre] == 0) ++pre;
		while (last > 0 && nums[last] == 2) --last;
		if (pre >= last) return;

		cur = pre + 1;
		while (cur < last) {
			if (nums[cur] == 0) {
				nums[cur] = nums[pre] ^ nums[cur];
				nums[pre] = nums[pre] ^ nums[cur];
				nums[cur] = nums[pre] ^ nums[cur];
				++pre;
				while (pre < nums.size() && nums[pre] == 0) ++pre;
				if (cur <= pre) cur = pre + 1;
			} else if (nums[cur] == 2) {
				nums[cur] = nums[last] ^ nums[cur];
				nums[last] = nums[last] ^ nums[cur];
				nums[cur] = nums[last] ^ nums[cur];
				--last;
				while (last > 0 && nums[last] == 2) --last;
			} else {
				++cur;
			}
		}

		if (pre >= last) return;
		if (nums[last] == 0 || nums[pre] == 2) {
			nums[pre] = nums[last] ^ nums[pre];
			nums[last] = nums[last] ^ nums[pre];
			nums[pre] = nums[last] ^ nums[pre];
		}
	}
};


int main(int argc, char **argv) {
	Solution s;
	int n, value;
	vector<int> nums;

	cin >> n;
	while (n) {
		cin >> value;
		nums.push_back(value);
		--n;
	}

	s.sortColors(nums);
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
