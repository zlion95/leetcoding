#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        stringstream ss;
        char c;
        int index = 0, i;
        bool endflag = true;
        while (endflag) {
            if (index >= strs[0].size()) break;
            c = strs[0][index];
            for (i = 1; i < strs.size(); ++i) {
                if (strs[i][index] != c) {
                    endflag = false;
                    break;
                }
            }
            if (endflag) ss << c;
            index++;
        }
        return ss.str();
    }
};


int main(int argc, char **argv) {
    Solution s;
    int n;
    string str;
    vector<string> strs;

    cin >> n;
    if (n != 0) {
        for (int i = 0; i < n; ++i) {
            cin >> str;
            strs.push_back(str);
        }
    }
    cout << s.longestCommonPrefix(strs) << endl;
}
