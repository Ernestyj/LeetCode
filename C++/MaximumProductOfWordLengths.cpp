
/**Given a string array words, find the maximum value of length(word[i]) * length(word[j])
 where the two words do not share common letters. You may assume that each word will
 contain only lower case letters. If no such two words exist, return 0.
 Example 1:
 Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 Return 16
 The two words can be "abcw", "xtfn".
 Example 2:
 Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 Return 4
 The two words can be "ab", "cd".
 Example 3:
 Given ["a", "aa", "aaa", "aaaa"]
 Return 0
 No such pair of words.
 * Created by eugene on 16/6/15.
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()<=1) return 0;
        vector<int> masks(words.size(), 0);
        int maxRes = 0;
        for (int i = 0; i < words.size(); ++i) {    //用一个int的26位去保存每个单词所包含的字母的信息
            for (auto& c: words[i]) {
                masks[i] |= 1 << c-'a';
            }
            for (int j = 0; j < i; ++j) {
                if((masks[i]&masks[j])==0){   //两个单词没有共同字母, TODO 一定要加括号，==优先级高于&
                    maxRes = max(maxRes, int(words[i].size()*words[j].size())); //注意强转int，否则size_type不会自动转，max签名报错
                }
            }
        }
        return maxRes;
    }
};
//public class MaximumProductOfWordLengths {
//
//    /**TODO 注意理解题意,length(word[i])*length(word[j])表示两个单词完整长度乘积
//     * https://leetcode.com/discuss/82920/java-easy-version-to-understand
//     * 位操作, O(n^2) 一个整型数int有32位，我们可以用后26位来对应26个字母，若为1，说明该对应位置的字母出现过，那么每个单词的都可由一个int数字表示，
//     两个单词没有共同字母的条件是这两个int数想与为0
//     */
//    public int maxProduct(String[] words) {
//        if (words == null || words.length <= 1) return 0;
//        int len = words.length;
//        int[] masks = new int[len];
//        for (int i=0; i<len; i++) { //用一个int的26位去保存每个单词所包含的字母的信息
//            masks[i] = 0;
//            for (int j=0; j<words[i].length(); j++) {
//                masks[i] |= (1 << words[i].charAt(j)-'a');
//            }
//        }
//        int max = 0;
//        for (int i = 0; i < len; i++) {
//            for (int j = i + 1; j < len; j++) {
//                if ((masks[i] & masks[j]) == 0) {
//                    max = Math.max(max, words[i].length()*words[j].length());
//                }
//            }
//        }
//        return max;
//    }
//
//
//    //超时 TODO 此法可检测两个单词非完整长度乘积最大值
//    public int maxProduct1(String[] words) {
//        int max = 0;
//        for (int i=0; i<words.length; i++){
//            char[] A = words[i].toCharArray();
//            for (int j=i+1; j<words.length; j++){
//                char[] B = words[j].toCharArray();
//                max = Math.max(max, maxProduct(A, B));
//            }
//        }
//        return max;
//    }
//    private static int maxProduct(char[] A, char[] B){
//        int max = 0;
//        HashSet<Character> setA = new HashSet<>();
//        int i, j;
//        for (i=0; i<A.length; i++){
//            setA.add(A[i]);
//            for (j=0; j<B.length; j++){
//                if (setA.contains(B[j])) break;
//            }
//            max = Math.max(max, (i+1)*(j));
//        }
//        return max;
//    }
//
//}
