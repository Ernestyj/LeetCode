

//判断是否是有向无环图(DAG)，输出拓扑排序结果
class Solution {//Course Schedule II与Course Schedule一样
public:
    //BFS，拓扑排序，关键是要维护一个入度为0的顶点的集合
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {//BFS
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0), res;
        for (auto& edge: prerequisites) {   //重新生成标准邻接表，与题目相关
            graph[edge[1]].push_back(edge[0]);
            ++in[edge[0]];  ////TODO 注意不是++in[edge[1]]与题目相关
        }
        queue<int> q;   //维护入度为0的顶点的队列
        for (int node = 0; node < numCourses; ++node) {
            if(in[node]==0) {
                q.push(node);
                res.push_back(node);
            }
        }
        int in0Count = q.size();
        while(!q.empty()){
            int node = q.front();
            q.pop();    //移除当前in=0的节点
            for(auto& adjNode: graph[node]){
                --in[adjNode];  //相关邻接节点in--
                if(in[adjNode]==0) {
                    q.push(adjNode);
                    ++in0Count;
                    res.push_back(adjNode);
                }
            }
        }
        return in0Count==numCourses? res : vector<int>(0);
    }

    //DFS 关键是维护visited[]防止顶点被多次访问(0还未访问过，1已经访问了，-1正在访问)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> visited(numCourses, 0);
        list<int> res;
        for (auto& edge: prerequisites) {   //重新生成标准邻接表，与题目相关
            graph[edge[1]].push_back(edge[0]);
        }
        for (int node = 0; node < numCourses; ++node) {
            if(!canDFS(graph, visited, res, node)) return vector<int>(0);
        }
        return vector<int>(res.begin(), res.end());
    }
    bool canDFS(vector<vector<int>>& graph, vector<int>& visited, list<int>& res, int node){
        if(visited[node]==1) {
            return true;    //TODO 不是在这里添加节点
        }else if(visited[node]==-1){
            return false;   //表示有环
        }else{
            visited[node] = -1; //表示正在访问
            for(auto& adjNode: graph[node]){
                if(!canDFS(graph, visited, res, adjNode)) return false;
            }
            visited[node] = 1;
            res.push_front(node);   //TODO 在这里添加节点
            return true;
        }
    }
};

