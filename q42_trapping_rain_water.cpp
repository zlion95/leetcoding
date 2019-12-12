#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> height_stack, temp_stack;
    int up = 0, down = 0;

    int get2watermark(int cur) {
        if (height_stack.empty()) {
            up = cur;
            height_stack.push(cur);
            return 0;
        }

        if (cur <= down) {
            height_stack.push(cur);
            down = cur;
            return 0;
        } else if (cur < up) {
            int trap = 0, count = 0;
            while (!height_stack.empty()) {
                ++count;
                trap += max(cur - height_stack.top(), 0);
                height_stack.pop();
            }
            height_stack.push(up);
            while (count--) height_stack.push(cur);
            down = cur;
            return trap;
        } else {
            int trap = 0;
            while (!height_stack.empty()) {
                trap += up - height_stack.top();
                height_stack.pop();
            }
            height_stack.push(cur);
            up = cur;
            down = 0;
            return trap;
        }
    }

    int trap(vector<int> &height) {
        int cur, trap = 0;

        for (int i = 0; i < height.size(); ++i) {
            cur = height[i];
            trap += get2watermark(cur);
        }
        return trap;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int n, value;
    vector<int> height;

    cin >> n;
    while (n) {
        cin >> value;
        height.push_back(value);
        cout << value << " ";
        --n;
    }
    cout << endl;
    cout << s.trap(height) << endl;
}
