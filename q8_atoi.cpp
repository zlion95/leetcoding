#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool flag = true, is_negative = false;
        int nums = 0, temp;
        for (int i = 0; i < str.size(); ++i) {
            if (flag || ('0' <= str[i] && str[i] <= '9')) {
                if (str[i] >= '0' && str[i] <= '9') {
                    flag = false;
                    temp = str[i] - '0';
                    if (nums > INT_MAX / 10 || (nums == INT_MAX / 10 && temp > 7)) return INT_MAX;
                    if (nums < INT_MIN / 10 || (nums == INT_MIN / 10 && temp > 8)) return INT_MIN;
                    if (is_negative)
                        nums = nums * 10 - temp;
                    else
                        nums = nums * 10 + temp;
                }
                else if (flag && str[i] == '-') {
                    is_negative = true;
                    flag = false;
                }
                else if (flag && str[i] == '+') {
                    is_negative = false;
                    flag = false;
                }
                else if (flag && str[i] == ' ') {
                    continue;
                }
                else {
                    return 0;
                }
            } else {
                break;
            }
        }
        return nums;
    }
};

int main() {
    string str = "  +2332";

    Solution s;
    int value = s.myAtoi(str);
    cout << value << endl;
}
