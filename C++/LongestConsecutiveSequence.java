package leetcode121_130;

import java.util.HashSet;
import java.util.Set;

/**Given an unsorted array of integers, find the length of
 the longest consecutive elements sequence.
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 Your algorithm should run in O(n) complexity.
 * Created by eugene on 16/2/16.
 */
public class LongestConsecutiveSequence {

    /**
     * http://www.programcreek.com/2013/01/leetcode-longest-consecutive-sequence-java/
     * 因为排序至少要O(nlogn),先排序是不行的.这里使用哈希表. 中间向两边发散法
     * @param nums
     * @return
     */
    public int longestConsecutive(int[] nums) {
        if (nums.length==0) return 0;
        Set<Integer> set = new HashSet<>();
        int longest = 0;
        for (int e : nums) set.add(e);
        for (int e : nums) {
            int left = e-1, right = e+1, count = 1;
            while (set.contains(left)){
                count++;
                set.remove(left);
                left--;
            }
            while (set.contains(right)){
                count++;
                set.remove(right);
                right++;
            }
            longest = Math.max(longest, count);
        }
        return longest;
    }

}
