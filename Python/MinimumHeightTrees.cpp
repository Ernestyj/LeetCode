
/**For a undirected graph with tree characteristics, we can choose any node as the root.
 The result graph is then a rooted tree. Among all possible rooted trees,
 those with minimum height are called minimum height trees (MHTs).
 Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 Format
 The graph contains n nodes which are labeled from 0 to n - 1.
 You will be given the number n and a list of undirected edges (each edge is a pair of labels).

 You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
 [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 Note:
 (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices
 are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
 (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 * Created by eugene on 16/6/11.
 */
class Solution {
public:
    //Remove the leaves, update the degrees of inner vertexes. Then remove the new leaves.
    //Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!
    //The time complexity and space complexity are both O(n).
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> res;
        vector<unordered_set<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        queue<int> q;   //存放叶子节点
        for (int i = 0; i < n; ++i) {
            if(adj[i].size()==1) q.push(i); 
        }
        while(n>2){
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int t = q.front();
                q.pop();
                for(auto& a: adj[t]){   //从t的adj移除节点t
                    adj[a].erase(t);
                    if(adj[a].size()==1) q.push(a);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
//public class MinimumHeightTrees {
//    /**https://leetcode.com/discuss/71763/share-some-thoughts
//     * Remove the leaves, update the degrees of inner vertexes. Then remove the new leaves.
//     Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!
//     The time complexity and space complexity are both O(n).
//     */
//    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
//        if (n==1) return Collections.singletonList(0);
//        ArrayList<HashSet<Integer>> adjs = new ArrayList<>(n);
//        for (int i=0; i<n; i++) adjs.add(new HashSet<>());
//        for (int[] e: edges){
//            adjs.get(e[0]).add(e[1]);
//            adjs.get(e[1]).add(e[0]);
//        }
//        ArrayList<Integer> leaves = new ArrayList<>();
//        for (int i=0; i<n; i++)
//            if (adjs.get(i).size()==1) leaves.add(i);
//        while (n>2){
//            n -= leaves.size();
//            ArrayList<Integer> newLeaves = new ArrayList<>();
//            for (int i: leaves){
//                int adjOfLeaf = adjs.get(i).iterator().next();
//                adjs.get(adjOfLeaf).remove(i);
//                if (adjs.get(adjOfLeaf).size()==1) newLeaves.add(adjOfLeaf);
//            }
//            leaves = newLeaves;
//        }
//        return leaves;
//    }
//
//
//}
