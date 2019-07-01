
/**
 *Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
 */
class Solution {//关于有向图的边的遍历，找出一条经过所有边的路径
public:
    // 图建立好了以后，从节点JFK开始遍历，只要当前节点映射的multiset里有节点，我们取出这个节点，将其在multiset里删掉，
    // 然后继续递归遍历这个节点，由于题目中限定了一定会有解，那么等图中所有的multiset中都没有节点的时候，我们把当前节点存入结果中，然后再一层层回溯回去，
    // 将当前节点都存入结果，那么最后结果中存的顺序和需要的相反的，再翻转一下即可
    vector<string> findItinerary(vector<vector<string>>& tickets) {//DFS 回溯
        vector<string> res;
        unordered_map<string, multiset<string>> graph;  //用multiset，可以自动排序
        for(auto& ticket: tickets){ //重建图
            graph[ticket[0]].insert(ticket[1]);
        }
        dfs(graph, res, "JFK");
        return vector<string>(res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string>>& graph, vector<string>& res, string start){
        while (graph[start].size()){
            auto itAdj = graph[start].begin();
            string adj = *itAdj;
            graph[start].erase(itAdj);
            dfs(graph, res, adj);
        }
        res.push_back(start);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {//BFS 借助栈实现回溯
        vector<string> res;
        unordered_map<string, multiset<string>> graph;  //用multiset，可以自动排序
        for(auto& ticket: tickets){ //重建图
            graph[ticket[0]].insert(ticket[1]);
        }
        stack<string> stk{{"JFK"}}; //TODO 注意是双括号
        while(!stk.empty()){
            string node = stk.top();
            if(graph[node].empty()){
                res.push_back(node);
                stk.pop();
            }else{
                auto itAdj = graph[node].begin();
                stk.push(*itAdj);
                graph[node].erase(itAdj);
            }
        }
        return vector<string>(res.rbegin(), res.rend());
    }
};