
/**There are a total of n courses you have to take, labeled from 0 to n - 1.
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 For example:2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 2, [[1,0],[0,1]]
 Note: The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
 * Created by eugene on 16/4/3.
 */
class Solution {//与Course Schedule II一样
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {//判断是否是有向无环图(DAG)，BFS，拓扑排序，关键是要维护一个入度为0的顶点的集合
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        queue<int> q; //维护入度为0的顶点的队列
        for (auto edge: prerequisites) {    //重新生成标准邻接表
            graph[edge[1]].push_back(edge[0]);
            ++in[edge[0]];  //TODO 注意不是++in[edge[1]]
        }
        for (int node = 0; node < numCourses; ++node) {
            if(in[node]==0) q.push(node);
        }
        int in0Count = q.size();
        while(!q.empty()){
            int node = q.front();
            q.pop();    //移除当前in=0的节点
            for(auto adjNode: graph[node]){
                --in[adjNode]; //相关邻接节点in--
                if(in[adjNode]==0) {
                    q.push(adjNode);
                    ++in0Count;
                }
            }
        }
        return in0Count==numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {//DFS, 关键是维护visited[]防止顶点被多次访问(0还未访问过，1已经访问了，-1正在访问)
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> visited(numCourses, 0);
        for (auto edge: prerequisites) {    //重新生成标准邻接表
            graph[edge[1]].push_back(edge[0]);
        }
        for (int node = 0; node < numCourses; ++node) {
            if(!canDFS(graph, visited, node)) return false;
        }
        return true;
    }
    bool canDFS(vector<vector<int>>& graph, vector<int>& visited, int node){
        if(visited[node]==1) return true;
        else if(visited[node]==-1) return false;    //表示有环
        else{
            visited[node] = -1; //表示正在访问 TODO 多熟记理解
            for(auto adjNode: graph[node]){
                if(!canDFS(graph, visited, adjNode)) return false;
            }
            visited[node] = 1;
            return true;
        }
    }
};
//public class CourseSchedule {
//    /**
//     * http://www.programcreek.com/2014/05/leetcode-course-schedule-java/
//     * 有向图BFS(边列表):队列存没有依赖的节点
//     */
//    public boolean canFinish(int numCourses, int[][] prerequisites) {
//        int len = prerequisites.length;
//        if(numCourses==0 || len==0) return true;
//        // counter for number of prerequisites
//        int[] pCount = new int[numCourses];
//        for(int i=0; i<len; i++) pCount[prerequisites[i][0]]++;
//        //store courses that have no prerequisites
//        LinkedList<Integer> queueNoPre = new LinkedList<>();
//        for(int i=0; i<numCourses; i++){
//            if(pCount[i]==0) queueNoPre.add(i);
//        }
//        // number of courses that have no prerequisites
//        int numNoPre = queueNoPre.size();
//        while(!queueNoPre.isEmpty()){
//            int top = queueNoPre.remove();
//            for(int i=0; i<len; i++){
//                // if a course's prerequisite can be satisfied by a course in queue
//                if(prerequisites[i][1]==top){
//                    pCount[prerequisites[i][0]]--;  //依赖减一
//                    if(pCount[prerequisites[i][0]]==0){ //若依赖清零了
//                        numNoPre++;
//                        queueNoPre.add(prerequisites[i][0]);
//                    }
//                }
//            }
//        }
//        return numNoPre == numCourses;
//    }
//
//}
