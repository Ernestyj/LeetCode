package leetcode211_220;

import java.util.HashMap;

/**
 * Created by eugene on 16/4/13.
 */
public class ContainsDuplicate {

    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<nums.length; i++){
            if (!map.containsKey(nums[i])) map.put(nums[i], 1);
            else return true;
        }
        return false;
    }

}
