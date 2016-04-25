package leetcode51_60;

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 If the last word does not exist, return 0.
 Note: A word is defined as a character sequence consists of non-space characters only.
 For example,
 Given s = "Hello World",
 return 5.
 * Created by DCLab on 12/11/2015.
 */
public class LengthfLastWord {

    public static void main(String[] args) {
        String s = "   ";
        System.out.println("*****RESULT*****");
        System.out.println(new LengthfLastWord().lengthOfLastWord(s));
    }


    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) return 0;
        String[] strings = s.split(" ");
        if (strings == null || strings.length == 0) return 0;
        System.out.println(strings.length);
        String last = strings[strings.length - 1];
        return last.length();
    }
}
