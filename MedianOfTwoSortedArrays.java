package leetcode41_50;


import java.util.Stack;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log(m + n)).
 *
 * Created by DCLab on 11/23/2015.
 */
public class MedianOfTwoSortedArrays {

    public static void main(String[] args) {
        int[] nums1 = {};
        int[] nums2 = {1};
        System.out.println("*****RESULT*****");
        double result = findMedianSortedArrays(nums1, nums2);
//        double result = findMedianSortedArrays1(nums1, nums2);
//        double result = new MedianOfTwoSortedArrays().findMedianSortedArrays2(nums1, nums2);
        System.out.println(result);
    }


    /**O(log(m + n))
     * TODO http://blog.csdn.net/yutianzuijin/article/details/11499917
     * 将原问题转变成一个寻找第k小数的问题（假设两个原序列升序排列），这样中位数实际上是第(m+n)/2小的数。
     * 递归法：实现寻找第k小的数。
     * 首先假设数组A和B的元素个数都大于k/2（且暂不考虑奇偶）：
     * 当A[k/2-1]<B[k/2-1]，这表示A[0]到A[k/2-1]的元素都在A和B合并之后的前k小的元素中；
     * 当A[k/2-1]>B[k/2-1]时存在类似的结论；
     * 当A[k/2-1]=B[k/2-1]时，我们已经找到了第k小的数。
     * @param nums1
     * @param nums2
     * @return
     */
    public static double findMedianSortedArrays(int nums1[], int nums2[]) {
        int len = nums1.length + nums2.length;
        if (len % 2 == 1)
            return findKth(nums1, 0, nums2, 0, len / 2 + 1);
        return (findKth(nums1, 0, nums2, 0, len / 2) +
                findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0;
    }
    // find kth number of two sorted array
    private static int findKth(int[] A, int aStart, int[] B, int bStart, int k){
        if (aStart >= A.length)
            return B[bStart + k - 1];
        if (bStart >= B.length)
            return A[aStart + k - 1];
        if (k == 1)
            return Math.min(A[aStart], B[bStart]);
        int A_key = aStart + k/2-1 < A.length
                ? A[aStart + k/2-1] : Integer.MAX_VALUE;
        int B_key = bStart + k/2-1 < B.length
                ? B[bStart + k/2-1] : Integer.MAX_VALUE;
        if (A_key < B_key) {
            return findKth(A, aStart + k/2, B, bStart, k-k/2);
        } else {
            return findKth(A, aStart, B, bStart + k/2, k-k/2);
        }
    }


    /**与上面方法思路基本一致，O(log(m + n))
     * TODO http://www.programcreek.com/2012/12/leetcode-median-of-two-sorted-arrays-java/
     * This problem can be converted to the problem of finding kth element,
     k is (A's length + B' Length)/2.
     * @param nums1
     * @param nums2
     * @return
     */
    public static double findMedianSortedArrays1(int nums1[], int nums2[]) {
        int m = nums1.length;
        int n = nums2.length;
        if ((m + n) % 2 != 0) // odd
            return (double) findKth(nums1, nums2, (m+n)/2, 0, m-1, 0, n-1);
        else { // even
            return (findKth(nums1, nums2, (m+n)/2, 0, m-1, 0, n-1)
                    + findKth(nums1, nums2, (m+n)/2-1, 0, m-1, 0, n-1))*0.5;
        }
    }
    private static int findKth(int A[], int B[], int k, int aStart, int aEnd, int bStart, int bEnd) {
        int aLen = aEnd - aStart + 1;
        int bLen = bEnd - bStart + 1;
        // Handle special cases
        if (aLen == 0) return B[bStart + k];
        if (bLen == 0) return A[aStart + k];
        if (k == 0) return A[aStart] < B[bStart] ? A[aStart] : B[bStart];

        int aMid = aLen * k / (aLen + bLen); // a's middle count TODO ???
        int bMid = k - aMid - 1; // b's middle count

        // make aMid and bMid to be array index
        aMid = aMid + aStart;
        bMid = bMid + bStart;

        if (A[aMid] > B[bMid]) {
            k = k - (bMid - bStart + 1);
            aEnd = aMid;
            bStart = bMid + 1;
        } else {
            k = k - (aMid - aStart + 1);
            bEnd = bMid;
            aStart = aMid + 1;
        }
        return findKth(A, B, k, aStart, aEnd, bStart, bEnd);
    }


    /**
     * 普通思路：利用类似merge的操作找到中位数，利用两个分别指向A和B数组头的指针去遍历数组，
     * 然后统计元素个数，直到找到中位数，此时算法复杂度为O(n)。
     * 但是该方法会存在无穷多的边界细节问题 TODO　边界条件极易出错
     * @param nums1
     * @param nums2
     * @return
     */
    public double findMedianSortedArrays2(int[] nums1, int[] nums2) {
        if (nums1 == null && nums2 == null || nums1.length == 0 && nums2.length == 0) return 0;
        if ((nums1 == null || nums1.length == 0) && nums2 != null && nums2.length != 0) {
            if (nums2.length % 2 != 0) return nums2[nums2.length / 2];
            else return (double)(nums2[nums2.length / 2] + nums2[nums2.length / 2 - 1]) / 2.0d;
        }
        if ((nums2 == null || nums2.length == 0) && nums1 != null && nums1.length != 0) {
            if (nums1.length % 2 != 0) return nums1[nums1.length / 2];
            else return (double)(nums1[nums1.length / 2] + nums1[nums1.length / 2 - 1]) / 2.0d;
        }
        int len = nums1.length + nums2.length;
        int count = len / 2;
        boolean isOdd = len % 2 != 0;
        int i = 0, j = 0;
        Stack<Integer> stack = new Stack<>();
        while (count >= 0){
            if (i >= nums1.length && j >= nums2.length) break;
            else if (i >= nums1.length) {
                stack.push(nums2[j]);
                j++;
            }else if (j >= nums2.length){
                stack.push(nums1[i]);
                i++;
            }else if (nums1[i] <= nums2[j]){
                stack.push(nums1[i]);
                i++;
            }else {
                stack.push(nums2[j]);
                j++;
            }
            count--;
        }
        if (isOdd) return stack.pop();
        else return (double)(stack.pop() + stack.pop()) / 2.0d;
    }

}
