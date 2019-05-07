package leetcode241_250;

import java.util.HashMap;

/**Given two strings s and t, write a function to determine if t is an anagram of s.
 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
 Note: You may assume the string contains only lowercase alphabets.
 * Created by eugene on 16/5/6.
 */
public class ValidAnagram {

    //简洁
    public boolean isAnagram(String s, String t) {
        int[] map = new int[26];
        for (int i=0; i<s.length(); i++) map[s.charAt(i)-'a']++;
        for (int i=0; i<t.length(); i++) map[t.charAt(i)-'a']--;
        for (int i: map) if (i != 0) return false;
        return true;
    }

    public boolean isAnagram1(String s, String t) {
        if (s.length()!=t.length()) return false;
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if (!map.containsKey(c)) map.put(c, 1);
            else map.put(c, map.get(c)+1);
        }
        for (int i=0; i<t.length(); i++) {
            char c = t.charAt(i);
            if (!map.containsKey(c)) return false;
            else map.put(c, map.get(c)-1);
        }
        for (Integer i: map.values()) {
            if (i!=0) return false;
        }
        return true;
    }

}
