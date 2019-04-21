package leetcode121_130;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/**Given two words (beginWord and endWord), and a dictionary's word list,
 find the length of shortest transformation sequence from beginWord to endWord, such that:
 1 Only one letter can be changed at a time
 2 Each intermediate word must exist in the word list
 For example,
 Given: beginWord = "hit" endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.
 * Created by eugene on 16/2/14.
 */
public class WordLadder {

    class WordNode{
        String word;
        int numSteps;
        public WordNode(String word, int numSteps){
            this.word = word;
            this.numSteps = numSteps;
        }
    }
    /**
     * http://www.programcreek.com/2012/12/leetcode-word-ladder/
     * 分支限界法(BFS,最短路径),算法引入WordNode数据结构
     * @param beginWord
     * @param endWord
     * @param wordList
     * @return
     */
    public int ladderLength1(String beginWord, String endWord, Set<String> wordList) {
        Queue<WordNode> queue = new LinkedList<>();
        queue.add(new WordNode(beginWord, 1));
        wordList.add(endWord);
        while(!queue.isEmpty()){
            WordNode node = queue.remove();
            String word = node.word;
            if(word.equals(endWord)) return node.numSteps;

            char[] chars = word.toCharArray();
            for(int i=0; i<chars.length; i++){
                for(char c='a'; c<='z'; c++){
                    char temp = chars[i];
                    if(chars[i]!=c) chars[i] = c;
                    String newWord = new String(chars);
                    if(wordList.contains(newWord)){
                        queue.add(new WordNode(newWord, node.numSteps+1));
                        wordList.remove(newWord);
                    }
                    chars[i] = temp;
                }
            }
        }
        return 0;
    }

}
