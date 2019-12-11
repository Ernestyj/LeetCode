
/**A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 The robot can only move either down or right at any point in time.
 The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 How many possible unique paths are there?
 Note: m and n will be at most 100.
 * Created by DCLab on 12/15/2015.
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                res[j] += res[j-1];
            }
        }
        return res[n-1];
    }
};
//public class UniquePaths {
//
//    /**
//     * 动态规划：res[i][j]=res[i-1][j]+res[i][j-1]，在递归基础上用一个数组来保存历史结果，降低时间复杂度；
//     * 为简化存储，只需要用一个一维数组存上一行的信息即可。
//     * 时间复杂度：O(m*n)；空间复杂度：O(n)。
//     * 参考：http://blog.csdn.net/linhuanmars/article/details/22126357
//     */
//    public int uniquePaths(int m, int n) {
//        int[] res = new int[n]; //存上一行的信息
//        res[0] = 1;
//        for(int i=0; i<m; i++)  //m-1+1，多出一行存初始值
//            for(int j=1; j<n; j++)  //n-1
//                res[j] += res[j-1];  //更新新一行的信息
//        return res[n-1];
//    }
//
//    /**
//     * 转化为组合数求解：从m+n-2个位置中挑选n-1个位置；C(n, k)=n(n-1)(n-2)...(n-k+1)/k!
//     * 注意：要计算阶乘的部分用double，否则很容易越界；
//     * 时间复杂度：O(min(m,n))，因为只需做一次行或者列的扫描；
//     * 空间复杂度：O(1)。
//     */
//    public int uniquePaths1(int m, int n) {
//        double numerator = 1;
//        double denominator = 1;
//        int small = m<n ? m-1 : n-1;
//        for(int i=1; i<=small; i++) {
//            denominator *= i;
//            numerator *= (m+n-2)+1-i;
//        }
//        return (int)(numerator/denominator);
//    }
//
//}
