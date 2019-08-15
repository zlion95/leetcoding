#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

    void proper_insert(vector<int> &list, int value) {
        for (vector<int>::iterator it = list.begin();
                it != list.end(); ++it) {
            if (value == *it) return;
            if (value > *it) {
                list.insert(it + 1, value);
                return;
            }
        }
        list.insert(list.begin(), value);
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        vector<int> sorted_keys;
        map<int, int> value_maps;
        map<int, int>::iterator it;
        vector<int>::iterator zs_it, ps_it;
        int value, minus_end, zstart, pstart;
        
        if (nums.size() < 2) return sum_pair;

        sorted_keys.push_back(nums[0]);
        for (int i = 0; i < nums.size(); ++i) {
            it = value_maps.find(nums[i]);
            if (it == value_maps.end()) {
                value_maps[nums[i]] = 1;
                proper_insert(sorted_keys, nums[i]);
                cout << nums[i] << endl;
            }
            else *it++;
        }

        zstart = sorted_keys.size();
        pstart = 0;
        while (pstart < sorted_keys.size()) {
            if (sorted_keys[pstart] == 0 && zstart == sorted_keys.size()) zstart = pstart;
            else if (sorted_keys[pstart] > 0) break;
            else pstart++;
        }
        cout << "zstart: " << zstart << " pstart: " << pstart << endl;
        if (zstart < sorted_keys.size() && pstart - zstart > 2) add_pair(sum_pair, 0, 0, 0);
        if (pstart == sorted_keys.size()) return sum_pair;
        if (pstart == 0 || zstart == 0) return sum_pair;
        
        minus_end = min(zstart, pstart);
        if (minus_end >= 2) {
            for (int i = 1; i < minus_end; ++i) {
                for (int j = 0; j < i; ++j) {
                    value = -(sorted_keys[i] + sorted_keys[j]);
                    cout << value << endl;
                    it = value_maps.find(value);
                    if (it == value_maps.end()) add_pair(sum_pair, sorted_keys[i], sorted_keys[j], value);
                }
            }
        }

        if (sorted_keys.size() - pstart >= 2) {
            for (int i = pstart + 1; i < sorted_keys.size(); ++i) {
                for (int j = pstart; j < i; ++j) {
                    value = -(sorted_keys[i] + sorted_keys[j]);
                    cout << value << endl;
                    it = value_maps.find(value);
                    if (it == value_maps.end()) add_pair(sum_pair, sorted_keys[i], sorted_keys[j], value);
                }
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
