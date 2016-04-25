package leetcode71_80;

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 * Created by DCLab on 12/26/2015.
 */
public class Search2DMatrix {

    public static void main(String[] args) {
        int[][] matrix = { {1,   3,  5,  7},
                            {10, 11, 16, 20},
                            {23, 30, 34, 50}
                        };
        System.out.println("*****RESULT*****");
        System.out.println(new Search2DMatrix().searchMatrix(matrix, 20));
    }

    //最外层也使用二分搜索
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;
        if (target < matrix[0][0] || target > matrix[row-1][col-1]) return false;
        int l = 0, r = row-1, m = 0;
        while (l <= r){
            m = (l + r) / 2;
            if (target < matrix[m][0]) r = m-1;
            else if (target > matrix[m][0]) l = m+1;
            else return true;
        }
        if (r >= 0){
            if (target == matrix[r][col-1]) return true;
            else if (target < matrix[r][col-1]){
                int res = binarySearch(matrix[r], target);
                return res != -1 ? true : false;
            } else return false;
        }
        return false;
    }
    private int binarySearch(int[] nums, int target){
        int l = 0, r = nums.length - 1;
        int m = 0;
        while (l <= r){
            m = (l + r) / 2;
            if (target < nums[m]) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else return m;  //target == nums[m]
        }
        return -1;
    }


    /**
     * 最外层没使用二分搜索
     * @param matrix
     * @param target
     * @return
     */
    public boolean searchMatrix1(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;
        if (target < matrix[0][0] || target > matrix[row-1][col-1]) return false;
        for (int i=0; i<row; i++){
            if (target == matrix[i][0]) return true;
            else if (target < matrix[i][0]){
                if (i-1 >= 0){
                    if (target == matrix[i-1][col-1]) return true;
                    else if (target < matrix[i-1][col-1]){
                        int res = binarySearch(matrix[i-1], target);
                        return res != -1 ? true : false;
                    } else return false;
                }
            }
        }
        if (target == matrix[row-1][col-1]) return true;
        else if (target < matrix[row-1][col-1]){
            int res = binarySearch(matrix[row-1], target);
            return res != -1 ? true : false;
        }
        return false;
    }

}
