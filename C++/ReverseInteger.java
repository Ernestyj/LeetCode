package leetcode1_10;

/**Reverse digits of an integer.
 Example1: x = 123, return 321
 Example2: x = -123, return -321
 * Created by eugene on 16/4/20.
 */
public class ReverseInteger {

    //空间O(1)
    public int reverse(int x) {
        long rev = 0;
        while(x!= 0){
            rev = rev*10 + x%10;
            x = x/10;
            if( rev>Integer.MAX_VALUE || rev<Integer.MIN_VALUE)
                return 0;
        }
        return (int)rev;
    }

    //空间O(n)
    public int reverse1(int x) {
        if (x==0 || x==Integer.MIN_VALUE) return 0; //TODO Integer.MIN_VALUE时也返回0
        int n = x;
        if (x<0) n = -n;
        StringBuilder s = new StringBuilder(String.valueOf(n)).reverse();
        int i = 0;
        while (s.charAt(i)=='0') i++;
        long l = Long.valueOf(s.substring(i));
        if (l>Integer.MAX_VALUE) return 0;
        if (x<0) l = -l;
        return (int)l;
    }

}
