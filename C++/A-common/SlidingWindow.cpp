
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
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum>=s){
                minLen = min(minLen, r-l+1);
                sum -= nums[l++];
            }
        }
        return minLen==INT_MAX? 0:minLen;
    }
};

/**
 * Given a string S and a string T, find the minimum window in S which will contain
 * all the characters in T in complexity O(n).
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 Note: If there is no such window in S that covers all characters in T, return the empty string "".
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 * Created by DCLab on 12/28/2015.
 */
class Solution {
public:
    //双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的。
    //Ex. S = "ADBANC"，T = "ABC"
    string minWindow(string s, string t) {//TODO 此法可作为substring类题目解答模板
        string res = "";
        vector<int> letterCnt(128, 0);
        int l = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];    //先扫描一遍T，把对应的字符及其出现的次数存到 HashMap 中
        for (int r = 0; r < s.size(); ++r) {//开始遍历S，就把遍历到的字母对应的HashMap中的value减一，如果减1后仍大于等于0，cnt自增1
            if (--letterCnt[s[r]] >= 0) ++cnt; //in t
            //如果cnt等于T串长度时开始循环，纪录一个字串并更新最小字串值；然后将子窗口的左边界向右移，如果某个移除掉的字母是T串中不可缺少的字母，那么cnt自减1(表示此时T串并没有完全匹配)
            while (cnt == t.size()) {   //valid
                if (minLen > r - l + 1) {   //update min len
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                //对于不在T串中的字母的映射值也这么加减，因为对于不在T串中的字母，我们减1后变-1，cnt不会增加；之后收缩左边界的时候，映射值加1后为0，cnt也不会减少，所以没有什么影响
                if (++letterCnt[s[l]] > 0) --cnt;   //make it invalid 收缩
                ++l;
            }
        }
        return res;
    }
};