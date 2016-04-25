package leetcode61_70;

/**
 * Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 Note: m and n will be at most 100.
 * Created by DCLab on 12/16/2015.
 */
public class UniquePathsII {

    public static void main(String[] args) {
//        int[][] obstacleGrid = {{0,0,0},
//                                {0,1,0},
//                                {0,0,0}};
        int[][] obstacleGrid = {{1}};
        System.out.println("*****RESULT*****");
        System.out.println(new UniquePathsII().uniquePathsWithObstacles(obstacleGrid));
    }


    /**
     * 动态规划：res[i][j]=res[i-1][j]+res[i][j-1]
     * @param obstacleGrid
     * @return
     */
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        int[][] res = new int[m][n];
        int i=0, j=0;
        for (i=0; i<m; i++){
            if (obstacleGrid[i][0] == 1) break;
            res[i][0] = 1;
        }
        for (j=0; j<n; j++){
            if (obstacleGrid[0][j] == 1) break;
            res[0][j] = 1;
        }
        for (i=1; i<m; i++){
            for (j=1; j<n; j++){
                if (obstacleGrid[i][j] != 1){
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
        }
        return res[i-1][j-1];
    }

}
