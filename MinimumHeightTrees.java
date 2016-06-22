package leetcode301_310;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

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
public class MinimumHeightTrees {

    /**https://leetcode.com/discuss/71763/share-some-thoughts
     * Remove the leaves, update the degrees of inner vertexes. Then remove the new leaves.
     Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!
     The time complexity and space complexity are both O(n).
     * @param n
     * @param edges
     * @return
     */
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n==1) return Collections.singletonList(0);
        ArrayList<HashSet<Integer>> adjs = new ArrayList<>(n);
        for (int i=0; i<n; i++) adjs.add(new HashSet<>());
        for (int[] e: edges){
            adjs.get(e[0]).add(e[1]);
            adjs.get(e[1]).add(e[0]);
        }
        ArrayList<Integer> leaves = new ArrayList<>();
        for (int i=0; i<n; i++)
            if (adjs.get(i).size()==1) leaves.add(i);
        while (n>2){
            n -= leaves.size();
            ArrayList<Integer> newLeaves = new ArrayList<>();
            for (int i: leaves){
                int adjOfLeaf = adjs.get(i).iterator().next();
                adjs.get(adjOfLeaf).remove(i);
                if (adjs.get(adjOfLeaf).size()==1) newLeaves.add(adjOfLeaf);
            }
            leaves = newLeaves;
        }
        return leaves;
    }


}
