

/**Write a function that takes a string as input and reverse only the vowels of a string.
 Example 1:
 Given s = "hello", return "holle".
 Example 2:
 Given s = "leetcode", return "leotcede".
 * Created by eugene on 16/6/22.
 */
class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        string t = "aeiouAEIOU";
        while(l<r){
            if(t.find(s[l]) == string::npos) ++l;
            else if(t.find(s[r]) == string::npos) --r;
            else swap(s[l++], s[r--]);
        }
        return s;
    }
};
//public class ReverseVowelsOfAString {
//
//    public String reverseVowels(String s) {
//        char[] chars = s.toCharArray();
//        int i = 0, j = chars.length-1;
//        while (i<j){
//            while (i<j && !isVowel(chars[i])) i++;
//            while (i<j && !isVowel(chars[j])) j--;
//            char temp = chars[i]; chars[i] = chars[j]; chars[j] = temp;
//            i++; j--;
//        }
//        return String.valueOf(chars);
//    }
//    private boolean isVowel(char c){
//        for (char ch: new char[]{'a','e','i','o','u','A','E','I','O','U'})
//            if (c==ch) return true;
//        return false;
//    }
//
//}
