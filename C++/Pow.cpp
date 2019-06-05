
/**
 * Implement myPow(x, n).
 * Created by DCLab on 12/3/2015.
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1.0/power(x, -static_cast<long long>(n));//TODO 注意这种写法防溢出
        else return power(x, n);
    }
    double power(double x, long long n){
        if(n==0) return 1.0;
        double v = power(x, n/2);
        return n%2==0? v*v : v*v*x;
    }
};
//public class Pow {
//
//    //二分法（递归）
//    public double myPow(double x, int n) {
//        if (n < 0)
//            return 1/power(x, -n);    //TODO 注意这种写法防溢出
//        else
//            return power(x, n);
//    }
//    private double power(double x, int n) {
//        if (n==0) return 1;
//        double v = power(x, n/2);
//        return n%2==0? v*v : x*v*v;
//    }
//
//
//    //简洁 此法遇到n=Integer.MIN 会溢出
//    public double myPow2(double x, int n) {
//        if(n==0) return 1;
//        if(n<0){
//            n = -n;
//            x = 1/x;
//        }
//        return (n%2 == 0)? myPow2(x*x, n/2) : x* myPow2(x*x, n/2);
//    }
//
//
//
//}
