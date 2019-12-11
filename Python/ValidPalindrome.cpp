
/**Given a string, determine if it is a palindrome, considering only
 alphanumeric characters and ignoring cases.
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.(amanaplanacanalpanama)
 "race a car" is not a palindrome.(raceacar)
 Note: Have you consider that the string might be empty?
 For the purpose of this problem, we define empty string as valid palindrome.
 * Created by eugene on 16/2/13.
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int l = 0, r = s.size()-1;
        while(l<=r){
            if(!isalnum(s[l])) ++l;
            else if(!isalnum(s[r])) --r;//TODO 注意要用else if而不是if
            else {
                if (tolower(s[l]) != tolower(s[r])) return false;
                else {
                    ++l;
                    --r;
                }
            }
        }
        return true;
    }
};

//public class ValidPalindrome {
//
//    //不借助正则,最快
//    public boolean isPalindrome(String s) {
//        if (s.isEmpty()) return true;
//        int l = 0, r = s.length()-1;
//        char c1, c2;
//        while(l<r) {
//            c1 = s.charAt(l); c2 = s.charAt(r);
//            if (!Character.isLetterOrDigit(c1)) l++;
//            else if(!Character.isLetterOrDigit(c2)) r--;
//            else {
//                if (Character.toLowerCase(c1) != Character.toLowerCase(c2)) return false;
//                l++; r--;
//            }
//        }
//        return true;
//    }
//
//    //取巧
//    public boolean isPalindrome1(String s) {
//        String actual = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
//        String rev = new StringBuffer(actual).reverse().toString();
//        return actual.equals(rev);
//    }
//
//    public boolean isPalindrome2(String s) {
//        if (s==null) return false;
//        if (s.length()<=1) return true;
//        s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
//        int l=0, r=s.length()-1;
//        while (l<r){
//            if (s.charAt(l++)!=s.charAt(r--)) return false;
//        }
//        return true;
//    }
//
//}
