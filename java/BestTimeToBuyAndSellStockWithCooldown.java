package leetcode301_310;

/**Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 Example:

 prices = [1, 2, 3, 0, 2]
 maxProfit = 3
 transactions = [buy, sell, cooldown, buy, sell]
 * Created by eugene on 16/6/10.
 */
public class BestTimeToBuyAndSellStockWithCooldown {

    /**https://leetcode.com/discuss/71354/share-my-thinking-process
     * DP: 列出初始转移状态再根据规律简化:
     buy[i] = max(rest[i-1]-price[i], buy[i-1])
     sell[i] = max(buy[i-1]+price[i], sell[i-1])
     rest[i] = max(sell[i-1], buy[i-1], rest[i-1]) = sell[i-1]
     最终简化为:
     buy[i] = max(sell[i-2]-price, buy[i-1])
     sell[i] = max(buy[i-1]+price, sell[i-1])
     DP solution only depending on i - 1 and i - 2 can be optimized using O(1) space.
     Let b1, b0 represent buy[i - 1], buy[i]
     Let s2, s1, s0 represent sell[i - 2], sell[i - 1], sell[i]
     First we define the initial states at i = 0:
     We can buy. The max profit at i = 0 ending with a buy is -prices[0].
     We cannot sell. The max profit at i = 0 ending with a sell is 0.
     * @param prices
     * @return
     */
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length <= 1) return 0;
        int b0 = -prices[0], b1 = b0;
        int s0 = 0, s1 = 0, s2 = 0;
        for(int i = 1; i < prices.length; i++) {
            b0 = Math.max(b1, s2 - prices[i]);
            s0 = Math.max(s1, b1 + prices[i]);
            b1 = b0; s2 = s1; s1 = s0;
        }
        return s0;
    }

}
