package leetcode121_130;

/**Given a string, determine if it is a palindrome, considering only
 alphanumeric characters and ignoring cases.
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.(amanaplanacanalpanama)
 "race a car" is not a palindrome.(raceacar)
 Note: Have you consider that the string might be empty?
 For the purpose of this problem, we define empty string as valid palindrome.
 * Created by eugene on 16/2/13.
 */
public class ValidPalindrome {

    /**
     * 正则表达式与双指针。
     * @param s
     * @return
     */
    public boolean isPalindrome(String s) {
        if (s==null) return false;
        if (s.length()<=1) return true;
        s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        int l=0, r=s.length()-1;
        while (l<r){
            if (s.charAt(l++)!=s.charAt(r--)) return false;
        }
        return true;
    }

}
