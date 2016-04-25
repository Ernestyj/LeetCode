package leetcode71_80;

import java.util.HashMap;

/**
 * Given a string S and a string T, find the minimum window in S which will contain
 * all the characters in T in complexity O(n).
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 Note: If there is no such window in S that covers all characters in T, return the empty string "".
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 * Created by DCLab on 12/28/2015.
 */
public class MinimumWindowSubstring {

    public static void main(String[] args){
        System.out.println("*****RESULT*****");
        System.out.println();
    }


    /**TODO 重温
     * http://blog.csdn.net/linhuanmars/article/details/20343903
     * 双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，
     * 然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的。
     * @param s
     * @param t
     * @return
     */
    public String minWindow(String s, String t) {
        if(s==null || s.length()==0) return "";
        HashMap<Character, Integer> bookT = new HashMap<>();
        //建立T字典
        for(int i=0; i<t.length(); i++) {
            if(bookT.containsKey(t.charAt(i))) {
                bookT.put(t.charAt(i), bookT.get(t.charAt(i))+1);
            }else {
                bookT.put(t.charAt(i), 1);
            }
        }
        int left = 0;
        int count = 0;
        int minLen = s.length()+1;  //+1用来判断无匹配的极端情况
        int minStart = 0;
        //尾指针不断往后扫
        for(int right=0; right<s.length(); right++) {
            if(bookT.containsKey(s.charAt(right))) {
                bookT.put(s.charAt(right), bookT.get(s.charAt(right))-1);
                if(bookT.get(s.charAt(right))>=0) {
                    count++;
                }
                //当扫到有一个窗口包含了所有T的字符后，然后再收缩头指针，直到不能再收缩为止
                while(count == t.length()) {
                    if(right-left+1 < minLen) { //更新
                        minLen = right-left+1;
                        minStart = left;
                    }
                    if(bookT.containsKey(s.charAt(left))) {     //left收缩
                        bookT.put(s.charAt(left), bookT.get(s.charAt(left))+1);
                        if(bookT.get(s.charAt(left))>0) {
                            count--;
                        }
                    }
                    left++;
                }
            }
        }
        if(minLen>s.length()) return "";
        //最后记录所有可能的情况中窗口最小的
        return s.substring(minStart, minStart+minLen);
    }

}
