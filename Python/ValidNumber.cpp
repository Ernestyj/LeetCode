
/**
 * Validate if a given string is numeric.
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 Note: It is intended for the problem statement to be ambiguous.
 You should gather all requirements up front before implementing one.
 * Created by DCLab on 12/18/2015.
 */
class Solution {
public:
    bool isNumber(string s) {   //注意判断条件繁杂
        bool num = false, numAfterE = true, dot = false, exp = false, sign = false;//numAfterE表示自然底数后面是否有数字
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                sign = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = true;
                numAfterE = true;
            } else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (s[i] == 'e') {
                if (exp || !num) return false;
                exp = true;
                numAfterE = false;
            } else return false;
        }
        return num && numAfterE;
    }
};
//更多测试用例
string s1 = "0"; // True
string s2 = " 0.1 "; // True
string s3 = "abc"; // False
string s4 = "1 a"; // False
string s5 = "2e10"; // True

string s6 = "-e10"; // False
string s7 = " 2e-9 "; // True
string s8 = "+e1"; // False
string s9 = "1+e"; // False
string s10 = " "; // False

string s11 = "e9"; // False
string s12 = "4e+"; // False
string s13 = " -."; // False
string s14 = "+.8"; // True
string s15 = " 005047e+6"; // True

string s16 = ".e1"; // False
string s17 = "3.e"; // False
string s18 = "3.e1"; // True
string s19 = "+1.e+5"; // True
string s20 = " -54.53061"; // True

string s21 = ". 1"; // False
//public class ValidNumber {
//
//    public static void main(String[] args) {
//        System.out.println("*****RESULT*****");
//        //"84656e656D" x "078332e437" v "-1.e49046 " v
//        System.out.println(Double.valueOf("-1.e49046 "));
//        System.out.println(new ValidNumber().isNumber("-1.e49046 "));
//    }
//
//    //TODO 待处理 hard 判断条件繁杂
//    //https://leetcode.com/discuss/26682/clear-java-solution-with-ifs
//    public boolean isNumber(String s) {
//        s = s.trim();
//        boolean pointSeen = false;
//        boolean eSeen = false;
//        boolean numberSeen = false;
//        boolean numberAfterE = true;
//        for(int i=0; i<s.length(); i++) {
//            if('0'<=s.charAt(i) && s.charAt(i)<='9') {
//                numberSeen = true;
//                numberAfterE = true;
//            } else if(s.charAt(i)=='.') {
//                if(eSeen || pointSeen) return false;
//                pointSeen = true;
//            } else if(s.charAt(i)=='e') {
//                if(eSeen || !numberSeen) return false;
//                numberAfterE = false;
//                eSeen = true;
//            } else if(s.charAt(i)=='-' || s.charAt(i)=='+') {
//                if(i!=0 && s.charAt(i-1)!='e') return false;
//            } else {
//                return false;
//            }
//        }
//        return numberSeen && numberAfterE;
//    }
//
//
//    /**
//     * @param s
//     * @return
//     */
//    public boolean isNumber1(String s) {
//        if(s == null) return false;
//        s = s.trim();
//        if(s.length()==0) return false;
//        boolean dotFlag = false;
//        boolean eFlag = false;
//        for(int i=0; i<s.length(); i++) {
//            switch(s.charAt(i)) {
//                case '.':
//                    if(dotFlag || eFlag || ((i==0 || !(s.charAt(i-1)>='0' && s.charAt(i-1)<='9'))
//                            && (i==s.length()-1 || !(s.charAt(i+1)>='0' && s.charAt(i+1)<='9'))))
//                        return false;
//                    dotFlag = true;
//                    break;
//                case '+':
//                case '-':
//                    if((i>0 && (s.charAt(i-1)!='e' && s.charAt(i-1)!='E'))
//                            || (i==s.length()-1 || !(s.charAt(i+1)>='0' && s.charAt(i+1)<='9' || s.charAt(i+1)=='.')))
//                        return false;
//                    break;
//                case 'e':
//                case 'E':
//                    if(eFlag || i==s.length()-1 || i==0) return false;
//                    eFlag = true;
//                    break;
//                case '0':
//                case '1':
//                case '2':
//                case '3':
//                case '4':
//                case '5':
//                case '6':
//                case '7':
//                case '8':
//                case '9':
//                    break;
//                default:
//                    return false;
//            }
//        }
//        return true;
//    }
//
//}
