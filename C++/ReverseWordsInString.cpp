
/**Given an input string, reverse the string word by word.
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 * Created by eugene on 16/3/10.
 */
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token, res;
        while(getline(ss, token, ' ')){
            if(token!="") res = token+" "+res;
        }
        res.pop_back();//可以不检测res.empty()
        return res;
    }

    string reverseWords(string s) {
        if(!s.size()) return "";
        istringstream is(s);
        string temp;
        is >> s;    // if s="  ", is>>s and s will remain original val
        while(is >> temp){
            s = temp+" "+s;
        }
        if(s[0]==' ') return "";
        return s;
    }
};
//public class ReverseWordsInString {
//
//    //神奇的写法
//    public String reverseWords(String s) {
//        String[] words = s.trim().split(" +");
//        Collections.reverse(Arrays.asList(words));//TODO words被in place修改了?
//        return String.join(" ", words);
//    }
//
//    //注意split对""的结果返回长度为1的数组,且第一个元素为""
//    public String reverseWords1(String s) {
//        if (s.length()==0) return "";
//        String trimed = s.trim();
//        if (trimed.length()==0) return "";
//        String[] strings = trimed.split("\\s+");
//        StringBuilder builder = new StringBuilder();
//        for (int i=strings.length-1; i>=0; i--){
//            builder.append(strings[i]+" ");
//        }
//        return builder.toString().trim();
//    }
//
//}
