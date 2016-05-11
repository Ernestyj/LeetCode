package leetcode51_60;

import java.util.*;

/**
 * Given a collection of intervals, merge all overlapping intervals.
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 注意：输入集合不一定是按区间首部排序的。
 * Created by DCLab on 12/9/2015.
 */
public class MergeIntervals {

    public static class Interval {
        int start;
        int end;
        Interval() { start = 0; end = 0; }
        Interval(int s, int e) { start = s; end = e; }
    }

    //简洁
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals.size() <= 1) return intervals;
        Collections.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return Integer.compare(i1.start, i2.start);
            }
        });
        List<Interval> result = new LinkedList<>();
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        for (Interval interval : intervals) {
            if (interval.start <= end) // Overlapping intervals, move the end if needed
                end = Math.max(end, interval.end);
            else {                     // Disjoint intervals, add the previous one and reset bounds
                result.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        result.add(new Interval(start, end));   // Add the last interval
        return result;
    }

    //麻烦,但速度稍快一点
    public List<Interval> merge1(List<Interval> intervals) {
        List<Interval> result = new ArrayList<>();
        if (intervals == null || intervals.size() == 0) return result;
        HashMap<Integer, Interval> map = new HashMap<>();
        for (Interval interval : intervals){
            if (!map.containsKey(interval.start)) map.put(interval.start, interval);
            else {
                Interval oldInterval = map.get(interval.start);
                if (oldInterval.end < interval.end){
                    map.replace(oldInterval.start, interval);
                }
            }
        }
        List<Integer> sortedIntegers = new ArrayList<Integer>(map.keySet());
        Collections.sort(sortedIntegers);

        Interval firstInterval = map.get(sortedIntegers.get(0));
        int start = firstInterval.start;
        int end = firstInterval.end;
        for (Integer i : sortedIntegers){
            Interval interval = map.get(i);
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
