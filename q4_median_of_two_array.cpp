#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double getMedian(vector<int>& nums) {
        int m = (nums.size() - 1) / 2;
        if (nums.size() % 2)
            return nums[m];
        else
            return (nums[m] + nums[m + 1]) / 2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return getMedian(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1);
        if (nums1.size() == 0 && nums2.size() != 0) getMedian(nums2);
        if (nums1.size() != 0 && nums2.size() == 0) getMedian(nums1);
        if (nums1.size() == 0 && nums2.size() == 0) return 0;
        int idx1 = 0, idx2 = 0, total = nums1.size() + nums2.size();
        int last = 0, present = 0;
        while (idx1 + idx2 < total / 2) {
            if (idx1 == nums1.size() || idx2 == nums2.size()) break;
            if (nums1[idx1] > nums2[idx2])
                present = nums2[idx2++];
            else
                present = nums1[idx1++];
        }
        if (idx1 + idx2 < total / 2) {
            while (idx1 == nums1.size() && idx1 + idx2 < total / 2) {
                present = nums2[idx2++];
            }
            while (idx2 == nums2.size() && idx1 + idx2 < total / 2) {
                present = nums1[idx1++];
            }
        }

        if (total % 2 && idx1 == nums1.size()) return nums2[idx2];
        else if (total % 2 && idx2 == nums2.size()) return nums1[idx1];
        else if (total % 2) return min(nums1[idx1], nums2[idx2]);
        else if (total % 2 == 0 && idx1 == nums1.size()) return (present + nums2[idx2]) / 2.0;
        else if (total % 2 == 0 && idx2 == nums2.size()) return (present + nums1[idx1]) / 2.0;
        else
            return (present + min(nums1[idx1], nums2[idx2])) / 2.0;
    }
};


int main() {
    int n, m;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; ++i) cin >> nums1[i];
    for (int i = 0; i < n; ++i) cin >> nums2[i];

    vector<int> nums3(0);
    Solution s;
    double median;
    median = s.findMedianSortedArrays(nums3, nums3);
    printf("%lf\n", median);
}