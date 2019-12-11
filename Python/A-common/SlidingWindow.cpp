
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


/**Given an array nums, there is a sliding window of size k which is moving from the very left of
 the array to the very right. You can only see the k numbers in the window.
 Each time the sliding window moves right by one position.
 For example, Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 Window position                Max
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 Therefore, return the max sliding window as [3,3,5,5,6,7].
 Note: You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 Follow up: Could you solve it in linear time?
 * Created by eugene on 16/5/3.
 */

class Solution {
public:
    //双向队列保存数字的下标，遍历整个数组，如果此时队列的首元素是 i-k 的话，表示此时窗口向右移了一步，则移除队首元素。
    // 然后比较队尾元素和将要进来的值，如果小的话就都移除，然后此时我们把队首元素加入结果中即可
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();//(保证队列是降序的)窗口中只留下有用的值，没用的全移除掉
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }

    //窗口内的数字是有序的，但是每次给新窗口排序又太费时了，所以最好能有一种类似二叉搜索树的结构，可以在 lgn 的时间复杂度内完成插入和删除操作，
    // 那么使用 STL 自带的 multiset 就能满足我们的需求，这是一种基于红黑树的数据结构，可以自动对元素进行排序，又允许有重复值，完美契合。
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) s.erase(s.find(nums[i - k]));//若超过了k，则需要收缩l
            s.insert(nums[i]);//扩张r(插入当前值)
            if (i >= k - 1) res.push_back(*s.rbegin());//若i >= k-1，说明窗口大小正好是k，就需要将最大值加入结果 res 中
        }
        return res;
    }
};
