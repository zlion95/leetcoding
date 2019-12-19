#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/* Solution 1:
	void wiggleSort(vector<int> &nums) {
		vector<int> sorted(nums);
		int pre = 0, mid = (nums.size() + 1) / 2;

		sort(sorted.begin(), sorted.end());
		for (int i = nums.size() - 1; i >= 0; --i) {
			nums[i] = sorted[i & 1 ? mid++ : pre++];
		}
	}
	*/
	/* 
	 * 基本原理和Solution 1其实是一样的，都是先排序，中分，穿插交换位置
	 * 相同数字的情况：
	 *	1. 如果相同数字在同一侧，则无影响直接可以通过穿插保证不连续
	 *	2. 如果相同数字刚好是中位数，就必须要有办法保证中位数不会被穿插到连续位置，比较简单的方法就是 遍历方向与更新数据的方向相反
	 * */
    void wiggleSort(vector<int>& nums) {
        int m = nums.size();
		sort(nums.begin(), nums.end());
        int median = nums[(m - 1) / 2]; 
        int i = 1;   // position for the larger values: start with first odd index
        int j = (m & 1) ? m - 1 : m - 2;  // position for the smaller values: start with last even index
        for (int l = 0; l < m; ++l) {
			for (int z = 0; z < nums.size(); ++z) {
				cout << nums[z] << " ";
			}
			cout << endl;
            if (nums[l] > median) {
                if (l <= i && (l & 1)) continue;       // skip the elements which are  already checked: 1, 3, 5, ..., i
                swap(nums[l--], nums[i]);
                i += 2;
            } else if (nums[l] < median) {
                if (l >= j && (l & 1) == 0) continue;     // skip the elements whcih are checked: j, j + 2, ..., lastEvenIndex
                swap(nums[l--], nums[j]);
                j -= 2;
            }
       }
    }

};

int main(int argc, char **argv) {
	int n;
	Solution s;
	vector<int> nums;

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];
	cout << "Input: ";
	for (int z = 0; z < nums.size(); ++z) {
		cout << nums[z] << " ";
	}
	cout << endl;
	s.wiggleSort(nums);
	cout << "final: ";
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
