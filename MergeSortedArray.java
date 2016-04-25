package leetcode81_90;

import java.util.Arrays;

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 Note: You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
 elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 * Created by DCLab on 1/9/2016.
 */
public class MergeSortedArray {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] num1Copy = Arrays.copyOf(nums1, m);
        int i=0, j=0;
        while(i<m){
            if (n == 0) break;
            if (num1Copy[i] < nums2[j]){
                nums1[i+j] = num1Copy[i];
                i++;
            } else {
                nums1[i+j] = nums2[j];
                j++;
                if (!(j<n)) break;
            }
        }
        while (i<m){
            nums1[i+j] = num1Copy[i];
            i++;
        }
        while (j<n){
            nums1[i+j] = nums2[j];
            j++;
        }
    }

}
