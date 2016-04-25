package leetcode31_40;

/**
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
 If such arrangement is not possible, it must rearrange it as the lowest possible order
 (ie, sorted in ascending order).
 The replacement must be in-place, do not allocate extra memory.
 * 对序列大小的比较做出定义：两个长度相同的序列，从两者的第一个元素开始向后比较，
 * 直到出现一个不同元素（也可能就是第它们的第一个元素），该元素较大的序列为大，
 * 反之序列为小；若一直到最后一个元素都相同，那么两个序列相等。
 * 对于一个任意序列，最小的序列是增序，最大的序列为减序。
 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are
 in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 *
 * Created by DCLab on 11/14/2015.
 */
public class NextPermutation {

    public static void main(String[] args) {
        int[] nums1 = {1, 1, 5};
//        reverse(nums1, 0, 4);
//        for (int i : nums1) System.out.print(i + " ");
        System.out.println("*****RESULT*****");
        nextPermutation(nums1);
        for (int i : nums1) System.out.print(i + " ");
    }

    /**
     * http://blog.csdn.net/jeasn168/article/details/39047685
     * 假设一个有m个元素的序列pn，其下一个较大序列为pn+1。
     * 1) 若pn最右端的2个元素构成一个增序子序列，那么直接反转这2个元素使该子序列成为减序，即可得到pn+1。
     * 2) 若pn最右端一共有连续的s个元素构成一个减序子序列，令i = m - s，则有pn(i) < pn(i+1)，
        其中pn(i)表示排列pn的第i个元素。因此若将pn(i)和其右边的子集s{pn(i+1), pn(i+2), ..., pn(m)}
        中任意一个元素调换必能得到一个较大的序列（不一定是下一个）。
        要保证是下一个较大的序列，必须保持pn(i)左边的元素不动，并在子集s{pn(i+1), pn(i+2), ..., pn(m)}
        中找出所有比pn(i)大的元素中最小的一个pn(j)，然后将二者调换位置。
        现在只要使新子集{pn(i+1), pn(i+2), ..., pn(i), ...,pn(m)}成为最小序列即得到pn+1。
        然而新子集仍保持减序，那么此时直接将其反转即可得到
        pn+1 {pn(1), pn(2), ..., pn(j), pn(m), pn(m-1), ..., pn(i), ..., pn(i+2), pn(i+1)}。
     ex. 3 6 4 2
         4 6 3 2
         4 2 3 6
     * @param nums
     */
    public static void nextPermutation(int[] nums) {
        if (nums == null) return;
        int len = nums.length;
        if (len == 0 || len == 1) return;
        int i = 0;
        //pn最右端的2个元素构成一个增序子序列
        if (nums[len - 1] > nums[len - 2]){
            swap(nums, len - 1, len - 2);
            return;
        }
        //pn最右端一共有连续的s个元素构成一个减序子序列
        for (i = len - 2; i >= 0; i--){
            //pn是一个非递增序列
            if (i == 0 && nums[0] >= nums[1]){
                reverse(nums, 0, len - 1);
                return;
            }
            if (nums[i] < nums[i + 1]) break;
        }
        int theI = i;
        for (i = len - 1; i > theI; i--){
            if (nums[theI] < nums[i]) break;
        }
        swap(nums, theI, i);
//        System.out.println((theI + 1) + " " + (len - 1));
        reverse(nums, theI + 1, len - 1);
    }
    private static void reverse(int[] nums, int l, int r) {
        int mid = (l + r) / 2;
        int count = r - l + 1;
        for(int i = l; i <= mid; i++){
            if (count % 2 == 0) swap(nums, i, i + (mid - i) * 2 + 1);
            else swap(nums, i, i + (mid - i) * 2);
        }
    }
    private static void swap(int[] s, int i, int j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}
