package leetcode71_80;


import java.util.Arrays;
import java.util.Stack;

/**
 * Given an absolute path for a file (Unix-style), simplify it.
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 * Created by DCLab on 12/23/2015.
 */
public class SimplifyPath {

    public static void main(String[] args) {
//        String path = "/a/./b/../../c/";
//        String path = "/home/";
        String path = "/home//foo/";
        System.out.println("*****RESULT*****");
        System.out.println(new SimplifyPath().simplifyPath(path));
    }


    public String simplifyPath(String path) {
        String[] strings = path.split("/");
        Stack<String> stack = new Stack<>();
        for (int i=1; i<strings.length; i++){
            String s = strings[i];
            if (s.length() != 0){
                if (s.equals(".")){
                }else if (s.equals("..")){
                    if (!stack.isEmpty()) stack.pop();
                }else {
                    stack.push(strings[i]);
                }
            }
        }
        if (stack.isEmpty()) return "/";
        else {
            StringBuilder builder = new StringBuilder();
            Object[] array = stack.toArray();
            for (Object o : array) builder.append("/" + o);
            return builder.toString();
        }
    }

}
