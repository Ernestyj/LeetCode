
/**Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array,
 and it should return false if every element is distinct.
 * Created by eugene on 16/4/13.
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if(m.find(nums[i]) != m.end()) return true;
            else ++m[nums[i]];
        }
        return false;
    }
};

//public class ContainsDuplicate {
//
//    public boolean containsDuplicate(int[] nums) {
//        HashMap<Integer, Integer> map = new HashMap<>();
//        for (int i=0; i<nums.length; i++){
//            if (!map.containsKey(nums[i])) map.put(nums[i], 1);
//            else return true;
//        }
//        return false;
//    }
//
//}
