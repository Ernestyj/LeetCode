#include <string>
#include <iostream>
#include <stack>
using namespace std;
/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid
 but "(]" and "([)]" are not.
 *
 * Created by DCLab on 11/3/2015.
 */
class Solution {
public:
    bool isValid(string s) {
        size_t preLen = 0;
        while(preLen!=s.size()){
            preLen = s.size();
            findAndReplaceAll(s, "()", "");
            findAndReplaceAll(s, "[]", "");
            findAndReplaceAll(s, "{}", "");
        }
        return s.empty();
    }
    void findAndReplaceAll(string& s, const string& searchStr, const string& replaceStr){
        auto pos = s.find(searchStr);
        while(pos!=string::npos){
            s.replace(pos, searchStr.size(), replaceStr);
            pos = s.find(searchStr, pos+replaceStr.size());
        }
    }

    bool isValid1(string s) {
        stack<char> v;
        for(auto c: s){
            switch (c){
                case '(':
                case '[':
                case '{':
                    v.push(c);
                    break;
                case ')':
                    if(v.empty() || v.top()!='(') return false;
                    v.pop();
                    break;
                case ']':
                    if(v.empty() || v.top()!='[') return false;
                    v.pop();
                    break;
                case '}':
                    if(v.empty() || v.top()!='{') return false;
                    v.pop();
                    break;

            }
        }
        return v.empty();
    }
};

//int main(){
//    Solution s;
//    string data = "()";
//    cout<<s.isValid(data)<<endl;
//}


//public class ValidParentheses {
//
//    //巧妙法,但速度很慢
//    public boolean isValid(String s) {
//        int preLen = -1;
//        while (preLen!=s.length()){
//            preLen = s.length();
//            s = s.replace("()", "").replace("{}", "").replace("[]", "");
//        }
//        return s.length()==0;
//    }
//
//    public boolean isValid1(String s) {
//        LinkedList<Character> stack = new LinkedList<>();
//        for(char c: s.toCharArray()){
//            switch(c){
//                case '(': case '[': case '{': stack.push(c); break;
//                case ')': if(stack.isEmpty() || stack.pop()!='(') return false; break; //TODO 判空易漏（短路求值）
//                case ']': if(stack.isEmpty() || stack.pop()!='[') return false; break;
//                case '}': if(stack.isEmpty() || stack.pop()!='{') return false; break;
//            }
//        }
//        return stack.isEmpty(); //TODO 易漏 如"("这种情况应排除
//    }
//
//}
