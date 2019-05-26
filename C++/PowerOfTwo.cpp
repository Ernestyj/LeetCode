package leetcode231_240;

/**Given an integer, write a function to determine if it is a power of two.
 * Created by eugene on 16/4/26.
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
};
//public class PowerOfTwo {
//
//    public boolean isPowerOfTwo(int n) {
//        return n>0 && (n&(n-1))==0;
//    }
//
//    public boolean isPowerOfTwo1(int n) {
//        int i = 0;
//        while (true){
//            if (i==32) return false;
//            int num = 1<<i;
//            if (n==num) return true;
//            else if (n<num) return false;
//            i++;
//        }
//    }
//
//    public boolean isPowerOfTwo2(int n) {
//        return n>0 && Integer.bitCount(n) == 1;
//    }
//
//}
