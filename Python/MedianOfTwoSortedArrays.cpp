
/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log(m + n)).
 *
 * Created by DCLab on 11/23/2015.
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//TODO 此题各种解法都相对较难,花时间理解
        //这对奇偶数均适用。若 m+n 为奇数的话，那么其实 (m+n+1) / 2 和 (m+n+2) / 2 的值相等，相当于两个相同的数字相加再除以2，还是其本身。
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        // 要对K二分，需要分别在 nums1 和 nums2 中查找第 K/2 个元素，注意这里由于两个数组的长度不定，所以有可能某个数组没有第 K/2 个数字，
        // 所以需要先 check 一下数组中到底存不存在第 K/2 个数字，如果存在就取出来，否则就赋值上一个整型最大值。Ex. nums1 = {3}，nums2 = {2, 4, 5, 6, 7}，K=4
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        // 最后就是二分法的核心：比较这两个数组的第 K/2 小的数字 midVal1 和 midVal2 的大小，
        // 如果第一个数组的第 K/2 个数字小的话，那么说明我们要找的数字肯定不在 nums1 中的前 K/2 个数字，所以我们可以将其淘汰，
        // 将 nums1 的起始位置向后移动 K/2 个，并且此时的K也自减去 K/2，调用递归（Ex. nums1 = {1, 3}，nums2 = {2, 4, 5}，K=4）
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};

//public class MedianOfTwoSortedArrays {
//
//    /**O(log(m + n)) TODO 此题各种解法都相对较难,花时间理解
//     * http://blog.csdn.net/yutianzuijin/article/details/11499917
//     * https://leetcode.com/discuss/67341/concise-java-solution-based-on-binary-search
//     * 将原问题转变成一个寻找第k小数的问题（假设两个原序列升序排列），这样中位数实际上是第(m+n)/2小的数。
//     * 递归法：实现寻找第k小的数。
//     * 首先假设数组A和B的元素个数都大于k/2（且暂不考虑奇偶）：
//     * 当A[k/2-1]<B[k/2-1],表示A[0]到A[k/2-1]的元素都在A和B合并之后的前k小的元素中,可以跳过；
//     * 当A[k/2-1]>B[k/2-1],表示B[0]到B[k/2-1]的元素都在A和B合并之后的前k小的元素中,可以跳过；
//     * 当A[k/2-1]=B[k/2-1]时，我们已经找到了第k小的数。
//     * @param nums1
//     * @param nums2
//     * @return
//     */
//    public static double findMedianSortedArrays(int nums1[], int nums2[]) {
//        int len = nums1.length + nums2.length;
//        if (len%2==1)
//            return findKth(nums1, 0, nums2, 0, len/2+1);
//        return (findKth(nums1, 0, nums2, 0, len/2) +
//                findKth(nums1, 0, nums2, 0, len/2+1)) / 2.0;
//    }
//    // find kth number of two sorted array
//    private static int findKth(int[] A, int lA, int[] B, int lB, int k){
//        if (lA>=A.length) return B[lB+k-1];
//        if (lB>=B.length) return A[lA+k-1];
//        if (k==1) return Math.min(A[lA], B[lB]);
//        int A_mid = lA+k/2-1<A.length ? A[lA+k/2-1] : Integer.MAX_VALUE;
//        int B_mid = lB+k/2-1<B.length ? B[lB+k/2-1] : Integer.MAX_VALUE;
//        if (A_mid < B_mid) {
//            return findKth(A, lA+k/2, B, lB, k-k/2);
//        } else {
//            return findKth(A, lA, B, lB+k/2, k-k/2);
//        }
//    }
//
//
//    /** O(log(m + n)) TODO 较难理解,放弃
//     * http://www.programcreek.com/2012/12/leetcode-median-of-two-sorted-arrays-java/
//     * This problem can be converted to the problem of finding kth element,
//     k is (A's length + B' Length)/2.
//     * @param nums1
//     * @param nums2
//     * @return
//     */
//    public static double findMedianSortedArrays1(int nums1[], int nums2[]) {
//        int m = nums1.length;
//        int n = nums2.length;
//        if ((m+n)%2 != 0) // odd
//            return (double) findKth(nums1, nums2, (m+n)/2, 0, m-1, 0, n-1);
//        else { // even
//            return (findKth(nums1, nums2, (m+n)/2, 0, m-1, 0, n-1)
//                    + findKth(nums1, nums2, (m+n)/2-1, 0, m-1, 0, n-1))*0.5;
//        }
//    }
//    private static int findKth(int A[], int B[], int k, int lA, int rA, int lB, int rB) {
//        int lenA = rA-lA + 1;
//        int lenB = rB-lB + 1;
//        // Handle special cases
//        if (lenA==0) return B[lB+k];
//        if (lenB==0) return A[lA+k];
//        if (k==0) return A[lA]<B[lB] ? A[lA] : B[lB];
//
//        int mA = lenA*k/(lenA+lenB); // a's middle count TODO ???
//        int mB = k-mA-1; // b's middle count
//        // make mA and mB to be array index
//        mA = mA+lA;
//        mB = mB+lB;
//        if (A[mA]>B[mB]) {
//            k = k-(mB-lB+1);
//            rA = mA;
//            lB = mB+1;
//        } else {
//            k = k-(mA-lA+1);
//            rB = mB;
//            lA = mA+1;
//        }
//        return findKth(A, B, k, lA, rA, lB, rB);
//    }
//
//
//}
