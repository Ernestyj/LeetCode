package leetcode321_330;

import java.util.Arrays;

/**Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 Example:
 (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
 (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 Note:
 You may assume all input has valid answer.
 Follow Up:
 Can you do it in O(n) time and/or in-place with O(1) extra space?
 * Created by eugene on 16/6/20.
 */
public class WiggleSortII {

    //https://leetcode.com/discuss/77496/ac-java-solution-7ms
    //actually faster O(nlogn) O(n)
    public void wiggleSort1(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        int[] temp = new int[len];
        int m = len%2==0? len/2-1 : len/2;
        int index = 0;
        for(int i=0; i<=m; i++){
            temp[index] = nums[m-i];
            if(index+1<len) temp[index+1] = nums[len-i-1];
            index = index+2;
        }
        for(int i=0; i<len; i++){
            nums[i] = temp[i];
        }
    }

    /**https://leetcode.com/discuss/95156/step-by-step-explanation-of-index-mapping-in-java
     * index mapping O(n) O(1) TODO 仍未弄清楚此题思路
     * @param nums
     */
    public void wiggleSort(int[] nums) {
        int median = findKthLargest(nums, (nums.length + 1) / 2);
        int n = nums.length;
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[newIndex(i,n)] > median) {
                swap(nums, newIndex(left++,n), newIndex(i++,n));
            }
            else if (nums[newIndex(i,n)] < median) {
                swap(nums, newIndex(right--,n), newIndex(i,n));
            }
            else {
                i++;
            }
        }
    }
    private int newIndex(int index, int n) {
        return (1 + 2*index) % (n | 1);
    }
    private int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, k-1, 0, nums.length - 1);
    }
    private int quickSelect(int[] arr, int k, int left, int right){ //返回第k大的索引
        int pivot = arr[left+(right-left)/2];
        int l = left, r = right;
        while(l<=r){
            while(arr[l]>pivot) l++;  // 从左向右找到第一个小于枢纽值的数
            while(arr[r]<pivot) r--;  // 从右向左找到第一个大于枢纽值的数
            if(l<=r){ // 将两个数互换
                swap(arr, l, r);
                l++;
                r--;
            }
        }// 最后退出的情况应该是右指针在左指针左边一格
        if(left<r && k<=r) return quickSelect(arr, k, left, r);// 这时如果右指针还大于等于k，说明kth在左半边
        if(l<right && k>=l) return quickSelect(arr, k, l, right);// 这时如果左指针还小于等于k，说明kth在右半边
        return arr[k];
    }
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

}
