#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // Two points method
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_square = 0;
        while (i < j) {
            max_square = max(max_square, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--;
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
