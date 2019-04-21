package leetcode201_210;

import java.util.LinkedList;

/**There are a total of n courses you have to take, labeled from 0 to n - 1.
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 For example:2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 2, [[1,0],[0,1]]
 Note: The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
 * Created by eugene on 16/4/3.
 */
public class CourseSchedule {

    /**
     * http://www.programcreek.com/2014/05/leetcode-course-schedule-java/
     * 有向图BFS(边列表):队列存没有依赖的节点
     * @param numCourses
     * @param prerequisites
     * @return
     */
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int len = prerequisites.length;
        if(numCourses==0 || len==0) return true;
        // counter for number of prerequisites
        int[] pCount = new int[numCourses];
        for(int i=0; i<len; i++) pCount[prerequisites[i][0]]++;
        //store courses that have no prerequisites
        LinkedList<Integer> queueNoPre = new LinkedList<>();
        for(int i=0; i<numCourses; i++){
            if(pCount[i]==0) queueNoPre.add(i);
        }
        // number of courses that have no prerequisites
        int numNoPre = queueNoPre.size();
        while(!queueNoPre.isEmpty()){
            int top = queueNoPre.remove();
            for(int i=0; i<len; i++){
                // if a course's prerequisite can be satisfied by a course in queue
                if(prerequisites[i][1]==top){
                    pCount[prerequisites[i][0]]--;  //依赖减一
                    if(pCount[prerequisites[i][0]]==0){ //若依赖清零了
                        numNoPre++;
                        queueNoPre.add(prerequisites[i][0]);
                    }
                }
            }
        }
        return numNoPre == numCourses;
    }

}
