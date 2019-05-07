package leetcode281_290;

import java.util.HashMap;
import java.util.HashSet;

/**Given a pattern and a string str, find if str follows the same pattern.
 Here follow means a full match, such that there is a bijection between a letter in pattern
 and a non-empty word in str.
 Examples:
 pattern = "abba", str = "dog cat cat dog" should return true.
 pattern = "abba", str = "dog cat cat fish" should return false.
 pattern = "aaaa", str = "dog cat cat dog" should return false.
 pattern = "abba", str = "dog dog dog dog" should return false.
 Notes:
 You may assume pattern contains only lowercase letters,
 and str contains lowercase letters separated by a single space.
 * Created by eugene on 16/5/26.
 */
public class WordPattern {

    //简洁
    public boolean wordPattern(String pattern, String str) {
        String[] strings = str.split(" ");
        if (strings.length != pattern.length()) return false;
        HashMap index = new HashMap();  //TODO 没有指定类型
        for (Integer i=0; i<strings.length; ++i){   //TODO Integer不能写成int
            if (index.put(pattern.charAt(i), i) != index.put(strings[i], i))
                return false;
        }
        return true;
    }

    public boolean wordPattern1(String pattern, String str) {
        String[] strings = str.split(" ");
        if (pattern.length()!=strings.length) return false;
        HashMap<Character, String> map = new HashMap<>();
        HashSet<String> set = new HashSet<>();
        for (int i=0; i<pattern.length(); i++){
            char c = pattern.charAt(i);
            if (!map.containsKey(c)) {
                if (!set.contains(strings[i])) {
                    map.put(c, strings[i]);
                    set.add(strings[i]);
                }
                else return false;
            } else {
                if (!map.get(c).equals(strings[i])) return false;
            }
        }
        return true;
    }

}
