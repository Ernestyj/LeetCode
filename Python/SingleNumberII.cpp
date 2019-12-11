
/**Given an array of integers, every element appears three times except for one.
 Find that single one.
 Note: Your algorithm should have a linear runtime complexity.
 Could you implement it without using extra memory?
 * Created by eugene on 16/2/25.
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 31; i >= 0; --i) { //不是++i
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += nums[j]>>i & 1;  //nums[j]>>i & 1 是取第i位值(0或1)
            }
            result = (result<<1) + sum%3;
        }
        return result;
    }
};
public class SingleNumberII {

    /**TODO 重温记忆
     * http://bangbingsyb.blogspot.co.id/2014/11/leetcode-single-number-i-ii.html
     * 由于x^x^x = x，无法直接利用I的方法来解。
     但可以应用类似的思路，即利用位运算来消除重复3次的数。以一个数组[14 14 14 9]为例，
     将每个数字以二进制表达：
     1110
     1110
     1110
     1001
     _____
     4331    对每一位进行求和
     1001    对每一位的和做%3运算，来消去所有重复3次的数
     */
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int i=31; i>=0; i--){
            int sum = 0;
            int mask = 1<<i;
            for (int j=0; j<nums.length; j++){
                if ((nums[j] & mask) != 0) sum++;
            }
            result = (result<<1) + sum%3;
        }
        return result;
    }

    //哈希表
    public int singleNumber2(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<nums.length; i++){
            if (!map.containsKey(nums[i])){
                map.put(nums[i], 1);
            } else {
                map.put(nums[i], map.get(nums[i])+1);
            }
        }
        for (Integer i : map.keySet()){
            if (map.get(i)!=3) return i;
        }
        return -1;
    }

}
