
/**Given n points on a 2D plane, find the maximum number of points
 that lie on the same straight line.
 * Created by eugene on 16/3/8.
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxP = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate; continue;  //重合情况
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];  //TODO 避免除法, 垂直情况也融合进去了
            }
            maxP = max(maxP, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                maxP = max(maxP, it->second + duplicate);
            }
        }
        return maxP;
    }
    int gcd(int a, int b) { //辗转相除法基于如下原理：两个整数的最大公约数等于其中较小的数和两数的相除余数的最大公约数
        return (b == 0) ? a : gcd(b, a % b);//在这个过程中，较大的数缩小了，所以继续进行同样的计算可以不断缩小这两个数直至余数变为零。这时的除数就是所求的两个数的最大公约数。
    }
};
//public class MaxPointsOnLine {
//
//    class Point {
//        int x;
//        int y;
//        Point() { x = 0; y = 0; }
//        Point(int a, int b) { x = a; y = b; }
//    }
//
//    /**TODO 注意一个极其容易出错的基础知识
//     * http://www.programcreek.com/2014/04/leetcode-max-points-on-a-line-java/
//     * 为每个点计算其与其他点的斜率,斜率相同则在同一直线上.注意额外处理重复点和垂直线的情况.
//     * @param points
//     * @return
//     */
//    public int maxPoints(Point[] points) {
//        if(points == null || points.length == 0) return 0;
//        Map<Double, Integer> slopeCount = new HashMap<>();
//        int max = 0;
//        for (int i=0; i<points.length; i++){
//            Point point1 = points[i];
//            int duplicate = 1;
//            int vertical = 0;
//            for (int j=i+1; j<points.length; j++){
//                Point point2 = points[j];
//                if (point1.x==point2.x) {
//                    if (point1.y==point2.y) duplicate++;
//                    else vertical++;
//                } else {
//                    //TODO 错误:double slope = (1.0*(point1.y-point2.y))/(point1.x-point2.x);
//                    double slope = (point1.y-point2.y)==0 ? 0.0 :
//                            (1.0*(point1.y-point2.y))/(point1.x-point2.x);
//                    if (!slopeCount.containsKey(slope)) slopeCount.put(slope, 1);
//                    else slopeCount.put(slope, slopeCount.get(slope)+1);
//                }
//            }
//            for (Integer n : slopeCount.values()){
//                if (n+duplicate>max) max = n+duplicate;
//            }
//            max = Math.max(vertical+duplicate, max);
//            slopeCount.clear();
//        }
//        return max;
//    }
//
//}
