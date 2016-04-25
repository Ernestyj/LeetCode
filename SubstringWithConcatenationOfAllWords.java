package leetcode21_30;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * You are given a string, s, and a list of words,
 * words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words
 * exactly once and without any intervening characters.
 * 注意：words中的word可以重复

 For example, given:
 s: "barfoothefoobarman"
 words: ["foo", "bar"]
 You should return the indices: [0,9]. (order does not matter).
 *
 * Created by DCLab on 11/13/2015.
 */
public class SubstringWithConcatenationOfAllWords {

    public static void main(String[] args) {
//        String s = "barfoothefoobarman";
//        String[] words = {"foo", "bar"};
//        String s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
//        String[] words = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
//        String s = "wordgoodgoodgoodbestword";
//        String[] words = {"word","good","best","good"};
        //TODO 下面这组答案输出[]，但易超时
        String s =
                "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
        String[] words = {"ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba",
                "ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba",
                "ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba"}
;       System.out.println("s.length():" + s.length());
;       System.out.println("words.length:" + words.length);

        System.out.println("*****RESULT*****");
        List<Integer> indexes = new ArrayList<>();
        indexes = new SubstringWithConcatenationOfAllWords().findSubstring(s, words);
        for (Integer i : indexes) System.out.print(i + " ");
//        for (char[] chars : permutatedList){
//            System.out.println(String.valueOf(chars));
//        }
    }


