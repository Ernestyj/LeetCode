package leetcode181_190;

/**Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most k transactions.
 Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * Created by eugene on 16/3/25.
 */
public class BestTimeToBuyAndSellStockIV {
    //TODO 重温
    /**http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
     * 二维DP(可简化为一维):
     错误的递推式:profit[i][j] = max(profit[i – 1][j], profit[i – 1][j – 1] + diff)
     注意两次交易合并的情况,于是引入局部与全局变量,定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润,
     其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，
     两者之中取较大值，而全局最优比较局部最优和前一天的全局最优。
     local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j]+diff)
     global[i][j] = max(local[i][j], global[i-1][j])
     另外,当k大于天数时，其实就退化成Best Time to Buy and Sell Stock II,就不能用DP来做了.
     * @param k
     * @param prices
     * @return
     */
    public int maxProfit(int k, int[] prices) {
        if (prices.length < 2) return 0;
        int days = prices.length;
        if (k >= days) return maxProfit(prices);
        int[][] local = new int[days][k + 1];
        int[][] global = new int[days][k + 1];
        for (int i = 1; i < days ; i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++) {
                local[i][j] = Math.max(global[i-1][j-1]+Math.max(diff, 0), local[i-1][j]+diff);
                global[i][j] = Math.max(global[i-1][j], local[i][j]);
            }
        }
        return global[days - 1][k];
    }
    //退化成Best Time to Buy and Sell Stock II
    private int maxProfit(int[] prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

}
