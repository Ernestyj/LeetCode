
/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * Could you devise a constant space solution?
 * Created by DCLab on 12/25/2015.
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rZero = false, cZero = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j]==0){
                    if(i==0) rZero = true;
                    if(j==0) cZero = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if(matrix[0][j] == 0 || matrix[i][0]==0) // TODO 注意是==0的条件
                    matrix[i][j] = 0;
            }
        }
        if(cZero)
            for (int i = 0; i < m; ++i)  matrix[i][0] = 0;
        if(rZero)
            for (int j = 0; j < n; ++j)  matrix[0][j] = 0;
    }
};
//public class SetMatrixZeroes {
//
//    /**
//     * O(1)空间解法：用第0行和第0列来记录第1~m-1行和第1~n-1列是否需要置0。
//     * 而用两个变量记录第0行和第0列是否需要置0。
//     * TODO 注意合并写法,不易出错
//     * @param matrix
//     */
//    public void setZeroes(int[][] matrix) {
//        int m = matrix.length, n = matrix[0].length;
//        boolean rZero = false, cZero = false;
//        for(int i=0; i<m; i++){
//            for(int j=0; j<n; j++){
//                if(matrix[i][j]==0) {
//                    if(i==0) rZero = true;
//                    if(j==0) cZero = true;
//                    matrix[0][j] = 0;
//                    matrix[i][0] = 0;
//                }
//            }
//        }
//        for(int i=1; i<m; i++){ //合并写法
//            for(int j=1; j<n; j++){
//                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j] = 0;
//            }
//        }
//        if(rZero) for(int j=0; j<n; j++) matrix[0][j] = 0;
//        if(cZero) for(int i=0; i<m; i++) matrix[i][0] = 0;
//    }
//
//}
