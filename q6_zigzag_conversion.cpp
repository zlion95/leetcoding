#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1) return s;
        string output = "";
        if (numRows == 2) { //{odd nums}; {even nums}
            for (int i = 0; i < s.size(); i = i + 2) output += s[i];
            for (int i = 1; i < s.size(); i = i + 2) output += s[i];
            return output;
        }
        // partition
        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1)
                for (int j = i; j < s.size(); j = j + 2 * numRows - 2) {
                    output += s[j];
                }
            else {
                for (int j = i; j < s.size();) {
                    output += s[j];
                    int next = 2 * i;
                    if (j % (2 * numRows - 2) < numRows) next = 2 * (numRows - i - 1);
                    j += next;
                }
            }
        }
        return output;
    }
};

int main() {
    string str;
    int numRows;
    cin >> str;
    cin >> numRows;
    
    Solution s;
    string output = s.convert(str, numRows);
    cout << output << endl;
}