#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 2) return min(height[0], height[1]);

        int max_square = 0, high, square;
        for (int i = 0; i < height.size() - 1; ++i) {
            for (int j = i; j < height.size(); ++j) {
                high = min(height[i], height[j]);
                square = (j - i) * high;
                max_square = max(max_square, square);
            }
        }
        return max_square;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    int n, temp;
    vector<int> height;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        height.push_back(temp);
    }

    cout << s.maxArea(height) << endl;;
    return 0;
}
