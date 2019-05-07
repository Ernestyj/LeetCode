package leetcode231_240;

/**Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 For example: Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * Created by eugene on 16/4/29.
 */
public class NumberOfDigitOne {

    /**TODO 重温此方法,不大好记忆
     * https://leetcode.com/discuss/85529/very-easy-to-understand-java-solution-0ms-%E9%99%84%E4%B8%AD%E6%96%87%E8%A7%A3%E9%87%8A
     * 考虑把某一个位数上的数字设成1后，看其他位置有多少种选择。然后把每个数字位取1而有的选择都加起来就可以了。
     比如，假设输入为392， 那么把个位设置成1之后，十位和百位的选择就有00~39共40种，所以个位上可以有40个1。
     然后把十位设置成1之后，百位和个位有 00 ~39共40中选择，注意这儿并不是32或者33种，
     因为当10位上的数设成1之后，319也是小于392的，所以个位可以取所有的0~9。然后百位设成1后，十位和个位有00~99，共100种选择。
     所以加起来就是： 40 + 40 + 100 = 180 种可能性，也就是180 个 1。
     // A number is divided into three parts, front, curDigit and rear.
     For example, if input is 123456789, when we are considering the situation if we set the digit 5 to 1,
     then: front = 1234, curDigit = 5, rear = 6789, rearSize = 1000
     * @param n
     * @return
     */
    public int countDigitOne(int n) {
        int rearSize = 1;
        long mod = 1;
        int count = 0;
        while(mod <= n){
            long front = n / (mod * 10);
            long rear = n % mod;
            int curDigit =(int) (n % (mod * 10)) / rearSize;
            if(curDigit > 1){
                count += ((front + 1) * rearSize);
            }
            else if(curDigit == 1){
                count += (front * rearSize + rear + 1);
            }
            else{
                count += (front * rearSize);
            }
            mod *= 10;
            rearSize *= 10;
        }
        return count;
    }

    /**TODO 方法较难记忆
     * https://leetcode.com/discuss/46366/ac-short-java-solution
     * 按个位/十位...分别计算一的个数:
     * 1. 设k为数字所在位(个位k=1,百位k=10),
     k=1时,由于每10个数其个位就必定有1个一,于是有(n/k)/10组十个数;
     k=10时,由于每100个数其十位就必定有10个一,于是有(n/k)/10组一百个数,其十位上一的个数有(n/k)/10*k;...
     设r=n/k,k处一的个数为r/10*k;
     2. 处理特殊情况,每10个组出现额外1个一,设m=n%k,修正k处一的个数为r/10*k + (r%10==1?m+1:0)
     3. 继续特殊情况,如n=20,其十位一的个数应该额外加10,规律是当前位的数字≥2时应额外加10,
     修正k处一的个数为(r+8)/10*k + (r%10==1?m+1:0)

     * @param n
     * @return
     */
    public int countDigitOne1(int n) {
        int count = 0;
        for (long k = 1; k <= n; k *= 10) {
            long r = n/k, m = n%k;
            // sum up the count of ones on every place k
            count += (r+8)/10*k + (r%10==1 ? m+1 : 0);
        }
        return count;
    }

    //TODO Memory Limit Exceeded
    public int countDigitOne2(int n) {
        if (n<=0) return 0;
        StringBuilder builder = new StringBuilder();
        for (int i=1; i<=n; i++){
            builder.append(i);
        }
        int count = 0;
        for (int i=0; i<builder.length(); i++) {
            if (builder.charAt(i)=='1') count++;
        }
        return count;
    }

}
