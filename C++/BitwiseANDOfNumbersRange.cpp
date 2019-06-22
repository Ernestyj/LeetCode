
/**Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 For example, given the range [5, 7], you should return 4.
     8  4  2  1
---------------
5 | 0  1  0  1
6 | 0  1  1  0
7 | 0  1  1  1
 * Created by eugene on 16/3/31.
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n>m) n &= n-1; //从n开始&(n-1)，直到结果小于等于m
        return n;
    }
};
//public class BitwiseANDOfNumbersRange {
//
//    //http://www.programcreek.com/2014/04/leetcode-bitwise-and-of-numbers-range-java/
//    public int rangeBitwiseAnd(int m, int n) {
//        while (n>m) n &= n-1;   //依次将n最靠右的1置零,直到小于等于m
//        return n;
//    }
//
//    //超时
//    public int rangeBitwiseAnd1(int m, int n) {
//        int res = m;
//        for (int i=m+1; i<=n; i++) res &= i;
//        return res;
//    }
//
//}
