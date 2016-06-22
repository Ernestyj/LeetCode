package leetcode281_290;

import java.util.ArrayList;
import java.util.List;

/**Given a string that contains only digits 0-9 and a target value, return all possibilities to
 * add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
 Examples:
 "123", 6 -> ["1+2+3", "1*2*3"]
 "232", 8 -> ["2*3+2", "2+3*2"]
 "105", 5 -> ["1*0+5","10-5"]
 "00", 0 -> ["0+0", "0-0", "0*0"]
 "3456237490", 9191 -> []
 * Created by eugene on 16/5/21.
 */
public class ExpressionAddOperators {

    /**
     * https://leetcode.com/discuss/58614/java-standard-backtrace-ac-solutoin-short-and-clear
     * 回溯:注意边界情况1.用long存储计算结果;2.零开头的数字应忽略. 注意乘法优先级,用一个变量暂存相乘的结果.
     * @param num
     * @param target
     * @return
     */
    public List<String> addOperators(String num, int target) {
        ArrayList<String> result = new ArrayList<>();
        if(num==null || num.length()==0) return result;
        dfs(num, target, 0, "", result, 0, 0);
        return result;
    }
    private void dfs(String num, int target, int start, String path, List<String> result, long eval, long multed){
        if (start==num.length()){
            if (target==eval) result.add(path);
            return;
        }
        for (int i=start; i<num.length(); i++){
            if (num.charAt(start)=='0'){
                if (i!=start) break;    //零开头的数字应忽略
            }
            long x = Long.parseLong(num.substring(start, i+1));
            if (start==0)
                dfs(num, target, i+1, path+x, result, x, x);
            else {
                dfs(num, target, i+1, path+"+"+x, result, eval+x, x);
                dfs(num, target, i+1, path+"-"+x, result, eval-x, -x);
                //减去之前操作的,再加上相乘值
                dfs(num, target, i+1, path+"*"+x, result, eval-multed+multed*x, multed*x);
            }
        }
    }
}
