package leetcode91_100;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 For example:
 Given "25525511135",
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * Created by DCLab on 1/14/2016.
 */
public class RestoreIPAddresses {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    /**参考：http://bangbingsyb.blogspot.com/2014/11/leetcode-restore-ip-addresses.html
     * 回溯法：一个有效的IP地址由4个数字组成，每个数字在0-255之间。对于其中的2位数或3位数，不能以0开头。
     所以对于以s[i]开头的数字有3种可能：
     1. 一位s[i]；
     2. 两位s[i:i+1]，s[i]!=0时；
     3. 三位s[i:i+2]，s[i]!=0，且s[i : i+2] <= 255；
     根据以上规律，对s从头开始进行DFS寻找4个数字即可。
     * @param s
     * @return
     */
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        List<String> list = new ArrayList<>();
        dfs(result, list, s, 0);
        return result;
    }
    private void dfs(List<String> result, List<String> list, String s, int start){
        if(list.size() == 4){
            if(start != s.length()) return;
            StringBuilder builder = new StringBuilder();
            for (int i=0; i<=2; i++){
                builder.append(list.get(i));
                builder.append(".");
            }
            builder.append(list.get(3));
            result.add(builder.toString());
            return;
        }
        for(int i=start; i<s.length() && i<start+3; i++){
            String tmp = s.substring(start, i+1);
            if(isValid(tmp)){
                list.add(tmp);
                dfs(result, list, s, i+1);
                list.remove(list.size()-1);
            }
        }
    }
    // 非常简洁的判定方法，注意学习
    private boolean isValid(String s){
        if(s.charAt(0) == '0')
            return s.equals("0"); // to eliminate cases like "00", "10"
        int digit = Integer.valueOf(s);
        return digit >= 0 && digit <= 255;
    }

}
