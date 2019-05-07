package leetcode131_140;

import java.util.*;

/**Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * https://leetcode.com/problems/clone-graph/
 * Created by eugene on 16/2/21.
 */
public class CloneGraph {

    class UndirectedGraphNode {
        int label;
        List<UndirectedGraphNode> neighbors;
        UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
    }

    /**
     * 无向图深拷贝,BFS
     * @param node
     * @return
     */
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node==null) return null;
        LinkedList<UndirectedGraphNode> q = new LinkedList<>();
        HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<>();
        q.offer(node);
        UndirectedGraphNode newHead = new UndirectedGraphNode(node.label);
        map.put(node, newHead);
        while(!q.isEmpty()){
            UndirectedGraphNode old = q.poll();
            for(UndirectedGraphNode oldN: old.neighbors){
                if(!map.containsKey(oldN)){
                    map.put(oldN, new UndirectedGraphNode(oldN.label));
                    q.offer(oldN);
                }
                map.get(old).neighbors.add(map.get(oldN));//TODO 注意是add(map.get(oldN))，不是add(oldN)
            }
        }
        return newHead;
    }

    //无向图深拷贝,BFS,比上面的方法慢
    public UndirectedGraphNode cloneGraph1(UndirectedGraphNode node) {
        if (node==null) return null;
        Queue<UndirectedGraphNode> queue = new LinkedList<>();
        Queue<UndirectedGraphNode> originQueue = new LinkedList<>();
        Map<Integer, UndirectedGraphNode> map = new HashMap<>();
        queue.offer(node);
        originQueue.offer(node);
        map.put(node.label, new UndirectedGraphNode(node.label));
        while (!queue.isEmpty()) {
            UndirectedGraphNode theNode = queue.poll();
            for (UndirectedGraphNode n : theNode.neighbors){
                if (!map.containsKey(n.label)){
                    map.put(n.label, new UndirectedGraphNode(n.label));
                    queue.offer(n);
                    originQueue.offer(n);
                }
            }
        }
        while (!originQueue.isEmpty()) {
            UndirectedGraphNode theNode = originQueue.poll();
            UndirectedGraphNode newNode = map.get(theNode.label);
            for (UndirectedGraphNode n : theNode.neighbors){
                newNode.neighbors.add(map.get(n.label));
            }
        }
        return map.get(node.label);
    }

}
