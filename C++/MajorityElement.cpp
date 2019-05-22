

/**Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 You may assume that the array is non-empty and the majority element always exist in the array.
 * Created by eugene on 16/3/19.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if(count == 0){
                ++count;
                major = nums[i];
            } else if(major == nums[i]){
                ++count;
            } else{
                --count;
            }
        }
        return major;
    }
};

//public class MajorityElement {
//
//    //O(n) time and O(1) space
//    public int majorityElement(int[] num) {
//        int major=num[0], count = 1;
//        for(int i=1; i<num.length;i++){
//            if(count==0){
//                count++;
//                major=num[i];
//            }else if(major==num[i]){
//                count++;
//            }else count--;
//        }
//        return major;
//    }
//
//    //nlog(n)
//    public int majorityElement1(int[] nums) {
//        if (nums.length<=2) return nums[0];
//        Arrays.sort(nums);
//        return nums[nums.length / 2];
//    }
//
//    //n
//    public int majorityElement2(int[] nums) {
//        if (nums.length<=2) return nums[0];
//        int indice = nums.length/2;
//        Map<Integer, Integer> map = new HashMap<>();
//        for (int n : nums){
//            if (!map.containsKey(n)) map.put(n, 1);
//            else{
//                int temp = map.get(n);
//                if (temp+1>indice) return n;
//                map.put(n, temp+1);
//            }
//        }
//        return 0;
//    }
//
//}
