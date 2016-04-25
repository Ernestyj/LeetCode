package leetcode201_210;

import java.util.HashSet;
import java.util.Set;

/**Write an algorithm to determine if a number is "happy".
 A happy number is a number defined by the following process: Starting with
 any positive integer, replace the number by the sum of the squares of its digits,
 and repeat the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1. Those numbers
 for which this process ends in 1 are happy numbers.
 https://leetcode.com/problems/happy-number/
 * Created by eugene on 16/4/1.
 */
public class HappyNumber {

    public static void main(String[] args) {
        System.out.println(new HappyNumber().isHappy(1));
    }

    //跳出循环的关键在于记录出现过的数
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (!set.contains(n)) {
            set.add(n);
            n = compute(n);
            if (n==1) return true;
        }
        return false;
    }
    private int compute(int n){
        char[] chars = String.valueOf(n).toCharArray();
        int sum = 0;
        for (char c : chars){
            int i = Integer.valueOf(c-'0'); //TODO Integer.valueOf(c)将得到ASCII值
            sum += i*i;
        }
        return sum;
    }

}
