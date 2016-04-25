package leetcode141_150;

import java.util.HashMap;
import java.util.Map;
import java.util.function.IntBinaryOperator;

/**Given n points on a 2D plane, find the maximum number of points
 that lie on the same straight line.
 * Created by eugene on 16/3/8.
 */
public class MaxPointsOnLine {

    class Point {
        int x;
        int y;
        Point() { x = 0; y = 0; }
        Point(int a, int b) { x = a; y = b; }
    }

    /**TODO 注意一个极其容易出错的基础知识
     * http://www.programcreek.com/2014/04/leetcode-max-points-on-a-line-java/
     * 为每个点计算其与其他点的斜率,斜率相同则在同一直线上.注意额外处理重复点和垂直线的情况.
     * @param points
     * @return
     */
    public int maxPoints(Point[] points) {
        if(points == null || points.length == 0) return 0;
        Map<Double, Integer> slopeCount = new HashMap<>();
        int max = 0;
        for (int i=0; i<points.length; i++){
            Point point1 = points[i];
            int duplicate = 1;
            int vertical = 0;
            for (int j=i+1; j<points.length; j++){
                Point point2 = points[j];
                if (point1.x==point2.x) {
                    if (point1.y==point2.y) duplicate++;
                    else vertical++;
                } else {
                    //TODO 错误:double slope = (1.0*(point1.y-point2.y))/(point1.x-point2.x);
                    double slope = (point1.y-point2.y)==0 ? 0.0 :
                            (1.0*(point1.y-point2.y))/(point1.x-point2.x);
                    if (!slopeCount.containsKey(slope)) slopeCount.put(slope, 1);
                    else slopeCount.put(slope, slopeCount.get(slope)+1);
                }
            }
            for (Integer n : slopeCount.values()){
                if (n+duplicate>max) max = n+duplicate;
            }
            max = Math.max(vertical+duplicate, max);
            slopeCount.clear();
        }
        return max;
    }

}
