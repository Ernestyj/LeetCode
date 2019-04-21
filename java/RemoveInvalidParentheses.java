package leetcode301_310;

import java.util.*;

/**Remove the minimum number of invalid parentheses in order to make the input string valid.
 Return all possible results.
 Note: The input string may contain letters other than the parentheses ( and ).

 Examples:
 "()())()" -> ["()()()", "(())()"]
 "(a)())()" -> ["(a)()()", "(a())()"]
 ")(" -> [""]
 * Created by eugene on 16/6/2.
 */
public class RemoveInvalidParentheses {

    /**https://leetcode.com/discuss/72208/easiest-9ms-java-solution
     * DFS, 剪枝条件较多,涉及rmL(待移除左括号数),rmR(待移除右括号数),open(尚未匹配的左括号数)
     * @param s
     * @return
     */
    public List<String> removeInvalidParentheses(String s) {
        Set<String> res = new HashSet<>();  //去除重复
        int rmL = 0, rmR = 0;
        for(int i = 0; i < s.length(); i++) {   //注意计算rmL与rmR的巧妙方法
            if(s.charAt(i)=='(') rmL++;
            else if(s.charAt(i)==')') {
                if(rmL!=0) rmL--;
                else rmR++;
            }
        }
        DFS(res, s, 0, rmL, rmR, 0, new StringBuilder());
        return new ArrayList<>(res);
    }
    public void DFS(Set<String> res, String s, int start, int rmL, int rmR, int open, StringBuilder sb) {
        if(start==s.length() && rmL==0 && rmR==0 && open==0) {
            res.add(sb.toString());
            return;
        }
        if(start==s.length() || rmL<0 || rmR<0 || open<0) return;
        char c = s.charAt(start);
        int len = sb.length();
        if(c=='(') {
            DFS(res, s, start+1, rmL-1, rmR, open, sb);
            DFS(res, s, start+1, rmL, rmR, open+1, sb.append(c));
        } else if(c==')') {
            DFS(res, s, start+1, rmL, rmR-1, open, sb);
            DFS(res, s, start+1, rmL, rmR, open-1, sb.append(c));
        } else {
            DFS(res, s, start+1, rmL, rmR, open, sb.append(c));
        }
        sb.setLength(len);  //恢复原长度
    }


}
