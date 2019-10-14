#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void printIntervals(vector<vector<int> > &intervals) {
    cout << "[";
    for (int i = 0; i < intervals.size(); ++i) {
        vector<int> part = intervals[i];
        cout << "[";
        for (int j = 0; j < part.size(); ++j) {
            cout << part[j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<int> temp;
    void swap(vector<vector<int> > &list, int i, int j) {
        //list[j].swap(list[i]);
        temp = list[j];
        list[j] = list[i];
        list[i] = temp;
    }

    void quicksort(vector<vector<int> > &list, int start, int end) {
        int i = start, j = end;
        vector<int> target = list[start];

        while (i < j) {
            while (i < j && target[0] <= list[j][0]) j--;
            if (i < j) swap(list, i, j);
            while (i < j && list[i][0] <= target[0]) i++;
            if (i < j) swap(list, i, j);
        }

        if (i - 1 > start) quicksort(list, start, i - 1);
        if (j + 1 < end) quicksort(list, j + 1, end);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());

        int i = 0, j;
        vector<vector<int> > result;
        while (i < intervals.size() - 1) {
            j = i + 1;
            if (intervals[j][0] <= intervals[i][1]) {
                intervals[j][0] = intervals[i][0];
                intervals[j][1] = max(intervals[i][1], intervals[j][1]);
            } else {
                result.push_back(intervals[i]);
            }
            i = j;
        }
        result.push_back(intervals[i]);

        return result;
    }
};



int main(int argc, char **argv) 
{
    Solution s;
    vector<vector<int> > intervals, result;
    int n, m, value;

    cin >> n;

    while (n) {
        vector<int> part;
        m = 2;
        while (m) {
            cin >> value;
            part.push_back(value);
            --m;
        }
        intervals.push_back(part);
        --n;
    }
    //printIntervals(intervals);
    result = s.merge(intervals);
    printIntervals(result);
}
