
/**Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (ie,
 buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * Created by eugene on 16/2/10.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minPrice = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            minPrice = min(prices[i], minPrice);
            profit = max(prices[i]-minPrice, profit);
        }
        return profit;
    }
};

//public class BestTimeToBuyAndSellStock {
//
//    /**
//     * 最一般的方法是嵌套遍历找到最大买入卖出差,但超时.
//     一维动态规划(双重):记录出现过的最低价作为买入价格,计算当天售出的收益.
//     P(i)=Max(P(i-1), price[i]-B(i))
//     B(i)=Min(B(i-1), price[i])
//     * @param prices
//     * @return
//     */
//    public int maxProfit(int[] prices) {
//        if(prices.length<=1) return 0;
//        int min = prices[0], profit = 0;
//        for(int i=1; i<prices.length; i++){
//            min = Math.min(min, prices[i]);
//            profit = Math.max(profit, prices[i]-min);
//        }
//        return profit;
//    }
//
//}
