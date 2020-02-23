
/**有时，确保我们永远不会访问一个结点两次很重要。否则，我们可能陷入无限循环。如果是这样，我们可以在上面的代码中添加一个哈希集来解决这个问题。
 * 有两种情况你不需要使用哈希集：1. 你完全确定没有循环，例如，在树遍历中；2.你确实希望多次将结点添加到队列中。
 * Return the length of the shortest path between root and target node.
 */
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    Set<Node> used;     // store all the used nodes
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    add root to used;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                if (next is not in used) {
                    add next to queue;
                    add next to used;
                }
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target

/**752 Open the Lock   
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, 
return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"   Output: 6 
Explanation: A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202". 
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid, 
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        if '0000' in deadends: return -1
        q = collections.deque() #1
        visited = set()         #2
        step = 0                #3
        q.append("0000")        #4
        visited.add("0000")     #5
        while q:                    #6
            step += 1               #7
            for _ in range(len(q)): #8
                seq = q.popleft()   #9
                for i in range(4):              #10
                    for direction in [-1, 1]:   #10
                        newSeq = list(seq[:])
                        newSeq[i] = str((int(seq[i])+direction+10)%10)
                        newSeq = "".join(newSeq)
                        if newSeq==target: return step  #11
                        if newSeq not in deadends and newSeq not in visited:    #12
                            q.append(newSeq)    #13
                            visited.add(newSeq) #14
        return -1
            

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
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {  //分支限界法(BFS,最短路径)
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 1;
        while (!q.empty()){
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord(word);
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if(dict.count(newWord)){
                        if(newWord==endWord) return m[word]+1;
                        else if(!m.count(newWord)){
                            q.push(newWord);
                            m[newWord] = m[word]+1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
//public class WordLadder {
//
//    class WordNode{
//        String word;
//        int numSteps;
//        public WordNode(String word, int numSteps){
//            this.word = word;
//            this.numSteps = numSteps;
//        }
//    }
//    /**
//     * http://www.programcreek.com/2012/12/leetcode-word-ladder/
//     * 分支限界法(BFS,最短路径),算法引入WordNode数据结构
//     */
//    public int ladderLength1(String beginWord, String endWord, Set<String> wordList) {
//        Queue<WordNode> queue = new LinkedList<>();
//        queue.add(new WordNode(beginWord, 1));
//        wordList.add(endWord);
//        while(!queue.isEmpty()){
//            WordNode node = queue.remove();
//            String word = node.word;
//            if(word.equals(endWord)) return node.numSteps;
//
//            char[] chars = word.toCharArray();
//            for(int i=0; i<chars.length; i++){
//                for(char c='a'; c<='z'; c++){
//                    char temp = chars[i];
//                    if(chars[i]!=c) chars[i] = c;
//                    String newWord = new String(chars);
//                    if(wordList.contains(newWord)){
//                        queue.add(new WordNode(newWord, node.numSteps+1));
//                        wordList.remove(newWord);
//                    }
//                    chars[i] = temp;
//                }
//            }
//        }
//        return 0;
//    }
//
//}
