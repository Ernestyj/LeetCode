package leetcode71_80;

/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * Could you devise a constant space solution?
 * Created by DCLab on 12/25/2015.
 */
public class SetMatrixZeroes {

    /**
     * O(1)解法：用第0行和第0列来记录第1~m-1行和第1~n-1列是否需要置0。
     * 而用两个变量记录第0行和第0列是否需要置0。
     * TODO 注意：直接用0来标记需要置零，不要使用其他标记，这样第0行、第0列可以不用额外处理。
     * @param matrix
     */
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int zeroRow = 1, zeroCol = 1;
        int i, j;
        //mark zeros on first row and column
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                if (matrix[i][j] == 0){
                    if (i==0) zeroRow = 0;
                    if (j==0) zeroCol = 0;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //set each elements by using marks in first row and column.
        for (i=1; i<m; i++)
            for (j=1; j<n; j++)
                if (matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
        //Set first column and row by using marks in first step.
        if (zeroRow==0)
            for (j=0; j<n; j++) matrix[0][j] = 0;
        if (zeroCol==0)
            for (i=0; i<m; i++) matrix[i][0] = 0;
    }

}
