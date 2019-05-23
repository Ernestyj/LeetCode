

/**Write an algorithm to determine if a number is "happy".
 A happy number is a number defined by the following process: Starting with
 any positive integer, replace the number by the sum of the squares of its digits,
 and repeat the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1. Those numbers
 for which this process ends in 1 are happy numbers.
 https://leetcode.com/problems/happy-number/
 * Created by eugene on 16/4/1.
 */
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(slow>1){
            slow = squareSum(slow);
            if(slow==1) return true;
            fast = squareSum(squareSum(fast));
            if(fast==1) return true;
            if(fast==slow) return false;
        }
        return true;//TODO n=1的时候
    }
    int squareSum(int n){
        int sum = 0, curN;
        while(n>0){
            curN = n%10;
            sum += curN*curN;
            n = n/10;
        }
        return sum;
    }
};

//public class HappyNumber {
//
//    //快慢法:比下面的方法更快,空间更少
//    public boolean isHappy(int n) {
//        int slow = n;
//        int fast = n;
//        while(slow>1){
//            slow = squareSum(slow) ;
//            if(slow==1) return true ;
//            fast = squareSum(squareSum(fast));
//            if(fast==1) return true ;
//            if(slow==fast) return false;
//        }
//        return true ;
//    }
//    int squareSum(int n) {
//        int sum = 0, tmp;
//        while (n>0) {
//            tmp = n%10;
//            sum += tmp*tmp;
//            n /= 10;
//        }
//        return sum;
//    }
//
//
//    //代码简短,注意跳出循环的关键在于记录出现过的数
//    public boolean isHappy1(int n) {
//        Set<Integer> set = new HashSet<>();
//        while (!set.contains(n)) {
//            set.add(n);
//            n = squareSum(n);
//            if (n==1) return true;
//        }
//        return false;
//    }
//    //digitSquareSum另一种计算方法
//    private int compute(int n){
//        char[] chars = String.valueOf(n).toCharArray();
//        int sum = 0;
//        for (char c : chars){
//            int i = Integer.valueOf(c-'0'); //TODO Integer.valueOf(c)将得到ASCII值
//            sum += i*i;
//        }
//        return sum;
//    }
//
//}
