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
        cout << i << " " << j << " " << k << endl;
    }

    void proper_insert(vector<int> &list, int value) {
        vector<int>::iterator it = list.begin();
        while (it != list.end() && *it < value) it++;
        if (it == list.end()) list.insert(list.end(), value);
        else if (*it == value) return;
        else list.insert(it, value);
    }

    bool find_one(map<int, int> &value_maps, int value) {
        map<int, int>::iterator it;
        it = value_maps.find(value);
        if (it != value_maps.end()) return true;
        return false;
    }

    bool find2add_when_zero(map<int, int> &value_maps, vector<vector<int> > &sum_pair,
            int value, bool with_zero) {
        if (with_zero)
            if (find_one(value_maps, -value))
                add_pair(sum_pair, value, -value, 0);
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        vector<int> sorted_keys;
        map<int, int> value_maps;
        map<int, int>::iterator it;
        vector<int>::iterator zs_it, ps_it;
        int value, minus_end, zstart, pstart;
        bool with_zero = false, one_minus = false;
        
        if (nums.size() < 2) return sum_pair;
        sorted_keys.push_back(nums[0]);
        for (int i = 0; i < nums.size(); ++i) {
            it = value_maps.find(nums[i]);
            if (it == value_maps.end()) {
                value_maps[nums[i]] = 1;
                proper_insert(sorted_keys, nums[i]);
                cout << nums[i] << endl;
            }
            else value_maps[nums[i]] += 1;
        }

        zstart = sorted_keys.size();
        pstart = 0;
        for (int i = 0; i < sorted_keys.size(); ++i) {
            cout << sorted_keys[i] << " ";
        }
        cout << endl;

        while (pstart < sorted_keys.size()) {
            if (sorted_keys[pstart] == 0) {
                zstart = pstart;
                pstart++;
                break;
            }
            else if (sorted_keys[pstart] > 0) break;
            pstart++;
        }
        cout << "zstart: " << zstart << " pstart: " << pstart << endl;
        cout << "value_maps size: " << value_maps.size() << endl;

        //with more than 3 of zero
        if (zstart < sorted_keys.size()){
            cout << "value: " << value_maps[0] << endl;
            if (value_maps[0] > 2)
                add_pair(sum_pair, 0, 0, 0);
            with_zero = true;
        }
        //all negative
        if (pstart == sorted_keys.size()) return sum_pair;
        minus_end = min(zstart, pstart);
        //all positive
        if (minus_end == 0) return sum_pair;

        //more than 2
        if (minus_end >= 2 || (minus_end == 1 && value_maps[sorted_keys[0]] > 1)) {
            for (int i = 0; i < minus_end; ++i) {
                if (value_maps[sorted_keys[i]] > 1) {
                    value = -sorted_keys[i] * 2;
                    if (find_one(value_maps, value))
                        add_pair(sum_pair, sorted_keys[i], sorted_keys[i], value);
                    cout << "mark1" << endl;
                }
                for (int j = 0; j < i; ++j) {
                    value = -(sorted_keys[i] + sorted_keys[j]);
                    if (find_one(value_maps, value))
                        add_pair(sum_pair, sorted_keys[i], sorted_keys[j], value);
                    cout << "mark2" << endl;
                }
                find2add_when_zero(value_maps, sum_pair, sorted_keys[i], with_zero);
            }
        } else {
            one_minus = true;
        }

        if (sorted_keys.size() - pstart >= 2 || 
                (sorted_keys.size() - 1 == pstart && value_maps[sorted_keys[pstart]] > 1)) {
            for (int i = pstart; i < sorted_keys.size(); ++i) {
                if (value_maps[sorted_keys[i]] > 1) {
                    value = -sorted_keys[i] * 2;
                    if (find_one(value_maps, value))
                        add_pair(sum_pair, sorted_keys[i], sorted_keys[i], value);
                    cout << "mark3" << endl;
                }
                for (int j = pstart; j < i; ++j) {
                    value = -(sorted_keys[i] + sorted_keys[j]);
                    if (find_one(value_maps, value))
                        add_pair(sum_pair, sorted_keys[i], sorted_keys[j], value);
                    cout << "mark4" << endl;
                }
                find2add_when_zero(value_maps, sum_pair, sorted_keys[i], with_zero);
            }
        } else if (one_minus && with_zero) {
            if (sorted_keys[0] == -sorted_keys[pstart])
                add_pair(sum_pair, sorted_keys[0], sorted_keys[pstart], 0);
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
