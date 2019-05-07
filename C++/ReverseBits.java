package leetcode181_190;

/**Reverse bits of a given 32 bits unsigned integer.
 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 return 964176192 (represented in binary as 00111001011110000010100101000000).
 * Created by eugene on 16/3/27.
 */
public class ReverseBits {

    /**
     * https://leetcode.com/discuss/27328/java-solution-and-optimization
     * @param n
     * @return
     */
    public int reverseBits(int n) {
        int result = 0;
        for (int i=0; i<32; i++) {
            result += n&1;
            n >>= 1;
            if (i<31) result <<= 1; //注意最后一位不移
        }
        return result;
    }

    // you need treat n as an unsigned value
    public int reverseBits1(int n) {
        for (int i=0; i<16; i++)
            n = swapBit(n, i, 32-i-1);
        return n;
    }
    private int swapBit(int n, int i, int j){
        int a = (n>>i)&1;
        int b = (n>>j)&1;
        if ((a^b)!=0) return n ^= (1<<i)|(1<<j);
        return n;
    }

}
