package leetcode211_220;

import java.util.Arrays;

/**Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 For example, Given [3,2,1,5,6,4] and k = 2, return 5.
 Note:  You may assume k is always valid, 1 ≤ k ≤ array's length.
 * Created by eugene on 16/4/11.
 */
public class KthLargestElementInArray {

    /**方法总结:
     * 堆:时间 O(NlogK) 空间 O(K)
     * 先排序:时间 O(NlogN) 空间 O(1)(其实空间不止常数项)
     * 快速选择:时间 Avg O(N) Worst O(N^2) 空间 O(1)
     */

    //https://segmentfault.com/a/1190000003704825
    class Solu{
        public int findKthLargest(int[] nums, int k) {
            return quickSelect(nums, k-1, 0, nums.length - 1);
        }
        //返回第k大的索引
        private int quickSelect(int[] arr, int k, int left, int right){
            int pivot = arr[(left + right) / 2];
            int i = left, j = right;
            while(i<=j){
                while(arr[i]>pivot) i++;  // 从左向右找到第一个小于枢纽值的数
                while(arr[j]<pivot) j--;  // 从右向左找到第一个大于枢纽值的数
                if(i<=j){ // 将两个数互换
                    swap(arr, i, j);
                    i++;
                    j--;
                }
            }// 最后退出的情况应该是右指针在左指针左边一格
            // 这时如果右指针还大于等于k，说明kth在左半边
            if(left<j && k<=j) return quickSelect(arr, k, left, j);
            // 这时如果左指针还小于等于k，说明kth在右半边
            if(i<right && k>=i) return quickSelect(arr, k, i, right);
            return arr[k];
        }
        private void swap(int[] a, int i, int j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    /**TODO 巩固
     * https://leetcode.com/discuss/45627/ac-clean-quickselect-java-solution-avg-o-n-time
     * O(n)
     * @param a
     * @param k
     * @return
     */
    public int findKthLargest(int[] a, int k) {
        int n = a.length;
        int p = quickSelect(a, 0, n-1, n-k+1);
        return a[p];
    }
    //返回第k小的索引
    private int quickSelect(int[] a, int lo, int hi, int k) {
        // use quick sort's idea, put nums that are <= pivot to the left, put nums that are  > pivot to the right
        int i = lo, j = hi, pivot = a[hi];
        while (i<j) {
            if (a[i++]>pivot) swap(a, --i, --j);
        }
        swap(a, i, hi);
        int m = i-lo+1; // count the nums that are <= pivot from lo
        if (m==k) return i;   // pivot is the one!
        else if (m>k) return quickSelect(a, lo, i-1, k);    // pivot is too big, so it must be on the left
        else return quickSelect(a, i+1, hi, k-m);// pivot is too small, so it must be on the right
    }
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public int findKthLargest1(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }

}
