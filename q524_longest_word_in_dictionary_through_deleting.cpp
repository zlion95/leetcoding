#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//without sort O(nx)
	string findLongestWord(string s, vector<string> &d) {
		string result = "";
		int max_len = 0;
		for (int i = 0; i < d.size(); ++i) {
			string ds = d[i];
			int index = 0;
			for (int j = 0; j < s.size(); ++j) {
				if (index < ds.size() && s[j] == ds[index]) ++index;
			}

			if (index == ds.size()){
				if (ds.size() > max_len) {
					result = ds;
					max_len = ds.size();
				} else if (ds.size() == max_len && ds < result) {
					result = ds;
				}
			}
		}
		return result;
	}
	/* // Sort O(nlogn + nx)
	string findLongestWord(string s, vector<string> &d) {
		string result = "";

		if (d.size() == 0) return result;
		sort(d.begin(), d.end());
		vector<int> count(d.size()), index(d.size(), 0);
		for (int i = 0; i < d.size(); ++i) count[i] = d[i].size();
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < count.size(); ++j) {
				if (s[i] == d[j][index[j]]) {
					--count[j];
					++index[j];
				}
			}
		}

		int max_len = 0;
		for (int i = 0; i < d.size(); ++i) {
			cout << d[i] << "\t" << count[i] << endl;
			if (count[i] <= 0 && d[i].size() > max_len) {
				result = d[i];
				max_len = result.size();
			}
		}

		return result;
	}
	*/
};

int main(int argc, char **argv) {
	int n;
	string s;
	Solution so;
	vector<string> d;

	cin >> s;
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	cout << so.findLongestWord(s, d) << endl;
}
