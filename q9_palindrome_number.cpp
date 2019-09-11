#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int nums = 0, j;
        while (x != 0) {
            j = x % 10;
            x /= 10;
            if (nums > INT_MAX / 10 || (nums == INT_MAX / 10 && j > 7)) return 0;
            if (nums < INT_MIN / 10 || (nums == INT_MIN / 10 && j < -8)) return 0;
            nums = nums * 10 + j;
        }
        return nums;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int reverse_value = reverse(x);
        if (reverse_value == x) return true;
        else return false;
    }
};


int main() {
    int x = -122321;
    
    Solution s;
    cout << s.isPalindrome(x) << endl;
}
