
/**You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise). 方阵
 Follow up: Could you do this in-place?
 * Created by DCLab on 12/1/2015.
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {//TODO 先行逆转再转置
        int m = matrix.size();
        for (int i = 0; i < m / 2; ++i) {
            swap(matrix[i], matrix[m-i-1]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
//public class RotateImage {
//
//    /**先行逆转再转置
//     * 1 2 3     7 8 9     7 4 1
//     * 4 5 6  => 4 5 6  => 8 5 2
//     * 7 8 9     1 2 3     9 6 3
//     */
//    public void rotate(int[][] matrix) {
//        int len = matrix.length;
//        for(int i=0; i<len/2; i++){
//            int[] temp = matrix[i];
//            matrix[i] = matrix[len-i-1];
//            matrix[len-i-1] = temp;
//        }
//        for(int i=0; i<len; i++){
//            for(int j=i; j<len; j++){
//                int temp = matrix[i][j];
//                matrix[i][j] = matrix[j][i];
//                matrix[j][i] = temp;
//            }
//        }
//    }
//
//}
