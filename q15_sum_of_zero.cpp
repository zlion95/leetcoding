#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    void add_pair(vector<vector<int> > &sum_pair, int i, int j, int k) {
        vector<int> pair;
        pair.push_back(i);
        pair.push_back(j);
        pair.push_back(k);
        sum_pair.push_back(pair);
    }

    bool sort_func(int i, int j) {return i < j;}

    void not_repeated_next(vector<int>& nums, int &i) {
        int old_value = nums[i];
        do {
            i++;
        } while (i < nums.size() - 1 && nums[i] == old_value);
    }

    void not_repeated_last(vector<int>& nums, int &i) {
        int old_value = nums[i];
        do {
            i--;
        } while (i > 0 && nums[i] == old_value);
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        int value, i, j, k, last = nums.size() - 1;
        bool is_repeated = false;

        if (nums.size() < 2) return sum_pair;
        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] >= 0) break;
            j = i + 1;
            k = last;

            while (j < last && nums[i] == nums[j]) {
                i = j;
                j++;
                is_repeated = true;
            }
            if (is_repeated) j--;


            while (j < k) {
                value = nums[i] + nums[j] + nums[k];
                if (value == 0) {
                    add_pair(sum_pair, nums[i], nums[j], nums[k]);
                    not_repeated_next(nums, j);
                }
                else if (value > 0) not_repeated_last(nums, k);
                else not_repeated_next(nums, j);
            }
            is_repeated = false;
        }

        if (last - i >= 2) {
            if (nums[i] == 0 && nums[i+1] == 0 && nums[i + 2] == 0) 
                add_pair(sum_pair, 0, 0, 0);
        }
        return sum_pair;
    }
};


int main(int argc, char **argv) {
    Solution s;
    int n, value;
    vector<int> nums;

    cin >> n;
    cout << "input: [ ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        nums.push_back(value);
        cout << value << " ";
    }
    cout << "]" << endl;


    vector<vector<int> > result = s.threeSum(nums);
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) cout << result[i][j] << " ";
        cout << "]";
        if (i+1 < result.size())
            cout << ", ";
    }
    cout << "]" << endl;
}
