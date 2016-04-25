package leetcode61_70;

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
public class ValidNumber {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        //"84656e656D" x "078332e437" v "-1.e49046 " v
        System.out.println(Double.valueOf("-1.e49046 "));
        System.out.println(new ValidNumber().isNumber("-1.e49046 "));
    }


    /**
     * 、
     * @param s
     * @return
     */
    public boolean isNumber(String s) {
        if(s == null) return false;
        s = s.trim();
        if(s.length()==0) return false;
        boolean dotFlag = false;
        boolean eFlag = false;
        for(int i=0; i<s.length(); i++) {
            switch(s.charAt(i)) {
                case '.':
                    if(dotFlag || eFlag || ((i==0 || !(s.charAt(i-1)>='0' && s.charAt(i-1)<='9'))
                            && (i==s.length()-1 || !(s.charAt(i+1)>='0' && s.charAt(i+1)<='9'))))
                        return false;
                    dotFlag = true;
                    break;
                case '+':
                case '-':
                    if((i>0 && (s.charAt(i-1)!='e' && s.charAt(i-1)!='E'))
                            || (i==s.length()-1 || !(s.charAt(i+1)>='0' && s.charAt(i+1)<='9' || s.charAt(i+1)=='.')))
                        return false;
                    break;
                case 'e':
                case 'E':
                    if(eFlag || i==s.length()-1 || i==0) return false;
                    eFlag = true;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    break;
                default:
                    return false;
            }
        }
        return true;
    }

}
