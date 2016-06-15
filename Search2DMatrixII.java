package leetcode231_240;

/**Write an efficient algorithm that searches for a value in an m x n matrix.
 This matrix has the following properties:
 Integers in each row are sorted in ascending from left to right.
 Integers in each column are sorted in ascending from top to bottom.
 For example, Consider the following matrix:
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 Given target = 20, return false.
 * Created by eugene on 16/5/4.
 */
public class Search2DMatrixII {

    /**
     * 均从右上角开始搜索
     * @param matrix
     * @param target
     * @return
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int i = 0, j = n-1;
        while (i<m && j>=0){
            if (matrix[i][j]==target){
                return true;
            }else if (matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }

}
