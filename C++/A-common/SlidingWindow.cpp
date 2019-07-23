
/**
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 * Created by DCLab on 11/22/2015.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {    //滑动窗口法O(n)
        unordered_map<char, int> m;
        int maxN = 0, l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if(m.find(s[r]) != m.end()){
                l = max(l, m[s[r]]+1);//TODO 核心 易错
            }
            m[s[r]] = r;
            maxN = max(maxN, r-l+1);
        }
        return maxN;
    }
};


/**Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
 * Created by eugene on 16/4/5.
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {//滑动窗口法:双指针,r指针++, 当sum>=s时l指针++直到sum<s，再r指针++
        if(nums.empty()) return 0;
        int l = 0, r = 0, sum = 0, minLen = INT_MAX;
        while(r<nums.size()){
            sum += nums[r++];
            while (sum>=s){
                minLen = min(minLen, r-l);
                sum -= nums[l++];
            }
        }
        return minLen==INT_MAX? 0:minLen;
    }
};