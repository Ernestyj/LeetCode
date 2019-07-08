
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
//public class LongestSubstringWithoutRepeatingCharacters {
//
//    /**https://leetcode.com/discuss/23883/11-line-simple-java-solution-o-n-with-explanation
//     * 简洁清晰,滑动窗口法O(n),借助HashMap
//     * @param s
//     * @return
//     */
//    public int lengthOfLongestSubstring(String s) {
//        if (s.length()==0) return 0;
//        HashMap<Character, Integer> map = new HashMap<>();
//        int max = 0;
//        for (int r=0, l=0; r<s.length(); ++r){
//            if (map.containsKey(s.charAt(r))){
//                l = Math.max(l, map.get(s.charAt(r))+1);    //TODO l,r pointers only move forward
//            }
//            map.put(s.charAt(r), r);    //update pos
//            max = Math.max(max, r-l+1);
//        }
//        return max;
//    }
//
//
//    /**滑动窗口法O(n)
//     * 思路：维护一个窗口，每次关注窗口中的字符串，在每次判断中，左窗口和右窗口选择其一向前移动。
//     * 同样是维护一个HashSet,①正常情况下移动右窗口，如果没有出现重复则继续移动右窗口；
//     * ②如果发现重复字符，则说明当前窗口中的串已经不满足要求，继续移动右窗口不可能得到更好的结果，
//     * 此时移动左窗口，直到不再有重复字符为止，中间跳过的这些串中不会有更好的结果，
//     * 因为他们不是重复就是更短。
//     *
//     * 复杂度：因为左窗口和右窗口都只向前，所以两个窗口都对每个元素访问不超过一遍，
//     * 因此时间复杂度为O(2*n)=O(n),是线性算法。空间复杂度为HashSet的size,也是O(n)。
//     * http://blog.csdn.net/linhuanmars/article/details/19949159
//     * @param s
//     * @return
//     */
//    public int lengthOfLongestSubstring1(String s) {
//        if (s == null || s.length() == 0) return 0;
//        if (s.length() == 1) return 1;
//        char[] chars = s.toCharArray();
//        Set<Character> set = new HashSet<>();
//        int r = 0, l = 0;
//        int max = 0;
//        for ( ; r < chars.length; r++){
//            if (!set.contains(chars[r])) set.add(chars[r]);
//            else {
//                if (max < r-l) max = r-l;
//                while (chars[r] != chars[l]){
//                    set.remove(chars[l]);
//                    l++;
//                }
//                l++;
//            }
//        }
//        return Math.max(max, r-l);
//    }
//
//
//    /**O(n^2)
//     * 思路：每次定一个起点pre，然后从起点走到有重复字符位置，过程用一个HashSet维护当前字符集，
//     * 认为是constant操作，这样算法要进行两层循环，复杂度是O(n^2)
//     * 参考http://blog.csdn.net/likecool21/article/details/10858799中的图
//     * @param s
//     * @return
//     */
//    public static int lengthOfLongestSubstring2(String s) {
//        if (s == null || s.length() == 0) return 0;
//        if (s.length() == 1) return 1;
//        char[] arr = s.toCharArray();
//        Map<Character, Integer> map = new HashMap<Character, Integer>();
//        int pre = 0;
//        for (int i = 0; i < arr.length; i++) {
//            if (!map.containsKey(arr[i])) {
//                map.put(arr[i], i);
//            } else {
//                pre = Math.max(pre, map.size());
//                i = map.get(arr[i]);
//                map.clear();
//            }
//        }
//        return Math.max(pre, map.size());
//    }
//
//}
