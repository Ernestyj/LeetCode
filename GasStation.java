package leetcode131_140;

/**There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 You have a car with an unlimited gas tank and it costs cost[i] of gas to
 travel from station i to its next station (i+1). You begin the journey
 with an empty tank at one of the gas stations.
 Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 Note: The solution is guaranteed to be unique.
 * Created by eugene on 16/2/22.
 */
public class GasStation {

    /**
     * 贪心:关键是要可以总结出来这道题目的属性，注意Note这个地方，其属性主要有两个：
     1 如果总的gas - cost小于零的话，那么没有解返回-1;
     2 如果前面所有的gas - cost加起来小于零，那么前面所有的点都不能作为出发点。
     http://blog.csdn.net/kenden23/article/details/14106137
     * @param gas
     * @param cost
     * @return
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int remaining = 0;
        int start = 0;
        int curRemaining = 0;
        int totalRemaining = 0;
        for (int i=0; i<gas.length; i++){
            remaining = gas[i]-cost[i];
            if (curRemaining>=0) curRemaining += remaining;
            else{
                curRemaining = remaining;
                start = i;
            }
            totalRemaining += remaining;
        }
        if (totalRemaining < 0) return -1;
        else return start;
    }

}
