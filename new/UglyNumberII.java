package leetcode261_270;

import java.util.PriorityQueue;

/**Write a program to find the n-th ugly number.
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 Note that 1 is typically treated as an ugly number.
 * Created by eugene on 16/5/14.
 */
public class UglyNumberII {

    /**https://leetcode.com/discuss/52905/my-16ms-c-dp-solution-with-short-explanation
     * DP: We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then
     k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1.
     Then we test:
     k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on.
     Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
     * @param n
     * @return
     */
    public int nthUglyNumber(int n) {
        int[] primes = {2,3,5};
        int[] idx = new int[3];
        int[] uglys = new int[n];
        uglys[0] = 1;
        for (int i=1; i<n; i++) {
            uglys[i] = Integer.MAX_VALUE;
            for (int j=0; j<3; j++)
                uglys[i] = Math.min(uglys[i], uglys[idx[j]]*primes[j]);
            for (int j=0; j<3; j++) // bump up index for the current minimum ugly number
                if (uglys[i]==uglys[idx[j]]*primes[j]) idx[j]++;
        }
        return uglys[n-1];
    }

}
