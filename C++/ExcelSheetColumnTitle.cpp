

/**Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 For example:
 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB
 * Created by eugene on 16/3/19.
 */
class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while (n>0){
            --n;
            char c = n%26 + 'A';
            s = c + s;
            n /= 26;
        }
        //reverse(s.begin(), s.end());
        return s;
    }
};

//public class ExcelSheetColumnTitle {
//
//    public static void main(String[] args) {
//        System.out.println(new ExcelSheetColumnTitle().convertToTitle(1000));
//    }
//
//    //http://www.programcreek.com/2014/03/leetcode-excel-sheet-column-title-java/
//    public String convertToTitle(int n) {
//        StringBuilder sb = new StringBuilder();
//        while(n > 0){
//            n--;    //TODO 关键点,因为从1开始
//            char ch = (char) (n % 26 + 'A');
//            sb.append(ch);
//            n /= 26;
//        }
//        return sb.reverse().toString(); //逆序
//    }
//
//}
