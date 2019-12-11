
/**You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 Example 2:
 coins = [2], amount = 3
 return -1.
 Note: You may assume that you have an infinite number of each kind of coin.
 * Created by eugene on 16/6/18.
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {    //完全背包计数问题
        vector<int> dp(amount+1, amount+1); //也可以初始化为INT_MAX
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) { //d(i)=min{ d(i-vj)+1 }，其中i-vj >=0，vj表示第j个硬币的面值, dp[0] = 0
            for(auto& coin: coins){
                if(coin<=i) dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp.back()>amount? -1 : dp.back();
    }

    //迭代的DP解法有一个好基友，就是递归+memo数组的解法，说其是递归形式的DP解法也没错(递归加记忆数组)。
    //其目的都是为了保存中间计算结果，避免大量的重复计算，从而提高运算效率，思路都一样，仅仅是写法有些区别。
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        return coinChangeDFS(coins, amount, memo);
    }
    int coinChangeDFS(vector<int>& coins, int target, vector<int>& memo) {
        if (target < 0) return - 1;
        if (memo[target] != INT_MAX) return memo[target];
        for (int i = 0; i < coins.size(); ++i) {
            int tmp = coinChangeDFS(coins, target - coins[i], memo);
            if (tmp >= 0) memo[target] = min(memo[target], tmp + 1);
        }
        return memo[target] = (memo[target] == INT_MAX) ? -1 : memo[target];
    }
};
//public class CoinChange {
//    /**https://leetcode.com/discuss/76217/java-both-iterative-recursive-solutions-with-explanations
//     * DP, 有点类似背包问题 d(i)=min{ d(i-vj)+1 }，其中i-vj >=0，vj表示第j个硬币的面值;
//     */
//    public int coinChange(int[] coins, int amount) {
//        if (coins==null || coins.length==0 || amount<=0) return 0;
//        int[] dp = new int[amount+1];
//        for (int i=1; i<=amount; i++) {
//            dp[i] = Integer.MAX_VALUE;
//            for (int coin: coins){
//                if (coin<=i && dp[i-coin]!=Integer.MAX_VALUE)
//                    dp[i] = Math.min(dp[i], 1+dp[i-coin]);
//            }
//        }
//        return dp[amount]==Integer.MAX_VALUE? -1 : dp[amount];
//    }
//
//}
