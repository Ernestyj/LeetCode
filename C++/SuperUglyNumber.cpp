
/**Write a program to find the nth super ugly number.
 Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
 For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers
 given primes = [2, 7, 13, 19] of size 4.
 Note:
 (1) 1 is a super ugly number for any given primes.
 (2) The given numbers in primes are in ascending order.
 (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * Created by eugene on 16/6/14.
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {    //与UglyNumberII思路一致，只是换成标准循环，O(kN)
        int len = primes.size();
        vector<int> idx(len);
        vector<int> uglys(n);
        uglys[0] = 1;
        for (int i = 1; i < n; ++i) {
            uglys[i] = INT_MAX;
            for (int j = 0; j < len; ++j) {   //j是primes的序号
                uglys[i] = min(uglys[i], uglys[idx[j]]*primes[j]);
            }
            for (int j = 0; j < len; ++j) {
                if(uglys[idx[j]]*primes[j] == uglys[i]) ++idx[j];
            }
        }
        return uglys.back();
    }
};
//public class SuperUglyNumber {
//    /**
//     * 与UglyNumberII思路一致, O(kN)
//     */
//    public int nthSuperUglyNumber(int n, int[] primes) {
//        int k = primes.length;
//        int[] idx = new int[k];
//        int[] uglys = new int[n];
//        uglys[0] = 1;
//        for (int i=1; i<n; i++){
//            uglys[i] = Integer.MAX_VALUE;
//            for (int j=0; j<k; j++){
//                uglys[i] = Math.min(uglys[i], uglys[idx[j]]*primes[j]);
//            }
//            for (int j=0; j<k; j++){
//                if (uglys[idx[j]]*primes[j]==uglys[i]) idx[j]++;
//            }
//        }
//        return uglys[n-1];
//    }
//
//}
