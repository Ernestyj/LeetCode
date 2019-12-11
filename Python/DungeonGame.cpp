
/**https://leetcode.com/problems/dungeon-game/
 * Created by eugene on 16/3/22.
 */
class Solution {
public:
    //dp[i][j] 用来表示当前位置 (i, j) 出发的最小起始血量.逆向推正是本题的精髓所在.当前位置的血量是由右边和下边房间的可生存血量决定的
    //到达公主房间后，骑士火拼完的血量至少为1，那么此时公主房间的右边和下边房间里的数字我们就都设置为1:dp[m][n - 1] = 1; dp[m - 1][n] = 1;
    //用当前房间的右边和下边房间中骑士的较小血量减去当前房间的数字，如果是负数或着0，说明当前房间是正数，这样骑士进入当前房间后的生命值是1就行了，因为不会减血.
    //dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
//public class DungeonGame {
//    /**
//     * DP:用hp[i,j]表示进入[i,j]前所需的最小生命值,
//     有hp[i,j] = min{hp[i+1,j]-dungeon[i,j], hp[i,j+1]-dungeon[i,j]},大括号内的两个值均需不小于零.
//     */
//    //另一种风格
//    public int calculateMinimumHP(int[][] dungeon) {
//        int m = dungeon.length;
//        int n = dungeon[0].length;
//        int[][] hp = new int[m][n];
//        hp[m-1][n-1] = 1-dungeon[m-1][n-1];
//        if (hp[m-1][n-1]<1) hp[m-1][n-1] = 1;
//        for (int i=m-2; i>=0; i--) {
//            hp[i][n-1] = hp[i+1][n-1]-dungeon[i][n-1];
//            if (hp[i][n-1]<1) hp[i][n-1] = 1;
//        }
//        for (int j=n-2; j>=0; j--) {
//            hp[m-1][j] = hp[m-1][j+1]-dungeon[m-1][j];
//            if (hp[m-1][j]<1) hp[m-1][j] = 1;
//        }
//        for (int i=m-2; i>=0; i--){
//            for (int j=n-2; j>=0; j--){
//                int down = hp[i+1][j]-dungeon[i][j];
//                if (down<1) down = 1;
//                int right = hp[i][j+1]-dungeon[i][j];
//                if (right<1) right = 1;
//                hp[i][j] = Math.min(down, right);
//            }
//        }
//        return hp[0][0];
//    }
//    //OJ速度更快
//    public int calculateMinimumHP1(int[][] dungeon) {
//        int m = dungeon.length;
//        int n = dungeon[0].length;
//        int[][] hp = new int[m+1][n+1];
//        for (int i=0; i<m; i++) hp[i][n] = 9999;    //TODO 不能用Integer.MAX,否则溢出为负数
//        for (int j=0; j<n; j++) hp[m][j] = 9999;
//        hp[m-1][n] = 1; hp[m][n-1] = 1;
//        for (int i=m-1; i>=0; i--){
//            for (int j=n-1; j>=0; j--){
//                int down = hp[i+1][j]-dungeon[i][j];
//                if (down<1) down = 1;
//                int right = hp[i][j+1]-dungeon[i][j];
//                if (right<1) right = 1;
//                hp[i][j] = Math.min(down, right);
//            }
//        }
//        return hp[0][0];
//    }
//
//}
