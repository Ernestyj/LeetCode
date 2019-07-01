
/**
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.
 Return the maximum product you can get.
Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
*/
class Solution {
public:
    /**
     * 题目提示中让我们用O(n)来解题，而且告诉我们找7到10之间的规律，那么我们一点一点的来分析：

正整数从1开始，但是1不能拆分成两个正整数之和，所以不能当输出。
那么2只能拆成1+1，所以乘积也为1。
数字3可以拆分成2+1或1+1+1，显然第一种拆分方法乘积大为2。
数字4拆成2+2，乘积最大，为4。
数字5拆成3+2，乘积最大，为6。
数字6拆成3+3，乘积最大，为9。
数字7拆为3+4，乘积最大，为12。
数字8拆为3+3+2，乘积最大，为18。
数字9拆为3+3+3，乘积最大，为27。
数字10拆为3+3+4，乘积最大，为36。
     发现数字7拆分结果是数字4的三倍，而7比4正好大三，数字8拆分结果是数字5的三倍，而8比5大3，后面都是这样的规律，
     那么我们可以把数字6之前的拆分结果都列举出来，然后之后的数通过查表都能计算出来
     */
    int integerBreak(int n) {
        vector<int> dp{0,0,1,2,4,6,9};
        for (int i = 7; i <= n; ++i) {
            dp.push_back(3*dp[i-3]);
        }
        return dp[n];   //TODO 注意不能用dp.back()，因为初始化了0~6的情况
    }
};