package leetcode341_350;

/**Write a function that takes a string as input and returns the string reversed.
 Example: Given s = "hello", return "olleh".
 * Created by eugene on 16/6/22.
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while (l<r){
            char t = s[l];
            s[l++] = s[r];
            s[r--] = t;
            //swap(s[l++], s[r--]);//TODO this is slower
        }
    }
};
//public class ReverseString {
//
//    public String reverseString(String s) {
//        char[] chars = s.toCharArray();
//        int i = 0, j = chars.length-1;
//        while (i<j){
//            char temp = chars[i]; chars[i] = chars[j]; chars[j] = temp;
//            i++; j--;
//        }
//        return String.valueOf(chars);
//    }
//
//    public String reverseString1(String s) {
//        return new StringBuilder(s).reverse().toString();
//    }
//
//}