    /** TODO
     * http://segmentfault.com/a/1190000002625580
     * 首先是要明确用滑块的概念来解决，始终保持L集合中的字符串在滑块中都只出现了一次，
     * 当然设置一个总计数count，当cout等于L集合长度时，即使找了一段符合要求的字符串。
     * 需要用到的内存空间：
     1. 两张哈希表，一张保存L集合中的单词，一张用来保存当前滑块中的单词，key为单词，value为出现次数
     2. count计数，保存当前滑块中的单词总数
     3. left标记，记录滑块左起点
     * 思路：
     1. 遍历一遍单词数组L集合，构造总单词表
     2. 以单词长度为步长，遍历目标字符串，如果当前单词在总单词表内，则进入步骤3；
        反之，则清空当前滑块单词表，将count置零，将left移动到下一位置
     3. 当前滑块档次表中的相应单词计数加1，检查该单词的计数是否小于等于总单词表中该单词的总数，
        如果是，则将count计数加1，进入步骤5；反之，进入步骤4
     4. 根据左起点left收缩滑块，直到收缩到与当前单词相同的字符串片段，将其剔除之后，滑块的收缩工作完成。
        （收缩滑块，这是因为当前滑块中有单词的出现次数超过了额定的出现次数，
        那么就是需要收缩滑块来剔除这个单词，相当于是从滑块的左起点开始寻找该单词，找到之后，
        将该单词的右端点作为滑块新的左起点，这样就保证了滑块中所有单词都是小于等于额定出现次数，
        这样也保证了count计数的有效性）
     5. 如果当前count计数等于单词集合长度，记录下left左起点的位置后，将left右移，
        当前滑块中相应单词计数减1，总计数减1，继续循环。
     *
     * 复杂度：因为每次扫描的时间复杂度是O(2*n/l)
     * (每个单词不会被访问多于两次，一次是窗口右端，一次是窗口左端)，总共扫描l次（i=0, ..., l-1)，
     * 所以总复杂度是O(2*n/l*l)=O(n)，是一个线性算法。
     * 空间复杂度是字典的大小，即O(m*l)，其中m是字典的单词数量。
     * @param s
     * @param words
     * @return
     */
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> indexes = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) return indexes;
        int wLen = words[0].length();
        HashMap<String,Integer> book = new HashMap<String,Integer>();
        for (int k = 0; k < words.length; k++){
            if (book.containsKey(words[k])) book.put(words[k], book.get(words[k]) + 1);
            else book.put(words[k], 1);
        }
        for(int i = 0; i < wLen; i++) {
            HashMap<String,Integer> curMap = new HashMap<String,Integer>();
            int count = 0;
            int left = i;   //left标记，记录滑块左起点
            //以单词长度为步长，遍历目标字符串
            for(int right = i; right <= s.length() - wLen; right += wLen) {
                String str = s.substring(right, right + wLen);
                if(book.containsKey(str)) { //当前单词在总单词表内
                    //set frequency in current map
                    if(curMap.containsKey(str)) curMap.put(str, curMap.get(str) + 1);
                    else curMap.put(str, 1);
                    //该单词的计数 <= 单词表中该单词的总数
                    if(curMap.get(str) <= book.get(str)) count++;
                    else {
                        while(curMap.get(str) > book.get(str)) {
                            //根据左起点left收缩滑块
                            String temp = s.substring(left, left + wLen);
                            //直到收缩到与当前单词相同的字符串片段
                            if(curMap.containsKey(temp)) {
                                //将其剔除之后，滑块的收缩工作完成
                                curMap.put(temp, curMap.get(temp) - 1);
                                if(curMap.get(temp) < book.get(temp)) count--;
                            }
                            left += wLen;
                        }
                    }
                    //如果当前count计数等于单词集合长度
                    if(count == words.length) {
                        //记录下left左起点的位置
                        indexes.add(left);
                        //将left右移
                        String temp = s.substring(left, left + wLen);
                        //当前滑块中相应单词计数减1
                        if(curMap.containsKey(temp)) curMap.put(temp, curMap.get(temp) - 1);
                        //总计数减1
                        count--;
                        left += wLen;
                    }
                } else {    //当前单词不在总单词表内
                    curMap.clear();
                    count = 0;
                    left = right + wLen;
                }
            }
        }
        return indexes;
    }


    /**
     * TODO 没有采用窗口方法，超时
     * 超时用例：
     * "ababababababababababa..."
     * {"ab","ba","ab","ba", ...}
     * @param s
     * @param words
     * @return
     */
    public List<Integer> findSubstring1(String s, String[] words) {
        List<Integer> indexes = new ArrayList<>();
        if (s == null || words == null || words.length == 0) return indexes;
        HashMap<String, Integer> map;
        for (int i = 0; i <= s.length() - words.length * words[0].length(); i++){//TODO 注意取等
            //也可以采用HashMap.clone()进行浅拷贝（针对基本类型和String类型可以说是“深拷贝”）
            map = new HashMap<>();
            for (int k = 0; k < words.length; k++){
                if (map.get(words[k]) != null) map.put(words[k], map.get(words[k]) + 1);
                else map.put(words[k], 1);
            }
            int count = 0;
            int headIndex = 0;
            for (int j = i; j < s.length(); j += words[0].length()){ //匹配内的循环，步长为一个word长度
                String temp = s.substring(j, j + words[0].length());
                if (map.get(temp) != null && map.get(temp) > 0){    //匹配words中存在的字
                    map.put(temp, map.get(temp) - 1);
                    count++;
                    if (count == 1){    //标记匹配的头索引
                        headIndex = j;
                    }
                    if (count == words.length){ //全匹配
                        indexes.add(headIndex);
                        break;
                    }
                }else{  //不匹配则跳出循环
                    break;
                }
            }
        }
        return indexes;
    }


    /**
     * TODO 全排列words再匹配，超时
     * 超时用例：
     * "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel"
     ["dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"]
     */
    static List<char[]> permutatedList = new ArrayList<>();
    public List<Integer> findSubstring2(String s, String[] words) {
        List<Integer> indexes = new ArrayList<>();
        if (s == null || words == null || words.length == 0) return indexes;

        permutation(words, 0, words.length);

        for (int i = 0; i < s.length(); i++){
            for (char[] tempCombinedArray : permutatedList){
                if (i + tempCombinedArray.length < s.length()){
                    String temp = s.substring(i, i + tempCombinedArray.length);
                    if (temp.equals(String.valueOf(tempCombinedArray))) indexes.add(i);
                }
            }
        }
        return indexes;
    }
    private StringBuilder builder;
    private void permutation(String[] str, int start, int len) {
        if (start == len - 1) {
            builder = new StringBuilder();
            for (int i = 0; i < len; i ++) {
                builder.append(str[i]);
            }
            permutatedList.add(builder.toString().toCharArray());
        }
        else {
            for (int i = start; i < len; i ++) {
                swap(str, start, i);
                permutation(str, start + 1, len);
                swap(str, start, i);
            }
        }

    }
    private void swap(String[] s, int i, int j) {
        String temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}
