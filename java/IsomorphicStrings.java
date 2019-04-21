package leetcode201_210;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**Given two strings s and t, determine if they are isomorphic.
 Two strings are isomorphic if the characters in s can be replaced to get t.
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 For example,
 Given "egg", "add", return true.
 Given "foo", "bar", return false.
 Given "paper", "title", return true.
 * Created by eugene on 16/4/2.
 */
public class IsomorphicStrings {

    /**
     * https://leetcode.com/discuss/33889/short-java-solution-without-maps
     * tricky方法,不使用哈希
     */
    public boolean isIsomorphic(String s1, String s2) {
        int[] m = new int[512];
        for (int i = 0; i < s1.length(); i++) {
            if (m[s1.charAt(i)] != m[s2.charAt(i)+256]) return false;
            m[s1.charAt(i)] = m[s2.charAt(i)+256] = i+1;    //+1是因为初始值为0,不能使用0值.
        }
        return true;
    }

    //普通方法,哈希+集合
    public boolean isIsomorphic1(String s, String t) {
        Map<Character, Character> map = new HashMap<>();
        Set<Character> set = new HashSet<>();
        for (int i=0; i<s.length(); i++){
            char c1 = s.charAt(i), c2 = t.charAt(i);
            if (!map.containsKey(c1)) {
                if (!set.contains(c2)) {
                    map.put(c1, c2);
                    set.add(c2);
                } else return false;
            } else {
                if (map.get(c1)!=c2) return false;
            }
        }
        return true;
    }

}
