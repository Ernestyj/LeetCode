package leetcode201_210;

/**Count the number of prime numbers less than a non-negative number, n.
 * Created by eugene on 16/4/1.
 */
public class CountPrimes {

    /**https://leetcode.com/problems/count-primes/
     * The Sieve of Eratosthenes uses an extra O(n) memory and
     its runtime complexity is O(n log log n).
     * if the current number is p, we can always mark off multiples of p
     starting at p2, then in increments of p: p2 + p, p2 + 2p, ...
     the terminating loop condition can be p < √n,
     When the loop terminates, all the numbers in the table that are non-marked are prime.
     * @param n
     * @return
     */
    public int countPrimes(int n) {
        boolean[] isPrime = new boolean[n];
        for (int i=2; i<n; i++) isPrime[i] = true;
        for (int i=2; i*i<n; i++) { //TODO i*i<n is cheaper than i<sqrt(n)
            if (!isPrime[i]) continue;
            for (int j=i*i; j<n; j+=i) isPrime[j] = false;
        }
        int count = 0;
        for (int i=2; i<n; i++) if (isPrime[i]) count++;
        return count;
    }

}
