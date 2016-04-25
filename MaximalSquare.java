package leetcode221_230;

/**Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 For example, given the following matrix:
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 4.
 * Created by eugene on 16/4/15.
 */
public class MaximalSquare {

    /**https://segmentfault.com/a/1190000003709497
     * 假设dp[i][j]表示以i,j为右下角的正方形的最大边长，则有
     dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1
     若matrix[i][j]==1,dp[i][j]=0.
     * @param matrix
     * @return
     */
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        if (m==0) return 0;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        int max = 0;
        int i, j;
        for (i=0; i<m; i++) {
            if (matrix[i][0]=='0') dp[i][0] = 0;
            else {
                dp[i][0] = 1;
                max = 1;
            }
        }
        for (j=0; j<n; j++) {
            if (matrix[0][j]=='0') dp[0][j] = 0;
            else {
                dp[0][j] = 1;
                max = 1;
            }
        }
        for (i=1; i<m; i++){
            for (j=1; j<n; j++){
                if (matrix[i][j]=='0') dp[i][j] = 0;
                else {
                    int min = Math.min(dp[i][j-1], dp[i-1][j]);
                    dp[i][j] = Math.min(min, dp[i-1][j-1])+1;
                    if (max<dp[i][j]) max = dp[i][j];
                }
            }
        }
        return max*max;
    }

}
