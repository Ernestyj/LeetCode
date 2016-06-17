package leetcode61_70;

/**
 * Implement int sqrt(int x).
 Compute and return the square root of x.
 * Created by DCLab on 12/21/2015.
 */
public class Sqrtx {

    /**
     * 二分搜索：对于一个非负数n，它的平方根不会大于（n/2+1）。
     * 在[0, n/2+1]这个范围内可以进行二分搜索，求出n的平方根。
     * http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
     * @param x
     * @return
     */
    public int mySqrt(int x) {
        long l = 0;
        long r = x/2 + 1;
        while (l<=r){
            long m = l+(r-l)/2;
            long square = m*m;
            if (square==x) return (int)m;
            else if (square<x) l = m + 1;
            else r = m-1;
        }
        return (int)r;
    }

}
