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
        int[] preProfit = new int[len];
        int[] postProfit = new int[len];
        int min = prices[0];
        for (int i=1; i<len; i++){
            min = Math.min(min, prices[i]);
            preProfit[i] = Math.max(preProfit[i-1], prices[i]-min); //注意是i-1
        }
        int max = prices[len-1];
        for (int i=len-2; i>=0; i--){
            max = Math.max(max, prices[i]);
            postProfit[i] = Math.max(postProfit[i+1], max-prices[i]);   //注意是i+1
        }
        int profit = 0;
        for (int i=0; i<len; i++){
            profit = Math.max(profit, preProfit[i]+postProfit[i]);
        }
        return profit;
    }
    //超时
    public int maxProfit1(int[] prices) {
        int len = prices.length;
        int min = Integer.MAX_VALUE;
        int preProfit = 0;
        int postProfit = 0;
        int profit = 0;
        for (int k=0; k<len; k++){
            for (int i=0; i<k; i++){
                min = Math.min(min, prices[i]);
                preProfit = Math.max(preProfit, prices[i]-min);
            }
            min = Integer.MAX_VALUE;
            for (int j=k; j<len; j++){
                min = Math.min(min, prices[j]);
                postProfit = Math.max(postProfit, prices[j]-min);
            }
            profit = Math.max(profit, preProfit+postProfit);
        }
        return profit;
    }

}
