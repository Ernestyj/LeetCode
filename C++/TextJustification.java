package leetcode61_70;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Given an array of words and a length L, format the text such that each line has exactly L
 * characters and is fully (left and right) justified.

 You should pack your words in a greedy approach; that is, pack as many words as you can
 in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

 Extra spaces between words should be distributed as evenly as possible.
 If the number of spaces on a line do not divide evenly between words,
 the empty slots on the left will be assigned more spaces than the slots on the right.

 For the last line of text, it should be left justified and no extra space is inserted
 between words.
 注意两个点，a、当该行只放一个单词时，空格全部在右边
 b、最后一行中单词间只有一个空格，其余空格全部在右边。然后只要贪心选择，在一行中尽量放多的单词。
 * Created by DCLab on 12/20/2015.
 */
public class TextJustification {
    //TODO 待处理
    /**https://leetcode.com/discuss/13610/share-my-concise-c-solution-less-than-20-lines
     * For each line, I first figure out which words can fit in. According to the code,
     these words are words[i] through words[i+k-1]. Then spaces are added between the words.
     The trick here is to use mod operation to manage the spaces that can't be evenly distrubuted:
     the first (L-l) % (k-1) gaps acquire an additional space.
     * @param words
     * @param L
     * @return
     */
    public List<String> fullJustify(String[] words, int L) {
        List<String> list = new LinkedList<>();
        for (int i = 0, w; i < words.length; i = w) {
            int len = -1;
            for (w = i; w < words.length && len + words[w].length() + 1 <= L; w++) {
                len += words[w].length() + 1;
            }
            StringBuilder strBuilder = new StringBuilder(words[i]);
            int space = 1, extra = 0;
            if (w != i + 1 && w != words.length) { // not 1 char, not last line
                space = (L - len) / (w - i - 1) + 1;
                extra = (L - len) % (w - i - 1);
            }
            for (int j = i + 1; j < w; j++) {
                for (int s = space; s > 0; s--) strBuilder.append(' ');
                if (extra-- > 0) strBuilder.append(' ');
                strBuilder.append(words[j]);
            }
            int strLen = L - strBuilder.length();
            while (strLen-- > 0) strBuilder.append(' ');
            list.add(strBuilder.toString());
        }
        return list;
    }

    /**TODO 边界极易出错 HARD
     * 每行中，有下一个单词，才需要补一个空格。
     * 算法中，跳到新一行首个单词，才将上一行写入结果（而不是在上一行末单词判断写入）。
     * http://blog.csdn.net/linhuanmars/article/details/24063271
     * @param words
     * @param maxWidth
     * @return
     */
    public List<String> fullJustify1(String[] words, int maxWidth) {
        ArrayList<String> res = new ArrayList<>();
        if(words==null || words.length==0) return res;
        int count = 0;
        int lastHead = 0;   //上一行第一个元素
        for(int i=0; i<words.length; i++) {
            int wordCount = i-lastHead; //wordCount不含当前第i个
            if(count + words[i].length() + wordCount > maxWidth) {  //此时i是新一行的首个单词
                int avgSpaceNum = 0;   //上一行平均空格数
                int extraSpaceNum = 0;   //上一行额外空格数
                if(wordCount-1 > 0) {
                    avgSpaceNum = (maxWidth-count)/(wordCount-1);
                    extraSpaceNum = (maxWidth-count)%(wordCount-1);
                }
                StringBuilder str = new StringBuilder();
                for(int j=lastHead; j<i; j++) {
                    str.append(words[j]);
                    if(j < i-1) {
                        for(int k=0; k<avgSpaceNum; k++) str.append(" ");   //补平均空格
                        if(extraSpaceNum>0) str.append(" ");    //补额外空格
                        extraSpaceNum--;
                    }
                }
                for(int j=str.length(); j<maxWidth; j++) str.append(" ");   //一个单词时，补末尾
                res.add(str.toString());
                count=0;    //新一行
                lastHead=i; //新一行
            }
            count += words[i].length();
        }
        StringBuilder str = new StringBuilder();
        for(int i=lastHead; i<words.length; i++) {  //最后一行
            str.append(words[i]);
            if(str.length() < maxWidth) str.append(" ");
        }
        for(int i=str.length(); i<maxWidth; i++) str.append(" ");
        res.add(str.toString());
        return res;
    }

}
