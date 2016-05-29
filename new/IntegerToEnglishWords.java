package leetcode271_280;

/**Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.
 For example,
 123 -> "One Hundred Twenty Three"
 12345 -> "Twelve Thousand Three Hundred Forty Five"
 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * Created by eugene on 16/5/16.
 */
public class IntegerToEnglishWords {

    private final String[] LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private final String[] TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"};
    private final String[] THOUSANDS = {"", "Thousand", "Million", "Billion"};
    /**
     * https://leetcode.com/problems/integer-to-english-words/
     * @param num
     * @return
     */
    public String numberToWords(int num) {
        if (num==0) return "Zero";
        int i = 0;
        String words = "";
        while (num>0) {
            if (num%1000 != 0)
                words = helper(num%1000)+THOUSANDS[i]+" "+words;
            num /= 1000;
            i++;
        }
        return words.trim();
    }
    private String helper(int num) {    //处理三位数及以下
        if (num == 0)
            return "";
        else if (num<20)
            return LESS_THAN_20[num] + " ";
        else if (num<100)
            return TENS[num/10] + " " + helper(num%10);
        else
            return LESS_THAN_20[num/100] + " Hundred " + helper(num%100);
    }


    //另一种直观写法,速度快
    private final String[] belowTen = new String[] {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    private final String[] belowTwenty = new String[] {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private final String[] tens = new String[] {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    public String numberToWords1(int num) {
        if (num == 0) return "Zero";
        return translate(num);
    }
    private String translate(int num) {
        String result = new String();
        if (num < 10) result = belowTen[num];
        else if (num < 20) result = belowTwenty[num-10];
        else if (num < 100) result = tens[num/10] + " " + translate(num%10);
        else if (num < 1000) result = translate(num/100) + " Hundred " +  translate(num%100);
        else if (num < 1000000) result = translate(num/1000) + " Thousand " +  translate(num%1000);
        else if (num < 1000000000) result = translate(num/1000000) + " Million " +  translate(num%1000000);
        else result = translate(num/1000000000) + " Billion " + translate(num%1000000000);
        return result.trim();
    }

}
