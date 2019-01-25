#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> outputs(2);
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    outputs[0] = i;
                    outputs[1] = j;
                    return outputs;
                }
            }
        }
    }
};


int main() {
    int list[] = {1,2,3,4,5};
    int value = 6;
    vector<int> nums(list, list + sizeof(list) / sizeof(int));
    Solution s;
    vector<int> outputs = s.twoSum(nums, value);
    for (int i = 0; i < outputs.size(); ++i) {
        cout << outputs[i] << "\t";
    }
    cout << endl;
    return 0;
}