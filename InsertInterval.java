package leetcode51_60;

import java.util.ArrayList;
import java.util.LinkedList;
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

    public static class Interval {
        int start;
        int end;
        Interval() { start = 0; end = 0; }
        Interval(int s, int e) { start = s; end = e; }
    }

    /**
     * https://leetcode.com/problems/insert-interval/
     * 简洁,清晰
     * @param intervals
     * @param newInterval
     * @return
     */
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        Interval span = newInterval;
        List<Interval> result = new LinkedList<>();
        int i = 0;
        while (i<intervals.size() && intervals.get(i).end<span.start)
            result.add(intervals.get(i++));
        while (i<intervals.size() && intervals.get(i).start<=span.end) {//merge all overlapping intervals
            span = new Interval(
                    Math.min(span.start, intervals.get(i).start),
                    Math.max(span.end, intervals.get(i).end));
            i++;
        }
        result.add(span); // add the union of intervals we got
        while (i<intervals.size()) result.add(intervals.get(i++));// add all the rest
        return result;
    }


    //快速.先将待插入区间加入原区间数组,再遍历区间数组进行合并.
    public List<Interval> insert1(List<Interval> intervals, Interval newInterval) {
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
