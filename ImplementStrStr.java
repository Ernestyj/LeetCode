package leetcode21_30;

/**
 * Implement strStr().
 Returns the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.
 实现strstr(). 返回needle(关键字)在haystack(字符串)中第一次出现的位置，
 如果needle不在haystack中，则返回-1。
 注：strstr()是c++中的一个函数
 *
 * Created by DCLab on 11/11/2015.
 */
public class ImplementStrStr {

    //简洁,但比下面方法慢
    public int strStr(String haystack, String needle) {
        for (int start=0; ; start++) {
            for (int j=0; ; j++) {
                if (j == needle.length()) return start;
                if (start+j == haystack.length()) return -1;
                if (needle.charAt(j) != haystack.charAt(start+j)) break;
            }
        }
    }

    //按思路写
    public int strStr1(String haystack, String needle) {
        if (haystack==null || needle==null) return -1;
        int needLen = needle.length(), hayLen = haystack.length();
        if (needLen==0) return 0;
        for (int start=0; start<hayLen; start++){
            if (needLen <= hayLen-start && //TODO 注意此条件
                    haystack.charAt(start) == needle.charAt(0)){
                if (needLen==1) return start;
                for (int j=1; j<needLen; j++){
                    if (needle.charAt(j) != haystack.charAt(start+j)) break;
                    if (j == needLen-1) return start;
                }
            }

        }
        return -1;
    }

}
