package leetcode71_80;

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 This matrix has the following properties:
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 Consider the following matrix:
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 Given target = 3, return true.
 * Created by DCLab on 12/26/2015.
 */
public class Search2DMatrix {

    //与Search2DMatrixII代码完全一样,从右上角开始搜
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

    //将矩阵看成数组
    public boolean searchMatrix1(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int l = 0, r = m*n-1;
        while (l<=r) {
            int mid = (l+r)/2;
            if (matrix[mid/n][mid%n] == target)  return true;
            if (matrix[mid/n][mid%n] < target)  l = mid+1;
            else r = mid-1;
        }
        return false;
    }



}
