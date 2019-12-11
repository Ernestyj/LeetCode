
/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 * Created by Eugene on 12/12/2015.
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
         n -= 1;
        int m = n, r = 0, c = 0, k = 1;
        while(r<=m && c<=n){
            for (int i = c; i <= n; ++i) res[r][i] = k++;
            ++r;
            for (int j = r; j <= m; ++j) res[j][n] = k++;
            --n;
            if(r<=m){
                for (int i = n; i >= c; --i) res[m][i] = k++;
                --m;
            }
            if(c<=n){
                for (int j = m; j >= r; --j) res[j][c] = k++;
                ++c;
            }
        }
        return res;
    }
};
//public class SpiralMatrixII {
//
//    //与SpiralMatrix思路一致,此法不易出错
//    public int[][] generateMatrix(int n){
//        int[][] res = new int[n][n];
//        n -= 1;
//        int m = n;
//        int r = 0, c = 0;   //begin
//        int k = 1;
//        while (r<=m && c<=n){
//            for (int j=c; j<=n; j++) res[r][j] = k++;
//            r++;
//            for (int i=r; i<=m; i++) res[i][n] = k++;
//            n--;
//            if (r<=m){
//                for (int j=n; j>=c; j--) res[m][j] = k++;
//            }
//            m--;
//            if (c<=n){
//                for (int i=m; i>=r; i--) res[i][c] = k++;
//            }
//            c++;
//        }
//        return res;
//    }
//
//    //若只剩下一行/列，则只处理此行/列，其余按circle方式处理
//    public int[][] generateMatrix1(int n) {
//        int[][] matrix = new int[n][n];
//        if (n == 0) return matrix;
//        if (n == 1) {
//            matrix[0][0] = 1;
//            return matrix;
//        }
//        int x = 0, y = 0, k = 1, i = 0;
//        while(n > 0){
//            if(n==1){//if one row/column left, no circle can be formed
//                matrix[x++][y] = k++;
//                break;
//            }
//            //below, process a circle
//            for(i=0;i<n-1;i++) matrix[x][y++] = k++;//top - move right
//            for(i=0;i<n-1;i++) matrix[x++][y] = k++;//right - move down
//            for(i=0;i<n-1;i++) matrix[x][y--] = k++;//bottom - move left
//            for(i=0;i<n-1;i++) matrix[x--][y] = k++;//left - move up
//            x++;
//            y++;
//            n=n-2;
//        }
//        return matrix;
//    }
//
//}
