package leetcode41_50;

/**
 * Implement pow(x, n).
 * Created by DCLab on 12/3/2015.
 */
public class Pow {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        System.out.println(new Pow().myPow(0.00001, 2147483647));
//        System.out.println(new Pow().myPow(2, 5));
    }


    //二分法（递归）
    public double myPow(double x, int n) {
        if (n < 0) {
            return 1 / power(x, -n);
        } else {
            return power(x, n);
        }
    }
    private double power(double x, int n) {
        if (n == 0) return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        } else {
            return v * v * x;
        }
    }

}
