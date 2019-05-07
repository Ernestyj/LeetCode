package leetcode301_310;

/**Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined
 by its upper left corner (row1, col1) and lower right corner (row2, col2).

 Example: Given matrix = [
 [3, 0, 1, 4, 2],
 [5, 6, 3, 2, 1],
 [1, 2, 0, 1, 5],
 [4, 1, 0, 1, 7],
 [1, 0, 3, 0, 5]
 ]
 sumRegion(2, 1, 4, 3) -> 8
 sumRegion(1, 1, 2, 2) -> 11
 sumRegion(1, 2, 2, 4) -> 12
 Note:
 You may assume that the matrix does not change.
 There are many calls to sumRegion function.
 You may assume that row1 ≤ row2 and col1 ≤ col2.
 * Created by eugene on 16/6/6.
 */
public class RangeSumQuery2DImmutable {

    //简洁
    public class NumMatrix {
        private int[][] dp;

        public NumMatrix(int[][] matrix) {
            if(matrix==null || matrix.length==0 || matrix[0].length==0) return;
            int m = matrix.length;
            int n = matrix[0].length;
            dp = new int[m+1][n+1];
            for(int i=1; i<=m; i++){
                for(int j=1; j<=n; j++){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1] ;
                }
            }
        }

        public int sumRegion(int row1, int col1, int row2, int col2) {
            int iMin = Math.min(row1, row2);
            int iMax = Math.max(row1, row2);
            int jMin = Math.min(col1, col2);
            int jMax = Math.max(col1, col2);
            return dp[iMax+1][jMax+1] - dp[iMax+1][jMin] - dp[iMin][jMax+1] + dp[iMin][jMin];
        }
    }


    public class NumMatrix1 {

        int[][] sum;

        public NumMatrix1(int[][] matrix) {
            if (matrix==null || matrix.length==0) return;
            int m = matrix.length, n = matrix[0].length;
            sum = new int[m][n];
            sum[0][0] = matrix[0][0];
            for (int i=1; i<m; i++){
                sum[i][0] = sum[i-1][0]+matrix[i][0];
            }
            for (int j=1; j<n; j++){
                sum[0][j] = sum[0][j-1]+matrix[0][j];
            }
            for (int i=1; i<m; i++){
                for (int j=1; j<n; j++){
                    sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];
                }
            }
        }

        public int sumRegion(int row1, int col1, int row2, int col2) {
            int res = sum[row2][col2];
            if (col1-1>=0) res -= sum[row2][col1-1];
            if (row1-1>=0) res -= sum[row1-1][col2];
            if (row1-1>=0 && col1-1>=0) res += sum[row1-1][col1-1];
            return res;
        }
    }


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix = new NumMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
}
