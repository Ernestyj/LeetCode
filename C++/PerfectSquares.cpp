
/**Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 * Created by eugene on 16/5/20.
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int k = 1; k <= n; ++k) {
            dp[k] = dp[k-1]+1;
            int i = 2;
            while(k-i*i>=0){
                int temp = dp[k-i*i]+1;
                if(temp<dp[k]) dp[k] = temp;
                ++i;
            }
        }
        return dp[n];
    }
};
//public class PerfectSquares {
//
//    /**https://leetcode.com/discuss/62526/an-easy-understanding-dp-solution-in-java
//     dp[0] = 0
//     dp[1] = dp[0]+1 = 1
//     dp[2] = dp[1]+1 = 2
//     dp[3] = dp[2]+1 = 3
//     dp[4] = Min{ dp[4-1*1]+1, dp[4-2*2]+1 } = Min{ dp[3]+1, dp[0]+1 } = 1
//     dp[5] = Min{ dp[5-1*1]+1, dp[5-2*2]+1 } = Min{ dp[4]+1, dp[1]+1 } = 2
//     ...
//     dp[13] = Min{ dp[13-1*1]+1, dp[13-2*2]+1, dp[13-3*3]+1 } = Min{ dp[12]+1, dp[9]+1, dp[4]+1 } = 2
//     ...
//     * DP: dp[k] = Min{ dp[k-i*i]+1 },  n-i*i>=0 && i>=1
//     */
//    public int numSquares(int n) {
//        int[] dp = new int[n+1];
//        dp[0] = 0;
//        for (int k=1; k<=n; k++){
//            dp[k] = dp[k-1]+1;
//            int i = 2;
//            while (k-i*i>=0){
//                int temp = dp[k-i*i]+1;
//                if (temp<dp[k]) dp[k] = temp;
//                i++;
//            }
//        }
//        return dp[n];
//    }
//
//}
