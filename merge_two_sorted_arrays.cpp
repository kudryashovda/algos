// https://leetcode.com/problems/merge-sorted-array/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        
        int right_pos_nums1 = m + n - 1;
        
        --m;
        --n;
        while (n >= 0 && m >= 0) {
            if (nums2[n] >= nums1[m]) {
                nums1[right_pos_nums1] = nums2[n];
                --n;
            } else {
                nums1[right_pos_nums1] = nums1[m];
                --m;
            }
            --right_pos_nums1;
        }
        
        while (m > 0) {
            if (nums1[m] < nums1[m - 1]) {
                swap(nums1[m - 1], nums1[m]);
            }
            --m;
        }

        while (n >= 0) {
            nums1[n] = nums2[n];
            --n;
        }
    }
};
