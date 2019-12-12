#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// 有致命问题
// 8464 84 
// 12 121?
class Solution1 {
	int max_d = 1;

public:
	int get_seed(int value, int radix, int d) {
		int idx = max_d - d;
		string s = to_string(value);
		if (idx >= s.size()) return s[0] - 48;
		else return s[idx] - 48;
	}

	void msd_sort(vector<int> &nums, int begin, int end, int radix, int d) {
		if (d < 1) return;

		vector<int> aux(nums.size());
		vector<int> count(radix, 0);


		for (int i = begin; i < end; ++i) count[get_seed(nums[i], radix, d)]++;
		vector<int> idx(count);
		for (int i = 1; i < radix; ++i) idx[i] += idx[i - 1];
		for (int i = end - 1; i >= begin; --i) aux[--idx[get_seed(nums[i], radix, d)] + begin] = nums[i];
		for (int i = begin; i < end; ++i) nums[i] = aux[i];

		int index = begin;
		for (int i = 0; i < radix; ++i) {
			if (count[i] > 1) {
				msd_sort(nums, index, index + count[i], radix, d - 1);
				index += count[i];
			} else if (count[i] == 1) {
				index += 1;
			}
		}
	}

	string largestNumber(vector<int> &nums) {
		int max_elem = *max_element(nums.begin(), nums.end());
		int zero_count = 0;

		max_d = to_string(max_elem).size();
		msd_sort(nums, 0, nums.size(), 10, max_d);
		stringstream ss;
		for (int i = nums.size() - 1; i >= 0; --i) {
			ss << nums[i];
			cout << nums[i]<< endl;
			zero_count |= nums[i];
		}
		if (!zero_count) return "0";
		return ss.str();
	}
};


int get_index(const int cur, const string &x, const string &y, bool bias) {
	if (bias) {
		if (cur < x.size()) return x[cur];
		else return y[cur - x.size()];
	} else {
		if (cur < y.size()) return y[cur];
		else return x[cur - y.size()];
	}
}

bool compare(const string &x, const string &y) {
	for (int i = 0; i < x.size() + y.size(); ++i) {
		int a = get_index(i, x, y, true), b = get_index(i, x, y, false);
		if (a > b) return true;
		else if (a < b) return false;
	}
	return true;
	//return x+y > y+x;
}

class Solution {
public:

	string largestNumber(vector<int> &nums) {
		vector<string> strs;
		string res;

		if (all_of(nums.begin(), nums.end(), [](int n) {return n == 0;})) return "0";

		strs.resize(nums.size());
		for (int i = 0; i < strs.size(); ++i) strs[i] = to_string(nums[i]);
		sort(strs.begin(), strs.end(), compare);
		for (int i = 0; i < strs.size(); ++i) res += strs[i];
		return res;
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

	string str = s.largestNumber(nums);
	cout << str << endl;
}
