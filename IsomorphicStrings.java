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

    public boolean isIsomorphic(String s, String t) {
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
