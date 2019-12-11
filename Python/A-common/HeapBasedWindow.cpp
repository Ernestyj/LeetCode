
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

