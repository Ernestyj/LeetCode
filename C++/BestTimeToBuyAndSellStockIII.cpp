
/**Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note: You may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).
 * Created by eugene on 16/2/10.
 */
/**http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
 * 两次一维动态规划组合:以第i天为分界线，计算第i天之前(含)进行一次交易的最大收益preProfit[i]，
 和第i天之后(含)进行一次交易的最大收益postProfit[i]，
 遍历的同时，max{preProfit[i] + postProfit[i]}(0≤i≤n-1)就是最大收益。
 第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。
 上述方法时间复杂度O(n^2),超时.
 优化:用数组暂存结果提速,时间复杂度O(n).
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int len = prices.size();
        vector<int> preP(len, 0), postP(len, 0);
        int minPrice = prices[0];
        for (int i=1; i<len; i++){
            minPrice = min(minPrice, prices[i]);
            preP[i] = max(preP[i-1], prices[i]-minPrice); //注意是i-1
        }
        int maxPrice = prices[len-1], profit = 0;
        for (int i=len-2; i>=0; i--){   //TODO 巧妙点在于从后往前计算
            maxPrice = max(maxPrice, prices[i]);
            postP[i] = max(postP[i+1], maxPrice-prices[i]);   //注意是i+1
            profit = max(profit, preP[i]+postP[i]);    //TODO 同时计算最大收益
        }
        return profit;
    }
};
 //local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。(第 i 天卖第 j 支股票)
 //global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：
 //local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff
 //global[i][j] = max(local[i][j], global[i-1][j])
 //其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，而全局最优比较局部最优和前一天的全局最优.

 //第 i 天卖第 j 支股票的话，一定是下面的一种：
 //1. 今天刚买的
 //那么 Local(i, j) = Global(i-1, j-1)
 //相当于啥都没干(但其实第一种情况是不需要考虑的，因为当天买当天卖不会增加利润，完全是重复操作)
 //2. 昨天买的
 //那么 Local(i, j) = Global(i-1, j-1) + diff
 //等于Global(i-1, j-1) 中的交易，加上今天干的那一票
 //3. 更早之前买的
 //那么 Local(i, j) = Local(i-1, j) + diff
 //昨天别卖了，留到今天卖
class Solution {//TODO 难理解递推式，多记忆
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i]-prices[i-1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = max(g[i-1][j-1], l[i-1][j]) + diff;
                g[i][j] = max(l[i][j], g[i-1][j]);
            }
        }
        return g[n-1][2];
    }
};
//public class BestTimeToBuyAndSellStockIII {
//
//    /**http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
//     * 两次一维动态规划组合:以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，
//     和第i天之后进行一次交易的最大收益postProfit[i]，
//     遍历的同时，max{preProfit[i] + postProfit[i]}(0≤i≤n-1)就是最大收益。
//     第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。
//     上述方法时间复杂度O(n^2),超时.
//     优化:用数组暂存结果提速,时间复杂度O(n).
//     */
//    public int maxProfit(int[] prices) {
//        if (prices.length < 2) return 0;
//        int len = prices.length;
//        int[] preP = new int[len];
//        int[] postP = new int[len];
//        int min = prices[0];
//        for (int i=1; i<len; i++){
//            min = Math.min(min, prices[i]);
//            preP[i] = Math.max(preP[i-1], prices[i]-min); //注意是i-1
//        }
//        int max = prices[len-1], profit = 0;
//        for (int i=len-2; i>=0; i--){   //TODO 巧妙点在于从后往前计算
//            max = Math.max(max, prices[i]);
//            postP[i] = Math.max(postP[i+1], max-prices[i]);   //注意是i+1
//            profit = Math.max(profit, preP[i]+postP[i]);    //TODO 同时计算最大收益
//        }
//        return profit;
//    }
//
//}
