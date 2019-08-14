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
            if (value == *it) break;
            if (value > *it) {
                list.insert(it, value);
                break;
            }
        }
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        vector<int> sorted_keys;
        map<int, int> value_maps;
        map<int, int>::iterator it, zs_it, ps_it;
        
        if (nums.size() < 2) return sum_pair;

        sorted_keys.push_back(nums[0]);
        for (int i = 0; i < nums.size(); ++i) {
            it = value_maps.find(nums[i]);
            if (it == value_maps.end()) {
                value_maps[nums[i]] = 1;
                proper_insert(sorted_keys, nums[i]);
            }
            else *it += 1;
        }

        zs_it = sorted_keys.end();
        ps_it = sorted_keys.begin();
        while(ps_it != sorted_keys.end()) { 
            if (*ps_it == 0 && zs_it == sorted_keys.end()) zs_it = ps_it;
            else if (*ps_it > 0) break;
            else ps_it++;
        }
        if (zs_it != sorted_keys.end() && ps_it - zs_it > 2)
            add_pair(sum_pair, 0, 0, 0);
        if (ps_it == sorted_keys.end()) return sum_pair;
        if (ps_it == sorted_keys.begin() || zs_it == sorted_keys.begin())
            return sum_pair;
        


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
