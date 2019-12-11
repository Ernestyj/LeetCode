
/**Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * https://leetcode.com/problems/clone-graph/
 * Created by eugene on 16/2/21.
 */
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {}
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> map;
        return clone(node, map);
    }
    Node* clone(Node* node, unordered_map<int, Node*>& map){    //recursive
        if(!node) return nullptr;
        if(map.count(node->val)) return map[node->val];
        else{
            Node* newNode = new Node(node->val, vector<Node*>());
            map[node->val] = newNode;
            for (int i = 0; i < node->neighbors.size(); ++i) {
                (newNode->neighbors).push_back(clone((node->neighbors)[i], map));
            }
            return newNode;
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> m;
        queue<Node*> q{{node}};
        Node *clone = new Node(node->val);
        m[node] = clone;
        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            for (Node *neighbor : t->neighbors) {
                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[t]->neighbors.push_back(m[neighbor]);
            }
        }
        return clone;
    }
};
//public class CloneGraph {
//    class UndirectedGraphNode {
//        int label;
//        List<UndirectedGraphNode> neighbors;
//        UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
//    }
//    /**
//     * 无向图深拷贝,BFS
//     */
//    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
//        if(node==null) return null;
//        LinkedList<UndirectedGraphNode> q = new LinkedList<>();
//        HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<>();
//        q.offer(node);
//        UndirectedGraphNode newHead = new UndirectedGraphNode(node.label);
//        map.put(node, newHead);
//        while(!q.isEmpty()){
//            UndirectedGraphNode old = q.poll();
//            for(UndirectedGraphNode oldN: old.neighbors){
//                if(!map.containsKey(oldN)){
//                    map.put(oldN, new UndirectedGraphNode(oldN.label));
//                    q.offer(oldN);
//                }
//                map.get(old).neighbors.add(map.get(oldN));//TODO 注意是add(map.get(oldN))，不是add(oldN)
//            }
//        }
//        return newHead;
//    }
//
//    //无向图深拷贝,BFS,比上面的方法慢
//    public UndirectedGraphNode cloneGraph1(UndirectedGraphNode node) {
//        if (node==null) return null;
//        Queue<UndirectedGraphNode> queue = new LinkedList<>();
//        Queue<UndirectedGraphNode> originQueue = new LinkedList<>();
//        Map<Integer, UndirectedGraphNode> map = new HashMap<>();
//        queue.offer(node);
//        originQueue.offer(node);
//        map.put(node.label, new UndirectedGraphNode(node.label));
//        while (!queue.isEmpty()) {
//            UndirectedGraphNode theNode = queue.poll();
//            for (UndirectedGraphNode n : theNode.neighbors){
//                if (!map.containsKey(n.label)){
//                    map.put(n.label, new UndirectedGraphNode(n.label));
//                    queue.offer(n);
//                    originQueue.offer(n);
//                }
//            }
//        }
//        while (!originQueue.isEmpty()) {
//            UndirectedGraphNode theNode = originQueue.poll();
//            UndirectedGraphNode newNode = map.get(theNode.label);
//            for (UndirectedGraphNode n : theNode.neighbors){
//                newNode.neighbors.add(map.get(n.label));
//            }
//        }
//        return map.get(node.label);
//    }
//
//}
