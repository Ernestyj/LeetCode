
/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 return the length of last word in the string.
 If the last word does not exist, return 0.
 Note: A word is defined as a character sequence consists of non-space characters only.
 For example,
 Given s = "Hello World",
 return 5.
 * Created by DCLab on 12/11/2015.
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size()-1;
        for (; i>=0 && s[i]==' '; --i) ;
        for (; i>=0 && s[i]!=' '; --i){
            len++;
        }
        return len;
    }
};

//public class LengthOfLastWord {
//
//    //不借助String函数
//    public int lengthOfLastWord(String s) {
//        int len = 0, i = s.length()-1;
//        //ignore the trailing whitespace
//        for (; i>=0 && s.charAt(i)==' '; i--);
//        for (; i>=0 && s.charAt(i)!=' '; i--) {
//            len++;
//        }
//        return len;
//    }
//
//    //简洁
//    public int lengthOfLastWord1(String s) {
//        return s.trim().length()-s.trim().lastIndexOf(" ")-1;
//    }
//
//
//    public int lengthOfLastWord2(String s) {
//        if (s == null || s.length() == 0) return 0;
//        String[] strings = s.split(" ");
//        if (strings == null || strings.length == 0) return 0;
//        String last = strings[strings.length - 1];
//        return last.length();
//    }
//}
