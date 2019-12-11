
/**
 * Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 Note: m and n will be at most 100.
 * Created by DCLab on 12/16/2015.
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<unsigned int> dp(n, 0);  //TODO 这里用unsigned防止溢出
        dp[0] = 1;
        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j]==1) dp[j] = 0;
                else if(j>0) dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
//public class UniquePathsII {
//
//    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
//        int n = obstacleGrid[0].length;
//        int[] dp = new int[n];
//        dp[0] = 1;
//        for (int[] row : obstacleGrid) {
//            for (int j = 0; j < n; j++) {
//                if (row[j]==1) dp[j] = 0;
//                else if (j>0) dp[j] += dp[j-1];
//            }
//        }
//        return dp[n-1];
//    }
//
//    //动态规划：res[i][j]=res[i-1][j]+res[i][j-1] 与UniquePaths一样,多了障碍判断
//    public int uniquePathsWithObstacles1(int[][] obstacleGrid) {
//        int m = obstacleGrid.length, n = obstacleGrid[0].length;
//        int[][] dp = new int[m][n];
//        for(int i=0; i<m; i++){
//            if(obstacleGrid[i][0]==1) break;
//            dp[i][0] = 1;
//        }
//        for(int j=0; j<n; j++){
//            if(obstacleGrid[0][j]==1) break;
//            dp[0][j] = 1;
//        }
//        for(int i=1; i<m; i++){
//            for(int j=1; j<n; j++){
//                if(obstacleGrid[i][j]!=1){
//                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
//                }
//            }
//        }
//        return dp[m-1][n-1];
//    }
//
//}
