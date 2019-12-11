
/**Given an array of integers, find out whether there are two distinct indices i and j
 in the array such that the difference between nums[i] and nums[j] is at most t
 and the difference between i and j is at most k.
 * Created by eugene on 16/4/14.
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {//O(nlog(k)),借助map维护窗口[i,i+k]
        map<long, int> m;//num->index, TODO 注意不能用map<int, int>
        for(int i=0; i<nums.size(); ++i){
            auto it = m.lower_bound((long)nums[i]-t);//找到大于等于nums[i]-t的最小数，注意不是大于等于nums[i]+t的最小数
            if(it==m.end()) m[nums[i]] = i;
            else{
                if(abs(it->first-nums[i])<=t) return true;
                else m[nums[i]] = i;
            }
            if(i>=k) m.erase(nums[i-k]);    //TODO 勿漏移除k窗口之外的数
        }
        return false;
    }
};
//public class ContainsDuplicateIII {
//    /**
//     * O(nlog(k)),借助TreeSet维护窗口k
//     * http://www.programcreek.com/2014/06/leetcode-contains-duplicate-iii-java/
//     */
//    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
//        if (k < 1 || t < 0) return false;
//        TreeSet<Integer> set = new TreeSet<>();
//        for (int i=0; i<nums.length; i++) {
//            int n = nums[i];
//            if ((set.floor(n)!=null && n-set.floor(n)<=t)
//                    || (set.ceiling(n)!=null && set.ceiling(n)-n<=t))
//                return true;
//            set.add(n);
//            if (i>=k) set.remove(nums[i-k]);
//        }
//        return false;
//    }
//
//    //(此法超时)维护窗口k, 注意边界情况 [-1,2147483647] 1 2147483647
//    public boolean containsNearbyAlmostDuplicate1(int[] nums, int k, int t) {
//        if (nums==null || nums.length<=1) return false;
//        int i, j;
//        int len;
//        if (nums.length-1<=k) len = nums.length-1;
//        else len = k;
//        for (i=0; i<=len; i++){
//            for (j=i+1; j<=len; j++){
//                if (i!=j && Math.abs((long)nums[j]-nums[i])<=t) return true;
//            }
//        }
//        if (nums.length-1<=k) return false;
//        for (i=k+1; i<nums.length; i++){    //窗口滚动
//            for (j=i-k; j<i; j++){
//                if (Math.abs((long)nums[j]-nums[i])<=t) return true;
//            }
//        }
//        return false;
//    }
//
//}
