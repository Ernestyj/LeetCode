package leetcode221_230;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 The algorithm should run in linear time and in O(1) space.
 * Created by eugene on 16/4/24.
 */
public class MajorityElementII {

    /**
     * Moore's Voting Algorithm:根据题目有两个候选者,分别为这两个数设置count计数,遍历数组若出现相同的数则加一,否则都减一.
     当任一count为0时,候选者替换为当前数.再遍历一次数组,确认出现次数超过⌊ n/3 ⌋.
     * https://leetcode.com/discuss/69126/concise-java-solution-based-on-moores-voting-algorithm
     * @param nums
     * @return
     */
    public List<Integer> majorityElement(int[] nums) {
        ArrayList<Integer> res = new ArrayList<>();
        int len = nums.length;
        if (len==0) return res;
        int fir = 0, sec = 1;   //TODO 使fir,sec两数保持不同
        int firCount = 0, secCount = 0;
        for (int i=0; i<len; i++) {
            if (fir == nums[i]) firCount++;
            else if (sec == nums[i]) secCount++;
            else if (firCount == 0) {
                fir = nums[i];
                firCount = 1;
            } else if (secCount == 0) {
                sec = nums[i];
                secCount = 1;
            } else {
                firCount--;
                secCount--;
            }
        }
        firCount = 0; secCount = 0;
        for (int i : nums) {    // Count again for x1, x2
            if (i == fir) firCount++;
            else if (i == sec) secCount++;
        }
        if (firCount>len/3) res.add(fir);
        if (secCount>len/3) res.add(sec);
        return res;
    }

}
