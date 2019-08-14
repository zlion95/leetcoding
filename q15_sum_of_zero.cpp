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

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        int pstart = 0;
        int zstart = INT_MAX;
        int i, j, value, last_i, last_j, mend;
        vector<int>::iterator it;


        if (nums.size() < 2) return sum_pair;
        sort(nums.begin(), nums.end());
        while(pstart < nums.size()) {   //search zero and positive start index
            if (nums[pstart] == 0 && zstart == INT_MAX) zstart = pstart;
            else if (nums[pstart] > 0) break;
            else pstart++;
        }

        if (zstart != INT_MAX && pstart - zstart > 2) 
            add_pair(sum_pair, 0, 0, 0);
        if (pstart > nums.size()) return sum_pair;          //all positive
        if (pstart == 0 || zstart == 0) return sum_pair;    //all negative
        mend = min(zstart, pstart);

        if (pstart > 1 && zstart > 1) {
            last_i = INT_MAX;
            for (i = 0; i < mend - 1; ++i) {
                if (nums[i] == last_i) continue;
                last_j = INT_MIN;
                for (j = i + 1; j < mend; ++j) {
                    if (nums[j] == last_j) continue;
                    value = -(nums[i] + nums[j]);
                    it = find(nums.begin() + pstart, nums.end(), value);
                    if (it != nums.end()) add_pair(sum_pair, nums[j], nums[i], value);
                    last_j = nums[j];
                }
                last_i = nums[i];
            }
        }

        if (nums.size() - pstart >= 2) {
            last_i = INT_MIN;
            for (i = pstart; i < nums.size() - 1; ++i) {
                if (nums[i] == last_i) continue;
                last_j = INT_MAX;
                for (j = i + 1; j < nums.size(); ++j) {
                    if (nums[j] == last_j) continue;
                    value = -(nums[i] + nums[j]);
                    it = find(nums.begin(), nums.begin() + mend, value);
                    if (it != nums.begin() + mend) add_pair(sum_pair, value, nums[j], nums[i]);
                    last_j = nums[j];
                }
                last_i = nums[i];
            }
        }

        if (zstart != INT_MAX) {
            last_i = INT_MAX;
            for(i = 0; i < min(pstart, zstart); ++i) {
                if (nums[i] == last_i) continue;
                it = find(nums.begin() + pstart, nums.end(), -nums[i]);
                if (it != nums.end()) add_pair(sum_pair, nums[i], 0, -nums[i]);
                last_i = nums[i];
                cout << "flag3" << endl;
            }
        }

        return sum_pair;
    }
};


int main(int argc, char **argv) {
    Solution s;
    int n, value;
    vector<int> nums;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        nums.push_back(value);
    }

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
