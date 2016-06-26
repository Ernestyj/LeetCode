package leetcode121_130;

/**Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note: You may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).
 * Created by eugene on 16/2/10.
 */
public class BestTimeToBuyAndSellStockIII {

    /**http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
     * 两次一维动态规划组合:以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，
     和第i天之后进行一次交易的最大收益postProfit[i]，
     遍历的同时，max{preProfit[i] + postProfit[i]}(0≤i≤n-1)就是最大收益。
     第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。
     上述方法时间复杂度O(n^2),超时.
     优化:用数组暂存结果提速,时间复杂度O(n).
     * @param prices
     * @return
     */
    public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;
        int len = prices.length;
        int[] preP = new int[len];
        int[] postP = new int[len];
        int min = prices[0];
        for (int i=1; i<len; i++){
            min = Math.min(min, prices[i]);
            preP[i] = Math.max(preP[i-1], prices[i]-min); //注意是i-1
        }
        int max = prices[len-1], profit = 0;
        for (int i=len-2; i>=0; i--){   //TODO 巧妙点在于从后往前计算
            max = Math.max(max, prices[i]);
            postP[i] = Math.max(postP[i+1], max-prices[i]);   //注意是i+1
            profit = Math.max(profit, preP[i]+postP[i]);    //TODO 同时计算最大收益
        }
        return profit;
    }

}
