#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int counts[255], left = 0, max_str = 0;
        for (int i = 0; i < 255; ++i) counts[i] = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (++counts[s[i]] > 1) 
                while (left < i) {
                    --counts[s[left]];
                    if (s[left++] == s[i]) break;
                }
            max_str = max(i - left + 1, max_str);
        }
        return max_str;
    } 
};


int main() {
    string str;
    cin >> str;
    
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;;

    return 0;
}