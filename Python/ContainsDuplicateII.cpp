
/**Given an array of integers and an integer k, find out whether there are two distinct indices i and j
 in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 * Created by eugene on 16/4/14.
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = m.find(nums[i]);
            if(iter == m.end()) m[nums[i]] = i;
            else{
                if(i - m[nums[i]] <= k) return true;
                else m[nums[i]] = i;
            }
        }
        return false;
    }
};

//public class ContainsDuplicateII {
//
//    public boolean containsNearbyDuplicate(int[] nums, int k) {
//        HashMap<Integer, Integer> map = new HashMap<>();
//        for (int i=0; i<nums.length; i++){
//            if (!map.containsKey(nums[i])) map.put(nums[i], i);
//            else {
//                if (i-map.get(nums[i])<=k) return true;
//                else map.put(nums[i], i);
//            };
//        }
//        return false;
//    }
//
//}
