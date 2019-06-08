
/**
 * Given an absolute path for a file (Unix-style), simplify it.
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".
 * Created by DCLab on 12/23/2015.
 */
class Solution {
public:
    string simplifyPath(string path) {
        string res, token;
        stringstream ss(path);
        vector<string> v;
        while(getline(ss, token, '/')){
            if(token=="" || token==".") continue;
            else if(token=="..") {
                if(!v.empty()) v.pop_back();
            }
            else v.push_back(token);
        }
        if(v.empty()) return "/";
        for(auto s: v) res += "/"+s;
        return res;
    }
};
//public class SimplifyPath {
//
//    public String simplifyPath(String path) {
//        String[] strings = path.split("/");
//        Stack<String> stack = new Stack<>();
//        for (int i=1; i<strings.length; i++){
//            String s = strings[i];
//            if (s.length() == 0) continue;
//            if (s.equals(".")) ;
//            else if (s.equals("..")) { if (!stack.isEmpty()) stack.pop(); }//TODO 加大括号
//            else stack.push(strings[i]);
//        }
//        if (stack.isEmpty()) return "/";
//        StringBuilder builder = new StringBuilder();
//        for (Object o : stack.toArray()) builder.append("/" + o);
//        return builder.toString();
//    }
//
//}
