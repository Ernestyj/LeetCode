
/**Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions
 as you like (ie, buy one and sell one share of the stock multiple times).
 However, you may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).
 * Created by eugene on 16/2/10.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if(prices[i-1]<prices[i]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

//public class BestTimeToBuyAndSellStockII {
//
//    /**
//     * 贪心方法:递增序前后元素差之和.
//     * @param prices
//     * @return
//     */
//    public int maxProfit(int[] prices) {
//        if (prices.length<2) return 0;
//        int profit = 0;
//        for (int i=1; i<prices.length; i++){
//            if (prices[i]>prices[i-1])
//                profit += prices[i]-prices[i-1];
//        }
//        return profit;
//    }
//
//}
