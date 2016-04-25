package leetcode51_60;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * Created by DCLab on 12/10/2015.
 */
public class InsertInterval {

    public static void main(String[] args) {
        List<Interval> intervals = new ArrayList<>();
        intervals.add(new Interval(0, 2));
        intervals.add(new Interval(3, 5));
        intervals.add(new Interval(6, 8));
        Interval newInterval = new Interval(4, 7);
        System.out.println("*****RESULT*****");
        List<Interval> result = new InsertInterval().insert(intervals, newInterval);
        for (Interval interval : result){
            System.out.print("[" + interval.start + "," + interval.end + "] ");
        }
    }


    public static class Interval {
        int start;
        int end;
        Interval() { start = 0; end = 0; }
        Interval(int s, int e) { start = s; end = e; }
    }


    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new ArrayList<>();
        if (intervals == null || intervals.size() == 0){
            result.add(newInterval);
            return result;
        }
        //将newInterval插入到intervals TODO 边界条件极易出错
        boolean isEnd = true;
        for (int i = 0; i < intervals.size(); i++){
            if (newInterval.start <= intervals.get(i).start){
                intervals.add(i, newInterval);
                isEnd = false;
                break;
            }
        }
        if (isEnd) intervals.add(newInterval);

        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        for (Interval interval : intervals){
            if (interval.start > end){
                result.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            } else {
                if (interval.end > end){
                    end = interval.end;
                }
            }
        }
        result.add(new Interval(start, end));
        return result;
    }
}
