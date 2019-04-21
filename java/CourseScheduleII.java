package leetcode201_210;

import java.util.LinkedList;

/**There are a total of n courses you have to take, labeled from 0 to n - 1.
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 For example: 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 4, [[1,0],[2,0],[3,1],[3,2]]
 There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
 Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 * Created by eugene on 16/4/6.
 */
public class CourseScheduleII {

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int len = prerequisites.length;
        int[] res = new int[numCourses];
        int index = 0;
        int[] pCount = new int[numCourses];// counter for number of prerequisites
        for (int i=0; i<len; i++) pCount[prerequisites[i][0]]++;
        LinkedList<Integer> queueNoPre = new LinkedList<>();//store courses that have no prerequisites
        for (int i=0; i<numCourses; i++){
            if (pCount[i]==0) {
                queueNoPre.offer(i);
                res[index++] = i;
            }
        }
        while (!queueNoPre.isEmpty()){
            int top = queueNoPre.poll();
            for (int i=0; i<len; i++){
                if (prerequisites[i][1]==top) {
                    pCount[prerequisites[i][0]]--;  //依赖减一
                    if(pCount[prerequisites[i][0]]==0){ //若依赖清零了
                        res[index++] = prerequisites[i][0];
                        queueNoPre.add(prerequisites[i][0]);
                    }
                }
            }
        }
        if (index==numCourses) return res;    //TODO 注意不是index-1
        else return new int[0];
    }

}
