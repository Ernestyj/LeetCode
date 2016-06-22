package leetcode11_20;

import java.util.HashMap;

/**Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.
 * Created by eugene on 16/6/1.
 */
public class RomanToInteger {

    /**https://leetcode.com/discuss/42582/my-java-solution
     * Ⅰ（1）Ⅴ（5）Ⅹ（10）L（50）C（100）D（500）M（1000）
     rules:位于大数的后面时就作为加数；位于大数的前面就作为减数
     eg：Ⅲ=3,Ⅳ=4,Ⅵ=6,ⅩⅨ=19,ⅩⅩ=20,ⅩLⅤ=45,MCMⅩⅩC=1980
     "DCXXI"
     * @param s
     * @return
     */
    public int romanToInt(String s) {
        if(s==null || s.length()==0) return 0;
        int len = s.length();
        HashMap<Character,Integer> map = new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        int result = map.get(s.charAt(len-1));
        int pivot = result;
        for(int i=len-2; i>=0; i--){
            int cur = map.get(s.charAt(i));
            if(cur>=pivot){
                result += cur;
            }else{
                result -= cur;
            }
            pivot = cur;
        }
        return result;
    }

}
