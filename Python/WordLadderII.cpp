
/**Given two words (beginWord and endWord), and a dictionary's word list,
 find all shortest transformation sequence(s) from beginWord to endWord, such that:
 1 Only one letter can be changed at a time
 2 Each intermediate word must exist in the word list
 For example,
 Given: beginWord = "hit" endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 Return
 [ ["hit","hot","dot","dog","cog"],
 ["hit","hot","lot","log","cog"] ]
 Note:
 All words have the same length.
 All words contain only lowercase alphabetic characters.
 */
class Solution {
public:
    //TODO 待理解
    /*BFS：建立一个路径集paths，用以保存所有路径，然后是起始路径p，在p中先把起始单词放进去。
     * 然后定义两个整型变量level，和minLevel，其中level是记录循环中当前路径的长度，minLevel是记录最短路径的长度，
     * 这样的好处是，如果某条路径的长度超过了已有的最短路径的长度，那么舍弃，这样会提高运行速度，相当于一种剪枝。
     * 还要定义一个set变量words，用来记录已经循环过的路径中的词.
     *
     * 然后就是BFS的核心了，循环路径集paths里的内容，取出队首路径，如果该路径长度大于level，说明字典中的有些词已经存入路径了，
     * 如果在路径中重复出现，则肯定不是最短路径，所以我们需要在字典中将这些词删去，然后将words清空，对循环对剪枝处理。
     * 然后我们取出当前路径的最后一个词，对每个字母进行替换并在字典中查找是否存在替换后的新词，这个过程在之前那道 Word Ladder 里面也有。
     * 如果替换后的新词在字典中存在，将其加入words中，并在原有路径的基础上加上这个新词生成一条新路径，
     * 如果这个新词就是结束词，则此新路径为一条完整的路径，加入结果中，并更新minLevel，若不是结束词，解将新路径加入路径集中继续循环。
     */
    vector <vector<string>> findLadders(string beginWord, string endWord, vector <string> &wordList) {
        vector <vector<string>> res;
        unordered_set <string> dict(wordList.begin(), wordList.end());
        vector <string> path{beginWord};
        queue <vector<string>> paths;
        paths.push(path);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front();
            paths.pop();
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector <string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};
//public class WordLadderII {
//
//    class WordNode{
//        String word;
//        List<String> transformList; //TODO 这里可以改成存储WordNode pre来优化性能
//
//        public WordNode(String word, List<String> oldTransformList){
//            this.word = word;
//            transformList = new ArrayList<>(oldTransformList);
//            transformList.add(word);
//        }
//        public int getSteps(){
//            return transformList.size();
//        }
//    }
//
//    /**
//     * 分支限界法(BFS,最短路径),与Word Ladder思路类似,不同点在于
//     1 不能直接从wordList中直接删除访问过的字符串,需要引入两个新的集合,
//     只有转换步数发生变化,才从字典中移除(观察到不同转换序列不可能出现重复的词,除了首尾两个词);
//     2 引入的数据结构WordNode多一个字段
//     * http://www.programcreek.com/2014/06/leetcode-word-ladder-ii-java/
//     */
//    public List<List<String>> findLadders(String beginWord, String endWord, Set<String> wordList) {
//        List<List<String>> result = new ArrayList<>();
//        Queue<WordNode> queue = new LinkedList<>();
//        queue.offer(new WordNode(beginWord, new ArrayList<>()));
//        wordList.add(endWord);
//        //不能直接从wordList中直接删除访问过的字符串,引入两个新的集合
//        Set<String> visited = new HashSet<>();
//        Set<String> unVisited = new HashSet<>(wordList);
//        int minSteps = Integer.MAX_VALUE;
//        int preSteps = 1;
//        while (!queue.isEmpty()){
//            WordNode top = queue.poll();
//            int curSteps = top.getSteps();
//            if (top.word.equals(endWord)) {
//                if (curSteps > minSteps) return result;
//                minSteps = curSteps;
//                result.add(top.transformList);
//            }
//            //只有转换步数发生变化,才从字典中移除(观察到不同转换序列不可能出现重复的词,除了首尾两个词)
//            if (curSteps > preSteps) {
//                unVisited.removeAll(visited);
//                preSteps = curSteps;
//            }
//            char[] chars = top.word.toCharArray();
//            for (int i=0; i<chars.length; i++){
//                char origin = chars[i];
//                for (char c='a'; c<='z'; c++){
//                    if (chars[i]!=c) chars[i] = c;
//                    String newString = new String(chars);   //TODO 千万别写成了chars.toString();
//                    if (unVisited.contains(newString)){
//                        queue.offer(new WordNode(newString, top.transformList));
//                        visited.add(newString);
//                    }
//                }
//                chars[i] = origin;
//            }
//        }
//        return result;
//    }
//
//}
