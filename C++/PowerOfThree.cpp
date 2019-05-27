package leetcode321_330;

/**Given an integer, write a function to determine if it is a power of three.
 Follow up:
 Could you do it without using any loop / recursion?
 * Created by eugene on 16/6/22.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n>0) while (n%3==0) n /= 3;
        return n==1;
    }
};
//public class PowerOfThree {
//
//    //Math
//    public boolean isPowerOfThree(int n) {
//        return ( n>0 && 1162261467%n==0); // 1162261467 is 3^19,  3^20 is bigger than int
//    }
//
//    //简单易懂
//    public boolean isPowerOfThree1(int n) {
//        if(n>1) while(n%3==0) n /= 3;
//        return n==1;
//    }
//
//    //超时
//    public boolean isPowerOfThree2(int n) {
//        if (n<1) return false;
//        if (n==1) return true;
//        int num = 1;
//        for (int i=1; i<Integer.MAX_VALUE; i++){
//            num *= 3;
//            if (num==n) return true;
//            if (num>n) return false;
//        }
//        return false;
//    }
//
//}
