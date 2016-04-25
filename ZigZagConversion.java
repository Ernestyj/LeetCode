package leetcode1_10;

/**The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 * Created by eugene on 16/4/2.
 */
public class ZigZagConversion {

    /**
     * http://www.cnblogs.com/springfor/p/3889414.html
     * 数学规律题(不大可能出现)
     * @param s
     * @param nRows
     * @return
     */
    public String convert(String s, int nRows) {
        if(s==null || s.length()==0 || nRows<=0) return "";
        if(nRows == 1) return s;
        StringBuilder res = new StringBuilder();
        int size = 2*nRows-2;
        for(int i=0;i<nRows;i++){
            for(int j=i;j<s.length();j+=size){
                res.append(s.charAt(j));
                if(i!=0 && i!=nRows-1){//except the first row and the last row
                    int temp = j+size-2*i;
                    if(temp<s.length()) res.append(s.charAt(temp));
                }
            }
        }
        return res.toString();
    }

}
