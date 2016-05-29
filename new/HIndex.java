package leetcode271_280;

import java.util.Arrays;

/**Given an array of citations (each citation is a non-negative integer) of a researcher,
 write a function to compute the researcher's h-index. According to the definition of h-index on Wikipedia: "A scientist has index h
 if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

 For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total
 and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers
 with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

 Note: If there are several possible values for h, the maximum one is taken as the h-index.
 * Created by eugene on 16/5/17.
 */
public class HIndex {

    //https://segmentfault.com/a/1190000003794831
    //借助额外数组, 时间O(N), 空间O(N)
    public int hIndex(int[] citations) {
        int N = citations.length;
        if(N<1) return 0;
        //counts[i]表示有多少文章被引用了i次，这里如果一篇文章引用大于N次，我们就将其当为N次，因为H指数不会超过文章的总数。
        int[] counts = new int[N+1];
        for(int cit: citations) {
            if(cit>N) counts[N]++;
            else counts[cit]++;
        }
        int sum = 0;
        //如果遍历到某一个引用次数时，大于或等于该引用次数的文章数量>=引用次数本身，则认为这是H指数。
        for(int k=N; k>=0; k--) {
            sum += counts[k];
            if(sum>=k) return k;
        }
        return 0;
    }

    //先排序, 时间O(NlogN), 空间O(1)
    public static int hIndex1(int[] citations) {
        int len = citations.length;
        if (len==0) return 0;
        Arrays.sort(citations);
        int h = 0;
        for (int i=0; i<len; i++){
            int currH = Math.min(citations[i], len-i);  //得到当前的H指数
            if(currH>h) h = currH;
        }
        return h;
    }

}
