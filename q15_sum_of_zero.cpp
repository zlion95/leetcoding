#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;

struct elem;
struct elem_pair;

struct elem_pair{
    struct elem *elem1;
    struct elem *elem2;
    elem_pair(struct elem *e1, struct elem *e2) : elem1(e1), elem2(e2) {}
};

struct elem {
    int value;
    int cnt;
    vector<struct elem_pair> pair;

    elem(int i, int j) : value(i), cnt(j) {}
    elem(int i, int j, struct elem *e1, struct elem *e2) : value(i), cnt(j) {
        struct elem_pair ep(e1, e2);
        pair.push_back(ep);
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

    void add_pair(vector<vector<int> > &sum_pair, struct elem *e, int value) {
        for (int i = 0; i < (e->pair).size(); ++i) {
            struct elem_pair ep = (e->pair)[i];
            vector<int> pair;
            pair.push_back((ep.elem1)->value);
            pair.push_back((ep.elem2)->value);
            pair.push_back(value);
            sum_pair.push_back(pair);
        }
    }

    void proper_insert(vector<struct elem> &list, struct elem *e) {
        vector<struct elem>::iterator it = list.begin();
        int value = e->value;
        while (it != list.end() && it->value < value) it++;
        if (it == list.end()) {
            list.insert(list.end(), *e);
        } else if (it->value == value) {
            if (it->pair.size() == 0) {
                it->cnt++;
                delete e;
            } else {
                (it->pair).insert(it->pair.end(), e->pair.begin(), e->pair.end());
            }
        } else {
            list.insert(it, *e);
        }
    }

    void middle_match(vector<vector<int> > &sum_pair, 
            vector<elem> &mlist, vector<elem> &plist, short mflag) {
        int i = 0, j = plist.size() - 1;
        while (i < mlist.size() && j >= 0) {
            if (-mlist[i].value == plist[j].value) {
                switch(mflag) {
                case 0: //with zero for no merge
                    add_pair(sum_pair, mlist[i].value, 0, plist[j].value);
                case 1: //mlist is merge
                    add_pair(sum_pair, &mlist[i], plist[j].value);
                case 2: //plist is merge
                    add_pair(sum_pair, &plist[j], mlist[i].value);
                }
                i++;
            }
            else if (-mlist[i].value > plist[j].value) i++;
            else j--;
        }
    }

    void merge_pair(vector<struct elem> &list, vector<struct elem> &mergelist) {
        struct elem *e;
        for (int i = 0; i < list.size(); ++i) {
            if (list[i].cnt > 1) {
                e = new struct elem(2 * list[i].value, 1, &list[i], &list[i]);
                proper_insert(mergelist, e);
            }

            for (int j = 0; j < i; ++j) {
                e = new struct elem(list[i].value + list[j].value, 1, &list[i], &list[j]);
                proper_insert(mergelist, e);
            }
        }
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > sum_pair;
        vector<struct elem> m_sorted_keys, p_sorted_keys, mergelist;
        int cnt0 = 0, cntp = 0, cntm = 0;
        struct elem *e;

        if (nums.size() < 2) return sum_pair;
        
        for (int i = 0; i < nums.size(); ++i) {
            e = new struct elem(nums[i], 1);
            if (nums[i] == 0) {
                cnt0++;
            } else if (nums[i] > 0) {
                proper_insert(p_sorted_keys, e);
                cntp++;
            } else {
                proper_insert(m_sorted_keys, e);
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
