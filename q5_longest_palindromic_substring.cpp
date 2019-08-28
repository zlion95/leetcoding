#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        char *extend_s = new char[2 * s.size()];
        // Insert '#' on even place.
        for (int i = 1; i <= 2 * s.size() - 1; ++i) {
            if (i % 2) extend_s[i] = s[i / 2];
            else extend_s[i] = '#';
        }
        
        int bias,
            max_string_size = 0;
        string max_string = "";
        max_string += s[0];
        for (int i = 1; i < 2 * s.size() - 1; ++i) {
            bias = 1;
            while (i - bias > 0 && i + bias < 2 * s.size()) {
                if (extend_s[i - bias] != extend_s[i + bias]) break;
                ++bias;
            }
            --bias;
            int size = 0;
            if (i % 2) { // i is odd: '#'
                size = (bias / 2) * 2 + 1;
            } else {
                size = 2 * ((bias / 2) + (bias % 2));
            }
            if (size > max_string_size) {
                max_string_size = size;
                max_string = "";
                for (int j = i - bias; j <= i + bias; ++j) {
                    if (extend_s[j] != '#')
                        max_string += extend_s[j];
                }
            }
        }
        return max_string;
    }
};


int main() {
    string str;
    cin >> str;
    
    Solution s;
    string output = s.longestPalindrome(str);
    cout << output << endl;
}