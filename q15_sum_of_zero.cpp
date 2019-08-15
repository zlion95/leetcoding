#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;

struct elem {
    int value;
    int cnt;
    struct elem *elem1;
    struct elem *elem2;

    elem(int i, int j) {
        value = i;
        cnt = j;
        elem1 = NULL;
        elem2 = NULL;
    }
};

class Solution {
public:
    void add_pair(vector<vector<int> > &sum_pair, int i, int j, int k) {
        vector<int> pair;
        pair.push_back(i);
        pair.push_back(j);
        pair.push_back(k);
        sum_pair.push_back(pair);
    }

    void proper_insert(vector<struct elem> &list, int value) {
        vector<struct elem>::iterator it = list.begin();
        while (it != list.end() && it->value < value) it++;
        if (it == list.end()) {
            struct elem e(value, 1);
            list.insert(list.end(), e);
        } else if (it->value == value) {
            it->cnt++;
        } else {
            struct elem e(value, 1);
            list.insert(it, e);
        }
    }

    void middle_match(vector<vector<int> > &sum_pair, 
            vector<elem> &mlist, vector<elem> &plist, short mflag) {
        int i = 0, j = plist.size() - 1;
        while (i < mlist.size() && j >= 0) {
            if (-mlist[i].value == plist[j].value) {
                switch(mflag) {
                case 0:
                    add_pair(sum_pair, mlist[i].value, 0, plist[j].value);
                case 1: //mlist is merge
                    add_pair(sum_pair, (mlist[i].elem1)->value, (mlist[i].elem2)->value, plist[j].value);
                case 2: //plist is merge
                    add_pair(sum_pair, (plist[j].elem1)->value, (mlist[j].elem2)->value, plist[i].value);
                }
                i++;
            }
            else if (-mlist[i].value > plist[j].value) i++;
            else j--;
        }
    }

    void merge_pair(vector<struct elem> &list, vector<struct elem> &mergelist) {
        for (int i = 0; i < list.size() - 1; ++i) {
            if (list[i].cnt > 1) 
                proper_insert(mergelist, 2 * list[i].value);

            for (int j = 0; j < i; ++j) {
                proper_insert(mergelist, list[i].value + list[j].value);
            }
        }
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        vector<struct elem> m_sorted_keys, p_sorted_keys, mergelist;
        int cnt0 = 0, cntp = 0, cntm = 0;

        if (nums.size() < 2) return sum_pair;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                cnt0++;
            } else if (nums[i] > 0) {
                proper_insert(p_sorted_keys, nums[i]);
                cntp++;
            } else {
                proper_insert(m_sorted_keys, nums[i]);
                cntm++;
            }
        }

        if (cnt0 > 2) add_pair(sum_pair, 0, 0, 0);
        if (cntp == 0 || cntm == 0) return sum_pair;

        if (cnt0 != 0) {//m0p
            middle_match(sum_pair, m_sorted_keys, p_sorted_keys, 0);
        }
        if (cntm > 1) {//mmp
            merge_pair(m_sorted_keys, mergelist);
            middle_match(sum_pair, mergelist, p_sorted_keys, 1);
        }
        if (cntp > 1) {//mpp
            mergelist.clear();
            merge_pair(p_sorted_keys, mergelist);
            middle_match(sum_pair, m_sorted_keys, mergelist, 2);
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
