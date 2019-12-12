#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution1 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int> > outputs;
		bool right_flag = true;
		int i, left = newInterval[0], right = INT_MIN;

		sort(intervals.begin(), intervals.end());
		for (i = 0; i < intervals.size(); ++i) {
			vector<int> interval = intervals[i];
			if (interval[1] < newInterval[0]) {
				outputs.push_back(interval);
				continue;
			}
			if (interval[0] >  newInterval[1]) {
				if (right_flag) {
					right = newInterval[1];
					vector<int> temp_interval {left, right};
					outputs.push_back(temp_interval);
					right_flag = false;
				}
				outputs.push_back(interval);
				continue;
			}
			
			if (interval[0] < newInterval[0] && interval[1] >= newInterval[0]) {
				left = interval[0];
			}

			if (interval[0] <= newInterval[1] && interval[1] > newInterval[1]) {
				right = interval[1];
				vector<int> temp_interval {left, right};
				outputs.push_back(temp_interval);
				right_flag = false;
			}
		}

		if (right_flag) {
			right = newInterval[1];
			vector<int> temp_interval {left, right};
			outputs.push_back(temp_interval);
		}
		return outputs;
	}
};

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int> > output;
		int size = intervals.size();
		int i = 0;

		while (i < size && intervals[i][1] < newInterval[0]) {
			output.push_back(intervals[i]);
			++i;
		}

		while (i < size && intervals[i][0] <= newInterval[1]) {
			newInterval[0] = min(intervals[i][0], newInterval[0]);
			newInterval[1] = max(intervals[i][1], newInterval[1]);
			++i;
		}
		output.push_back(newInterval);

		while (i < size) {
			output.push_back(intervals[i]);
			++i;
		}
		return output;
	}

};

int main(int argc, char **argv) {
	int n;
	int value;
	vector<vector<int> > intervals;
	vector<int> new_interval(2);
	Solution s;

	cin >> n;
	while (n) {
		vector<int> interval(2);
		for (int i = 0; i < 2; ++i) {
			cin >> value;
			interval[i] = value;
		}
		intervals.push_back(interval);
		--n;
	}
	cin >> value;
	new_interval[0] = value;
	cin >> value;
	new_interval[1] = value;

	cout << "start" << endl;
	vector<vector<int> > outputs = s.insert(intervals, new_interval);
	cout << "result: " << endl;
	for (int i = 0; i < outputs.size(); ++i) {
		cout << "[" << outputs[i][0] << ", " << outputs[i][1] << "]" << endl;
	}
	return 0;
}
