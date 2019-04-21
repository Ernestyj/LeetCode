package leetcode1_10;

/**Determine whether an integer is a palindrome. Do this without extra space.
 * Created by eugene on 16/5/31.
 */
public class PalindromeNumber {

    //先逆转整数,注意overflow
    public boolean isPalindrome(int x) {
        if (x==0) return true;
        if (x<0) return false;
        if (reverse(x)==x) return true;
        return false;
    }
    private static int reverse(int x){
        long res = 0;
        while (x!=0){
            res = res*10 + x%10;
            x = x/10;
            if (res>Integer.MAX_VALUE || res<Integer.MIN_VALUE) return 0;
        }
        return (int)res;
    }

}
