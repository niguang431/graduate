// https://leetcode.cn/problems/merge-sorted-array/
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int i = m;
        int j = n;
        while(i + j > 0) {
            if (i > 0 && j > 0) {
                if (nums1[i-1] <= nums2[j-1]) {
                    nums1[i+j-1] = nums2[j-1];
                    --j;
                } else {
                    nums1[i+j-1] = nums1[i-1];
                    --i;
                }
            } else if (i == 0 && j > 0) {
                nums1[i+j-1] = nums2[j-1];
                --j;
            } else if (i > 0 && j == 0) {
                nums1[i+j-1] = nums1[i-1];
                    --i;
            }
        }
    }
};