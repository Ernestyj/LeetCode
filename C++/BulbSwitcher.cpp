
/**There are n bulbs that are initially off. You first turn on all the bulbs.
 Then, you turn off every second bulb. On the third round, you toggle every third bulb
 (turning on if it's off or turning off if it's on). For the ith round,
 you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
 Example:
 Given n = 3.
 At first, the three bulbs are [off, off, off].
 After first round, the three bulbs are [on, on, on].
 After second round, the three bulbs are [on, off, on].
 After third round, the three bulbs are [on, off, off].
 So you should return 1, because there is only one bulb is on.
 * Created by eugene on 16/6/17.
 */
class Solution {
public:
    int bulbSwitch(int n) { //找出规律:结果为1有3个,结果为2有5个,结果为3有7个...(n=3是1,n=5是2,n=7是3),或问题就简化为求1到n之间完全平方数的个数
        int count = 0, i = 1;
        while (i * i <= n) ++count, ++i;
        return count;
    }

    int bulbSwitch(int n) { //进化
        int res = 1;
        while (res * res <= n) ++res;
        return res - 1;
    }

    int bulbSwitch(int n) { //再进化
        return sqrt(n);
    }
};
//public class BulbSwitcher {
//
//    //下面解法进一步简化
//    public static int bulbSwitch(int n) {
//        return (int)Math.sqrt(n);
//    }
//
//    //找出规律:结果为1有3个,结果为2有5个,结果为3有7个...
//    public static int bulbSwitch1(int n) {
//        if (n<=0) return 0;
//        for (int i=1; i<Integer.MAX_VALUE; i++){
//            int sum = (2+i)*i;  //ai = 3+2*(i-1); 等差数列求和
//            if (sum>=n) return i;
//        }
//        return 0;
//    }
//
//    //模拟方法,超时
//    public static int bulbSwitch2(int n) {
//        boolean[] bulbs = new boolean[n];
//        for (int i=0; i<n; i++){
//            for (int j=i; j<n; j+=(i+1)){
//                bulbs[j] = !bulbs[j];
//            }
//        }
//        int res = 0;
//        for (boolean b: bulbs)
//            if (b) res++;
//        return res;
//    }
//
//}
