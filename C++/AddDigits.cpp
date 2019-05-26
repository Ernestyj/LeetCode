package leetcode251_260;

/**Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 For example:
 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * Created by eugene on 16/5/11.
 */
class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};
//public class AddDigits {
//
//    /**
//     * 结果存在固有的周期性:
//     ~input: 0 1 2 3 4 ...
//     output: 0 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 ....
//     * @param num
//     * @return
//     */
//    public int addDigits(int num) {
//        return 1+(num-1)%9;
//    }
//
//
//    public static int addDigits1(int num) {
//        return addAll(String.valueOf(num));
//    }
//    private static int addAll(String s){
//        if (s.length()==1) return Integer.valueOf(s);
//        int sum = 0;
//        for (int i=0; i<s.length(); i++){
//            sum += Integer.valueOf(s.charAt(i)-'0');    //TODO Integer.valueOf(s.charAt(i))是ASCII值
//        }
//        return addAll(String.valueOf(sum));
//    }
//
//}
