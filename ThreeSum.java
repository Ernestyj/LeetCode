package leetcode11_20;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.

 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.

 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)
 *
 * Created by DCLab on 11/4/2015.
 */
public class ThreeSum {

    /**https://leetcode.com/discuss/23638/concise-o-n-2-java-solution
     * O(n^2) 先快排，再枚举第一个数，然后对余下数的求2sum(由于数组有序,采用二分法,同时注意去重)
     * @param num
     * @return
     */
    public List<List<Integer>> threeSum(int[] num) {
        Arrays.sort(num);
        List<List<Integer>> res = new LinkedList<>();
        for (int i = 0; i < num.length-2; i++) {
            if (i==0 || (i>0 && num[i]!=num[i-1])) {  // Skip same results
                int l = i+1, r = num.length-1, sum = 0-num[i];
                while (l<r) {
                    if (num[l]+num[r]==sum) {
                        res.add(Arrays.asList(num[i], num[l], num[r]));
                        while (l<r && num[l]==num[l+1]) l++;   // Skip same results
                        while (l<r && num[r]==num[r-1]) r--;   // Skip same results
                        l++; r--;
                    } else if (num[l]+num[r]<sum) l++;
                    else r--;
                }
            }
        }
        return res;
    }

}
