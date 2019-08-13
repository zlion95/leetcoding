#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct index_height{
    int index;
    int height;
};

int MAX = numeric_limits<int>::max();

bool index_height_compare(struct index_height i, struct index_height j)
{
    return i.height > j.height;
}

class Solution {
public:
    // 排除不可能作为最终边的索引上的值
    void erase_heights(vector<int> &height, int left, int right) {
        for (int i = left + 1; i < right; ++i) {
            height[i] = 0;
        }
    }

    int maxArea(vector<int>& height) {
        vector<struct index_height> index_heights;
        int i, j;
        int max_square = 0, high, square;

        if (height.size() == 2) return min(height[0], height[1]);
        for (i = 0; i < height.size(); ++i) {
            struct index_height p = {
                index: i,
                height: height[i]
            };
            index_heights.push_back(p);
        }
        sort(index_heights.begin(), index_heights.end(), index_height_compare);

        int left = MAX, right = -1;
        for (i = 0; i < index_heights.size(); ++i) {
            struct index_height ihigh = index_heights[i];
            if (height[ihigh.index] == 0) continue;
            if (ihigh.index > right) right = ihigh.index;
            if (ihigh.index < left) left = ihigh.index;
            erase_heights(height, left, right);

            int max_length = 0;
            for (j = 0; j < i; ++j) {
                if (height[index_heights[j].index] == 0) continue;
                max_length = max(max_length, abs(ihigh.index - index_heights[j].index));
            }
            max_square = max(max_square, max_length * ihigh.height);
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
