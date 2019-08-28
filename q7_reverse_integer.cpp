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
};


int main() {
    int num;
    cin >> num;
    Solution s;
    cout << s.reverse(num) << endl;;
}
