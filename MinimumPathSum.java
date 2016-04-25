package leetcode61_70;

/**
 * Given a m x n grid filled with non-negative numbers, find a path
 * from top left to bottom right which minimizes the sum of all numbers along its path.
 Note: You can only move either down or right at any point in time.
 * Created by DCLab on 12/17/2015.
 */
public class MinimumPathSum {

    public static void main(String[] args) {
        int[][] grid = {{0,0,0},
                                {0,1,0},
                                {0,0,0}};
//        int[][] grid = {{1}};
        System.out.println("*****RESULT*****");
        System.out.println(new MinimumPathSum().minPathSum(grid));
    }


    /**
     * 动态规划：res[i][j]=grid[i][j] + Min(res[i-1][j], res[i][j-1])
     * @param grid
     * @return
     */
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] res = new int[m][n];
        int i=0, j=0;
        res[0][0] = grid[0][0];
        for (i=1; i<m; i++){
            res[i][0] = grid[i][0] + res[i-1][0];
        }
        for (j=1; j<n; j++){
            res[0][j] = grid[0][j] + res[0][j-1];
        }
        for (i=1; i<m; i++){
            for (j=1; j<n; j++){
                res[i][j] = grid[i][j] + Math.min(res[i-1][j], res[i][j-1]);
            }
        }
        return res[i-1][j-1];
    }

}
