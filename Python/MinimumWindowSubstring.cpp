
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
        int i = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];    //先扫描一遍T，把对应的字符及其出现的次数存到 HashMap 中
        for (int j = 0; j < s.size(); ++j) {//开始遍历S，就把遍历到的字母对应的HashMap中的value减一，如果减1后仍大于等于0，cnt自增1
            if (--letterCnt[s[j]] >= 0) ++cnt; //in t
            //如果cnt等于T串长度时开始循环，纪录一个字串并更新最小字串值；然后将子窗口的左边界向右移，如果某个移除掉的字母是T串中不可缺少的字母，那么cnt自减1(表示此时T串并没有完全匹配)
            while (cnt == t.size()) {   //valid
                if (minLen > j - i + 1) {   //update min len
                    minLen = j - i + 1;
                    res = s.substr(i, minLen);
                }
                //对于不在T串中的字母的映射值也这么加减，因为对于不在T串中的字母，我们减1后变-1，cnt不会增加；之后收缩左边界的时候，映射值加1后为0，cnt也不会减少，所以没有什么影响
                if (++letterCnt[s[i]] > 0) --cnt;   //make it invalid 收缩
                ++i;
            }
        }
        return res;
    }
};
//public class MinimumWindowSubstring {
//
//    /**https://leetcode.com/discuss/94871/java-4ms-bit-97-6%25
//     * TODO 此法可作为substring类题目解答模板
//     * 简洁. 双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，
//     然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的。
//     */
//    public String minWindow(String s, String t) {
//        char[] sArr = s.toCharArray();
//        char[] tArr = t.toCharArray();
//        int[] map = new int[256];
//        int j = 0, i = 0;
//        int count = tArr.length;
//        int minLen = Integer.MAX_VALUE;
//        int minI = 0;
//        for(char c: tArr) map[c]++;
//        while(j<s.length()) {
//            if(map[sArr[j]]>0) count--; //in t
//            map[sArr[j]]--; //TODO 此行不能移入上述if块
//            while(count==0) {   //valid
//                if((j-i+1) < minLen) {  //update min len and min start
//                    minLen = j-i+1;
//                    minI = i;
//                }
//                map[sArr[i]]++;
//                if(map[sArr[i]]>0) count++; //make it invalid 收缩
//                i++;
//            }
//            j++;
//        }
//        if(minI+minLen > s.length()) return "";
//        return s.substring(minI, minI+minLen);
//    }
//
//
//    /**与上面方法一样
//     * http://blog.csdn.net/linhuanmars/article/details/20343903
//     * 双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，
//     * 然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的。
//     * @param s
//     * @param t
//     * @return
//     */
//    public String minWindow1(String s, String t) {
//        if(s==null || s.length()==0) return "";
//        HashMap<Character, Integer> bookT = new HashMap<>();
//        //建立T字典
//        for(int i=0; i<t.length(); i++) {
//            if(bookT.containsKey(t.charAt(i))) {
//                bookT.put(t.charAt(i), bookT.get(t.charAt(i))+1);
//            }else {
//                bookT.put(t.charAt(i), 1);
//            }
//        }
//        int left = 0;
//        int count = 0;
//        int minLen = s.length()+1;  //+1用来判断无匹配的极端情况
//        int minStart = 0;
//        //尾指针不断往后扫
//        for(int right=0; right<s.length(); right++) {
//            if(bookT.containsKey(s.charAt(right))) {
//                bookT.put(s.charAt(right), bookT.get(s.charAt(right))-1);
//                if(bookT.get(s.charAt(right))>=0) {
//                    count++;
//                }
//                //当扫到有一个窗口包含了所有T的字符后，然后再收缩头指针，直到不能再收缩为止
//                while(count == t.length()) {
//                    if(right-left+1 < minLen) { //更新
//                        minLen = right-left+1;
//                        minStart = left;
//                    }
//                    if(bookT.containsKey(s.charAt(left))) {     //left收缩
//                        bookT.put(s.charAt(left), bookT.get(s.charAt(left))+1);
//                        if(bookT.get(s.charAt(left))>0) {
//                            count--;
//                        }
//                    }
//                    left++;
//                }
//            }
//        }
//        if(minLen>s.length()) return "";
//        //最后记录所有可能的情况中窗口最小的
//        return s.substring(minStart, minStart+minLen);
//    }
//
//}
