
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
class Solution {
public:
    int maxProfit(vector<int>& prices) {//TODO 较难理解，多理解记忆
        if(prices.size()<=1) return 0;
        int buy = INT_MIN, preBuy = buy;    //TODO 注意初始状态，多理解
        int sell = 0, preSell = 0, prepreSell = 0;
        for (int i = 0; i < prices.size(); ++i) {   //i从0开始
            buy = max(prepreSell-prices[i], preBuy);
            sell = max(preBuy+prices[i], preSell);
            preBuy = buy;
            prepreSell = preSell;
            preSell = sell;
        }
        return sell;
    }
};
//public class BestTimeToBuyAndSellStockWithCooldown {
//
//    /**https://leetcode.com/discuss/71354/share-my-thinking-process
//     * DP: 列出初始转移状态再根据规律简化:
//     buy[i] = max(rest[i-1]-price[i], buy[i-1])   buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
//     sell[i] = max(buy[i-1]+price[i], sell[i-1])  sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
//     rest[i] = max(sell[i-1], buy[i-1], rest[i-1]) = sell[i-1] rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。
//     上述递推式很好的表示了在买之前有冷冻期，买之前要卖掉之前的股票。
//     1.一个小技巧是如何保证[buy, rest, buy]的情况不会出现，这是由于buy[i] <= rest[i]， 即rest[i] = max(sell[i-1], rest[i-1])
//     2.由于冷冻期的存在，rest[i]<=sell[i], 我们可以进一步得出rest[i] = sell[i-1]
//     最终简化为:
//     buy[i] = max(sell[i-2]-price, buy[i-1])
//     sell[i] = max(buy[i-1]+price, sell[i-1])
//     DP solution only depending on i - 1 and i - 2 can be optimized using O(1) space.
//     Let b1, b0 represent buy[i - 1], buy[i]
//     Let s2, s1, s0 represent sell[i - 2], sell[i - 1], sell[i]
//     First we define the initial states at i = 0:
//     We can buy. The max profit at i = 0 ending with a buy is -prices[0].
//     We cannot sell. The max profit at i = 0 ending with a sell is 0.
//     */
//    public int maxProfit(int[] prices) {
//        if(prices == null || prices.length <= 1) return 0;
//        int b0 = -prices[0], b1 = b0;
//        int s0 = 0, s1 = 0, s2 = 0;
//        for(int i = 1; i < prices.length; i++) {
//            b0 = Math.max(b1, s2 - prices[i]);
//            s0 = Math.max(s1, b1 + prices[i]);
//            b1 = b0; s2 = s1; s1 = s0;
//        }
//        return s0;
//    }
//
//}
