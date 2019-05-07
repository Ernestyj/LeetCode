package leetcode171_180;

/**Related to question Excel Sheet Column Title
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 For example:
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 * Created by eugene on 16/3/19.
 */
public class ExcelSheetColumnNumber {

    public static void main(String[] args) {
        System.out.println(new ExcelSheetColumnNumber().titleToNumber("ABS"));
    }

    public int titleToNumber(String s) {
        int result  = 0;
        for (int i = 0; i < s.length(); i++){
            result *= 26;
            result += ((s.charAt(i) - 'A') + 1);
        }
        return result;
    }

    public int titleToNumber1(String s) {
        char[] chars = new StringBuilder(s).reverse().toString().toCharArray();
        int n = 1;
        for (int i=0; i<chars.length; i++){
            if (i==0) n += (chars[i]-'A');
            else n += (chars[i]-'A'+1)*Math.pow(26, i);
        }
        return n;
    }

}
