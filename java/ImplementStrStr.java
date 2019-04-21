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

    //按思路写
    public int strStr(String haystack, String needle) {
        int l1 = haystack.length(), l2 = needle.length();
        if(l2==0) return 0; //TODO 不能漏
        for(int start=0; start<=l1-l2; start++){
            for(int j=0; j<l2; j++){
                if(haystack.charAt(start+j)!=needle.charAt(j)) break;
                if(j==l2-1) return start;
            }
        }
        return -1;
    }

}
