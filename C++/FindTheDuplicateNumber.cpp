
/**Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 find the duplicate one.
 Note:
 You must not modify the array (assume the array is read only).
 You must use only constant, O(1) extra space.
 Your runtime complexity should be less than O(n2).
 There is only one duplicate number in the array, but it could be repeated more than once.
 * Created by eugene on 16/5/24.
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
//public class FindTheDuplicateNumber {
//    /**
//     * 详细解释参考 https://segmentfault.com/a/1190000003817671
//     * 时间O(N),空间 O(1).
//     * 将数组下标与其值映射起来,若有重复值,则连续映射下去会出现环路,环路的起点就是重复值.
//     用快慢两个下标都从0开始，快下标每轮映射两次，慢下标每轮映射一次，直到两个下标再次相同。保持慢下标位置不变，
//     再用一个新的下标从0开始，这两个下标都继续每轮映射一次，当这两个下标相遇时，就是环的起点(重复的数)。
//     */
//    public int findDuplicate(int[] nums) {
//        int slow = nums[0];
//        int fast = nums[nums[0]];
//        while (slow!=fast){
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        }
//        int i = 0;
//        while (slow!=i){
//            slow = nums[slow];
//            i = nums[i];
//        }
//        return i;
//    }
//
//    //时间O(NlogN),空间O(1).二分法:注意与中点序号比较的是count值
//    public int findDuplicate1(int[] nums) {
//        int l = 0, r = nums.length-1;
//        while (l<=r){
//            int m = l+(r-l)/2;
//            int count = 0;
//            for (int i=0; i<nums.length; i++){
//                if (nums[i]<=m) count++;
//            }
//            if (count<=m) l = m+1;
//            else r = m-1;
//        }
//        return l;
//    }
//
//    //brute force
//    public int findDuplicate2(int[] nums) {
//        int len = nums.length;
//        for (int i=0; i<len; i++){
//            for (int j=i+1; j<len; j++){
//                if (nums[i]==nums[j]) return nums[i];
//            }
//        }
//        return -1;
//    }
//
//}
