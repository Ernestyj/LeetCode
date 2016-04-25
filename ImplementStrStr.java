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

    public static void main(String[] args) {
        String haystack = "mississippi";
        String key = "issipi";
//        String key = "issipisssssssss";
        int index = new ImplementStrStr().strStr(haystack, key);
        System.out.println("*****RESULT*****");
        System.out.println(index);
        if (index != -1)
            for (int i = index; i < key.length() + index; i++) System.out.print(haystack.charAt(i));
    }

    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) return -1;
        if (needle.length() == 0) return 0;
        for (int i = 0; i < haystack.length(); i++){
            if (needle.length() <= haystack.length() - i && //TODO 注意此条件
                    haystack.charAt(i) == needle.charAt(0)){
                if (needle.length() == 1) return i;
                for (int j = 1; j < needle.length(); j++){
                    if (needle.charAt(j) != haystack.charAt(i + j)) break;
                    if (j == needle.length() - 1) return i;
                }
            }

        }
        return -1;
    }

}
