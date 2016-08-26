package leetcode81_90;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer n representing the total number of bits in the code,
 print the sequence of gray code. A gray code sequence must begin with 0.
 For example, given n = 2, return [0,1,3,2].
 * Created by DCLab on 1/10/2016.
 */
public class GrayCode {

    //G(i) = i^(i/2)
    public List<Integer> grayCode0(int n) {
        List<Integer> result = new LinkedList<>();
        for (int i=0; i < 1<<n; i++) result.add(i ^ i>>1);
        return result;
    }

    /** http://fisherlei.blogspot.com/2012/12/leetcode-gray-code.html
     * 注意：格雷码是唯一的（如果每次只是与上一个数有一个位不同的话，则会有很多种组合结果）。
     因此另一种解法是数学解：第i个数可以由如下公式产生，(i>>1)^i。
     * 递归法：
     * 规律：n位格雷码的前一半是：n-1位的所有格雷码；而后一半是：前一半逆序后，均加上2^(n-1)。
     * 示例：n=3: 000, 001, 011, 010 | 110, 111, 101, 100 (0, 1, 3, 2 | 6, 7, 5, 4)
     */
    private List<Integer> result = new ArrayList<>();
    public List<Integer> grayCode(int n) {
        if (n == 0){
            result.add(0);
            return result;
        }
        result = grayCode(n-1);
        int adds = 1 << (n-1);
        for (int i=result.size()-1; i>=0; i--){
            result.add(result.get(i) + adds);
        }
        return result;
    }

}
