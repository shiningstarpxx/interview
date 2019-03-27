/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (33.46%)
 * Total Accepted:    36.9K
 * Total Submissions: 109.9K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

/*  Explain 1: 用虚拟数据的方式，优雅的实现下标寻找
   偶数情况
   A[1, 2, 3, 4]=>A'[#, 1, #, 2, #, 3, #, 4, #]        

     0  1  2  3      0  1  2  3  4  5  6  7  8

     first step: c1 = 8 / 2 = 4,    l1的下标: (c1 - 1) / 2 = 1  => orign l1 = A[1] = 2; r1的下标： c1 / 2 = 2, r1 = A[2] = 3;

    奇数情况
    B[1, 2, 3]=>B'[#, 1, #, 2, #, 3, #]
      0  1  2      0  1  2  3  4  5  6

    first step: c1 = 6 / 2 = 3,    l1的下标: (c1 - 1) / 2 = 1  => orign l1 = A[1] = 2; r1的下标： c1 / 2 = 1, r1 = A[1] = 2;

    Explain 2:   c2 = m + n - c1;
    A, B 找到两个分隔后要实现 left(A) + left(B) = right(A) + right(B), 对于原始的A，B来说分割点是i， j
    也就是 i + j = n - i + m - j => 2 * j = n + m - 2 * i, 也就是c2 = n + m - c1
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = 2 * n;
        int c1, c2;
        int l1, l2, r1, r2;
        while (low <= high) {
            c1 = (low + high) / 2;
            c2 = m + n - c1;
            l1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1)/2];
            r1 = (c1 >= 2*n) ? INT_MAX : nums1[c1 / 2];
            l2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1)/2];
            r2 = (c2 >= 2*m) ? INT_MAX : nums2[c2 / 2];

            if (l1 > r2)
                high = c1 - 1;
            else if (l2 > r1)
                low = c1 + 1;
            else break;
        }
        return (max(l1, l2) + min(r1, r2)) / 2.0;
    }
};

