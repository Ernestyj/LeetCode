
/**
 * Implement int sqrt(int x).
 Compute and return the square root of x.
 * Created by DCLab on 12/21/2015.
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int l=0, r=x/2+1, m=0;
        while(l+1<r){
            m=l+(r-l)/2;
            long square = static_cast<long>(m)*m;
            if(square==x) return m;
            else if(square<x) l=m;
            else r=m;
        }
        if(x>=static_cast<long>(l)*l) return l;
        if(x>=static_cast<long>(r)*r) return r;
        return -1;
    }

    int mySqrt(int x) {
        int l=0, r=x/2+1;
        while(l<=r){
            int m=l+(r-l)/2;
            long square = static_cast<long>(m)*m;
            if(square==x) return m;
            else if(square<x) l=m+1;
            else r=m-1;
        }
        return r;
    }
};

//public class Sqrtx {
//
//    /**
//     * 二分搜索：对于一个非负数n，它的平方根不会大于（n/2+1）。
//     * 在[0, n/2+1]这个范围内可以进行二分搜索，求出n的平方根。
//     * http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
//     * @param x
//     * @return
//     */
//    public int mySqrt(int x) {
//        int l = 0, r = x/2 + 1;
//        while (l<=r){
//            int m = l+(r-l)/2;
//            long square = (long)m*m;    //TODO 强制转化为long非常重要,否则溢出
//            if (square==x) return m;
//            else if (square<x) l = m+1;
//            else r = m-1;
//        }
//        return r;
//    }
//
//}
