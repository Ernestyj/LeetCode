
/**Given an array of integers, every element appears twice except for one.
 Find that single one.
 Note: Your algorithm should have a linear runtime complexity.
 Could you implement it without using extra memory?
 * Created by eugene on 16/2/24.
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[0] = nums[0]^nums[i];
        }
        return nums[0];
    }
};

//public class SingleNumber {
//
//    //异或(此法不消耗额外空间),只有两不同位异或才会返回1,所有相同整数异或结果为整数0.
//    public int singleNumber(int[] nums) {
//        if (nums.length==1) return nums[0];
//        for (int i=1; i<nums.length; i++) nums[0] = nums[0]^nums[i];
//        return nums[0];
//    }
//
//    //集合
//    public int singleNumber1(int[] nums) {
//        Set<Integer> set = new HashSet<>();
//        for (int n : nums){
//            if (!set.add(n)) set.remove(n);
//        }
//        return (int)set.toArray()[0];
//    }
//
//    //哈希表
//    public int singleNumber2(int[] nums) {
//        Map<Integer, Integer> map = new HashMap<>();
//        for (int i=0; i<nums.length; i++){
//            if (!map.containsKey(nums[i])){
//                map.put(nums[i], 1);
//            } else {
//                map.put(nums[i], map.get(nums[i])+1);
//            }
//        }
//        for (Integer i : map.keySet()){
//            if (map.get(i)==1) return i;
//        }
//        return -1;
//    }
//
//}
