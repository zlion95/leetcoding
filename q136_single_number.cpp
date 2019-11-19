#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

#define MAP_SIZE (INT_MAX/8 + 1)

using namespace std;

//Solution 1 bitmap
//time: O(n) space: O(1)
class Solution1 {
public:
	char bitmap[MAP_SIZE], minus_bitmap[MAP_SIZE];
	int get_bit(char c) {
		switch (c) {
		case 1:
			return 0;
		case 2:
			return 1;
		case 4:
			return 2;
		case 8:
			return 3;
		case 16:
			return 4;
		case 32:
			return 5;
		case 64:
			return 6;
		default:
			return 7;
		}
	}

	int singleNumber(vector<int>& nums) {
		cout << "@@@@@" << endl;
		int size = nums.size();

		memset(bitmap, 0, sizeof(bitmap));
		memset(minus_bitmap, 0, sizeof(minus_bitmap));
		for (int i = 0; i < size; ++i) {
			int outer = nums[i] / 8, inner = abs(nums[i] % 8);
			char *cur_map;
			if (outer > 0)
				cur_map = &bitmap[outer];
			else
				cur_map = &minus_bitmap[-outer];
			*cur_map ^= (1 << inner);
		}
		for (int i = 0; i < MAP_SIZE; ++i) {
			if (bitmap[i]) {
				return 8 * i + get_bit(bitmap[i]);
			}
		}
		for (int i = 0; i < MAP_SIZE; ++i) {
			if (minus_bitmap[i]) {
				return -(8 * i + get_bit(minus_bitmap[i]));
			}
		}
	}
};
//Solution 2 hashmap
//time: O(n) space: O(n)

//Solution 3 bit action
//time: O(n) space: O(1)
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for (int i = 0; i < nums.size(); ++i) {
			value ^= nums[i];
		}
		return value;
	}
};

int main(int argc, char **argv) {
	Solution s;
	int n, value;
	vector<int> list;

	cin >> n;
	while (n) {
		cin >> value;
		list.push_back(value);
		--n;
	}
	cout << s.singleNumber(list) << endl;
}
