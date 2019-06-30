
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
class Solution {
public:
    void wiggleSort(vector<int>& nums) {//space O(n), 对于space O(1)太难
        vector<int> temp = nums;
        int n = nums.size(), firInd = (n+1)/2, secInd = n;//TODO 这里firInd不取n/2-1，secInd不取n-1，理由如下面解释
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; ++i) {   //对于奇数n，i取偶数的情况比奇数多一种，--firInd会多执行一次，所以上面firInd, secInd取值要这样取
            nums[i] = i&1 ? temp[--secInd] : temp[--firInd];    //TODO i&1==1 表示奇数
        }
    }
};
//public class WiggleSortII {
//    //https://leetcode.com/discuss/77496/ac-java-solution-7ms
//    //actually faster O(nlogn) O(n)
//    // 我们可以先给数组排序，然后在做调整。调整的方法是找到数组的中间的数，相当于把有序数组从中间分成两部分，
//    // 然后从前半段的末尾取一个，在从后半的末尾去一个，这样保证了第一个数小于第二个数，
//    // 然后从前半段取倒数第二个，从后半段取倒数第二个，这保证了第二个数大于第三个数，且第三个数小于第四个数，以此类推直至都取完
//    // 这道题的Follow up让我们用O(n)的时间复杂度和O(1)的空间复杂度，这个真的比较难，参见
//    // https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
//    public void wiggleSort1(int[] nums) {
//        Arrays.sort(nums);
//        int len = nums.length;
//        int[] temp = new int[len];
//        int m = len%2==0? len/2-1 : len/2;
//        int index = 0;
//        for(int i=0; i<=m; i++){
//            temp[index] = nums[m-i];
//            if(index+1<len) temp[index+1] = nums[len-i-1];
//            index = index+2;
//        }
//        for(int i=0; i<len; i++){
//            nums[i] = temp[i];
//        }
//    }
//
//    /**https://leetcode.com/discuss/95156/step-by-step-explanation-of-index-mapping-in-java
//     * index mapping O(n) O(1) TODO 仍未弄清楚此题思路
//     * @param nums
//     */
//    public void wiggleSort(int[] nums) {
//        int median = findKthLargest(nums, (nums.length + 1) / 2);
//        int n = nums.length;
//        int left = 0, i = 0, right = n - 1;
//        while (i <= right) {
//            if (nums[newIndex(i,n)] > median) {
//                swap(nums, newIndex(left++,n), newIndex(i++,n));
//            }
//            else if (nums[newIndex(i,n)] < median) {
//                swap(nums, newIndex(right--,n), newIndex(i,n));
//            }
//            else {
//                i++;
//            }
//        }
//    }
//    private int newIndex(int index, int n) {
//        return (1 + 2*index) % (n | 1);
//    }
//    private int findKthLargest(int[] nums, int k) {
//        return quickSelect(nums, k-1, 0, nums.length - 1);
//    }
//    private int quickSelect(int[] arr, int k, int left, int right){ //返回第k大的索引
//        int pivot = arr[left+(right-left)/2];
//        int l = left, r = right;
//        while(l<=r){
//            while(arr[l]>pivot) l++;  // 从左向右找到第一个小于枢纽值的数
//            while(arr[r]<pivot) r--;  // 从右向左找到第一个大于枢纽值的数
//            if(l<=r){ // 将两个数互换
//                swap(arr, l, r);
//                l++;
//                r--;
//            }
//        }// 最后退出的情况应该是右指针在左指针左边一格
//        if(left<r && k<=r) return quickSelect(arr, k, left, r);// 这时如果右指针还大于等于k，说明kth在左半边
//        if(l<right && k>=l) return quickSelect(arr, k, l, right);// 这时如果左指针还小于等于k，说明kth在右半边
//        return arr[k];
//    }
//    private void swap(int[] a, int i, int j) {
//        int tmp = a[i];
//        a[i] = a[j];
//        a[j] = tmp;
//    }
//
//}
