package leetcode61_70;

/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Created by DCLab on 12/22/2015.
 */
public class ClimbingStairs {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        System.out.println(new ClimbingStairs().climbStairs(3));
    }

    /**
     * 动态规划：res[i]=res[i-1]+res[i-2]
     * @param n
     * @return
     */
    public int climbStairs(int n) {
        if (n == 1) return 1;
        int[] res = new int[n];
        res[0] = 1;
        res[1] = 2;
        for (int i=2; i<n; i++){
            res[i] = res[i-1] + res[i-2];
        }
        return res[n-1];
    }

}
