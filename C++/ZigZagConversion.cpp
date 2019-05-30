package leetcode1_10;

/**The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 * Created by eugene on 16/4/2.
 */
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows, "");
        int k = 0;
        while(k < s.size()){
            for (int i = 0; i<numRows && k<s.size(); ++i) {
                strs[i] += s[k++];
            }
            for (int i = numRows-2; i>=1 && k<s.size(); --i) {
                strs[i] += s[k++];
            }
        }
        for (int i = 1; i < numRows; ++i) {
            strs[0] += strs[i];
        }
        return strs[0];
    }
};
//public class ZigZagConversion {
//
//    /**https://leetcode.com/discuss/10493/easy-to-understand-java-solution
//     * 简洁易懂
//     * @param s
//     * @param nRows
//     * @return
//     */
//    public String convert(String s, int nRows) {
//        char[] c = s.toCharArray();
//        int len = c.length;
//        StringBuffer[] sb = new StringBuffer[nRows];
//        for (int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();
//        int k = 0;
//        while (k < len) {
//            for (int i=0; i<nRows && k<len; i++) // vertically down
//                sb[i].append(c[k++]);
//            for (int i=nRows-2; i>=1 && k<len; i--) // obliquely up
//                sb[i].append(c[k++]);
//        }
//        for (int i=1; i<sb.length; i++) sb[0].append(sb[i]);
//        return sb[0].toString();
//    }
//
//    /**
//     * http://www.cnblogs.com/springfor/p/3889414.html
//     * 图 https://leetcode.com/discuss/55208/if-you-are-confused-with-zigzag-pattern-come-and-see
//     * 数学规律题(不大可能出现)
//     * @param s
//     * @param nRows
//     * @return
//     */
//    public String convert1(String s, int nRows) {
//        if(s==null || s.length()==0 || nRows<=0) return "";
//        if(nRows == 1) return s;
//        StringBuilder res = new StringBuilder();
//        int size = 2*nRows-2;
//        for(int i=0; i<nRows; i++){
//            for(int j=i; j<s.length(); j+=size){
//                res.append(s.charAt(j));
//                if(i!=0 && i!=nRows-1){//except the first row and the last row
//                    int temp = j+size-2*i;
//                    if(temp<s.length()) res.append(s.charAt(temp));
//                }
//            }
//        }
//        return res.toString();
//    }
//
//}
