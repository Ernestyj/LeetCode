#include <string>
#include <iostream>
using namespace std;
/**
 * Implement strStr().
 Returns the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.
 实现strstr(). 返回needle(关键字)在haystack(字符串)中第一次出现的位置，
 如果needle不在haystack中，则返回-1。
 注：strstr()是c++中的一个函数
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
 *
 * Created by DCLab on 11/11/2015.
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.size()<needle.size()) return -1;//TODO: 不能漏，因为haystack.size()-needle.size()可能为大正数
        int start = 0;
        for(; start<=haystack.size()-needle.size(); ++start){
            for(int j=0; j<needle.size(); ++j){
                if(haystack[start+j]!=needle[j]) break;
                if(j==needle.size()-1) return start;
            }
        }
        return -1;
    }
};

//int main(){
//    Solution s;
//    auto result = s.strStr("aaa", "aaaa");
//    cout<<"result="<<result<<endl;
//}

//public class ImplementStrStr {
//
//    //按思路写
//    public int strStr(String haystack, String needle) {
//        int l1 = haystack.length(), l2 = needle.length();
//        if(l2==0) return 0; //TODO 不能漏
//        for(int start=0; start<=l1-l2; start++){
//            for(int j=0; j<l2; j++){
//                if(haystack.charAt(start+j)!=needle.charAt(j)) break;
//                if(j==l2-1) return start;
//            }
//        }
//        return -1;
//    }
//
//}
