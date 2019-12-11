package leetcode201_210;

/**Count the number of prime numbers less than a non-negative number, n.
 * Created by eugene on 16/4/1.
 */
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++count;
                for (int j = 2; i * j < n; ++j) {
                    isPrime[i * j] = false;
                }
            }
        }
        return count;
    }
};
//public class CountPrimes {
//
//    /**简洁
//     * 如果一个数是另一个数的倍数，那这个数肯定不是素数。利用这个性质，我们可以建立一个素数数组，
//     从2开始将素数的倍数都标注为不是素数。第一轮将4、6、8等表为非素数，然后遍历到3，发现3没有被标记为非素数，
//     则将6、9、12等标记为非素数，一直到N为止，再数一遍素数数组中有多少素数。
//     * @param n
//     * @return
//     */
//    public int countPrimes(int n) {
//        boolean[] notPrime = new boolean[n];
//        int count = 0;
//        for (int i = 2; i < n; i++) {
//            if (!notPrime[i]) {
//                count++;
//                for (int j = 2; i*j < n; j++) {
//                    notPrime[i*j] = true;
//                }
//            }
//        }
//        return count;
//    }
//
//    /**https://segmentfault.com/a/1190000003709122
//     * The Sieve of Eratosthenes uses an extra O(n) memory and
//     its runtime complexity is O(n log log n).
//     * if the current number is p, we can always mark off multiples of p
//     starting at p2, then in increments of p: p2 + p, p2 + 2p, ...
//     the terminating loop condition can be p < √n,
//     When the loop terminates, all the numbers in the table that are non-marked are prime.
//     * @param n
//     * @return
//     */
//    public int countPrimes1(int n) {
//        boolean[] isPrime = new boolean[n];
//        for (int i=2; i<n; i++) isPrime[i] = true;
//        for (int i=2; i*i<n; i++) { //TODO i*i<n is cheaper than i<sqrt(n)
//            if (!isPrime[i]) continue;
//            for (int j=i*i; j<n; j+=i) isPrime[j] = false;
//        }
//        int count = 0;
//        for (int i=2; i<n; i++) if (isPrime[i]) count++;
//        return count;
//    }
//
//}
