package leetcode11_20;

/**Write a function to find the longest common prefix string amongst an array of strings.
 * Created by eugene on 16/6/1.
 */
public class LongestCommonPrefix {

    //https://leetcode.com/discuss/20993/java-code-with-13-lines
    //稍微更快
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
        String pre = strs[0];
        int i = 1;
        while(i < strs.length){
            while(strs[i].indexOf(pre) != 0)
                pre = pre.substring(0, pre.length()-1);
            i++;
        }
        return pre;
    }

    public String longestCommonPrefix0(String[] strs) {
        if(strs==null || strs.length==0) return "";
        String res = strs[0];
        for(int i=1; i<strs.length; i++){
            int k = 0, minL = Math.min(res.length(), strs[i].length());
            while(k<minL && res.charAt(k)==strs[i].charAt(k)) k++;
            res = res.substring(0, k);
        }
        return res;
    }

}
