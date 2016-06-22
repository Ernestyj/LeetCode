package leetcode321_330;

/**You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 Example 2:
 coins = [2], amount = 3
 return -1.
 Note: You may assume that you have an infinite number of each kind of coin.
 * Created by eugene on 16/6/18.
 */
public class CoinChange {

    /**https://leetcode.com/discuss/76217/java-both-iterative-recursive-solutions-with-explanations
     * DP, 有点类似背包问题 d(i)=min{ d(i-vj)+1 }，其中i-vj >=0，vj表示第j个硬币的面值;
     * @param coins
     * @param amount
     * @return
     */
    public int coinChange(int[] coins, int amount) {
        if (coins==null || coins.length==0 || amount<=0) return 0;
        int[] dp = new int[amount+1];
        for (int i=1; i<=amount; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int coin: coins){
                if (coin<=i && dp[i-coin]!=Integer.MAX_VALUE)
                    dp[i] = Math.min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp[amount]==Integer.MAX_VALUE? -1 : dp[amount];
    }

}
