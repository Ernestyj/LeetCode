
/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 For example:
 Given "25525511135",
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * Created by DCLab on 1/14/2016.
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()<4) return res;
        dfs(s, res, "", 0);
        return res;
    }
    void dfs(string s, vector<string>& res, string sol, int start){ //深度是IP段数4
        if(start==4){
            if(s.empty()) res.push_back(sol);
        }else{
            for (int len = 1; len <= 3; ++len) {
                if(len>s.size()) break;
                string temp(s, 0, len);
                if(isValid(temp)){
                    dfs(s.substr(len), res, sol+temp+(start==3? "":"."), start+1);//string是临时对象，无需push和pop
                }
            }
        }
    }
    bool isValid(string s){
        if(s[0]=='0') return s=="0";
        else {
            int i = stoi(s);
            return 0<=i && i<=255;
        }
    }
};
//public class RestoreIPAddresses {
//
//    /**参考：http://bangbingsyb.blogspot.com/2014/11/leetcode-restore-ip-addresses.html
//     * 标准回溯：一个有效的IP地址由4个数字组成，每个数字在0-255之间。对于其中的2位数或3位数，不能以0开头。
//     所以对于以s[i]开头的数字有2种可能：
//     1. s[i]==0时, s=="0"
//     2. s[i]!=0时，0 <= s[i : i+2] <= 255
//     根据以上规律，对s从头开始进行DFS寻找4个数字即可。
//     * @param s
//     * @return
//     */
//    public List<String> restoreIpAddresses(String s) {
//        List<String> result = new ArrayList<>();
//        List<String> list = new ArrayList<>();
//        dfs(result, list, s, 0);
//        return result;
//    }
//    private void dfs(List<String> result, List<String> list, String s, int start){
//        if(list.size()==4){
//            if(start != s.length()) return;
//            StringBuilder builder = new StringBuilder();
//            for (int i=0; i<3; i++){
//                builder.append(list.get(i)).append(".");
//            }
//            builder.append(list.get(3));
//            result.add(builder.toString());
//            return;
//        }
//        for(int i=start; i<s.length() && i<start+3; i++){
//            String tmp = s.substring(start, i+1);
//            if(isValid(tmp)){
//                list.add(tmp);
//                dfs(result, list, s, i + 1);
//                list.remove(list.size()-1);
//            }
//        }
//    }
//    private boolean isValid(String s){
//        if(s.charAt(0) == '0')
//            return s.equals("0"); // to eliminate cases like "00", "10"
//        int digit = Integer.valueOf(s);
//        return digit >= 0 && digit <= 255;
//    }
//
//}
