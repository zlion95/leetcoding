#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
	//aab => aba
	//aaaabsd => abadasa
	string reorganizeString(string S)
	{
		string result = "";
		vector<pair<int, char>> dup;

		for (int i = 0; i < 26; ++i) dup.push_back(make_pair(0, i + 'a'));
		for (int i = 0; i < S.size(); ++i) dup[S[i] - 'a'].first++;
		sort(dup.rbegin(), dup.rend());
		
		string sort_str;
		for (pair<int, char> &p: dup) {
			if (p.first > (S.size() + 1) / 2) return "";
			sort_str += string(p.first, p.second);
		}
		for (int i = 0, j = (S.size() - 1)/2 + 1; i <= (S.size()-1)/2; ++i, ++j) {
			result += sort_str[i];
			if (j < S.size()) result += sort_str[j];
		}

		return result;
	}
};

int main(int argc, char **argv)
{
	string s;
	Solution solution;

	cin >> s;
	cout << solution.reorganizeString(s) << endl;
}
