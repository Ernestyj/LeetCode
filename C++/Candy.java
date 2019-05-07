package leetcode131_140;

/**There are N children standing in a line. Each child is assigned a rating value.
 You are giving candies to these children subjected to the following requirements:
 Each child must have at least one candy.
 Children with a higher rating get more candies than their neighbors.
 What is the minimum candies you must give?
 * Created by eugene on 16/2/23.
 */
public class Candy {

    /**
     * 涉及相邻元素问题,类似Trapping Rain Water,总体思路也是从左从右双向遍历.
     * 贪心:只要遇到更大的相邻值,则可以加一;但要总数最小,则需按升序来加一.
     首先从左向右遍历,升序加一;再从右向左遍历,升序加一.
     http://www.programcreek.com/2014/03/leetcode-candy-java/
     * @param ratings
     * @return
     */
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        candies[0] = 1;
        int total = candies[0];
        for (int i=1; i<ratings.length; i++){
            if (ratings[i-1]<ratings[i]){
                candies[i] = candies[i-1]+1;
            } else {
                candies[i] = 1;
            }
            total += candies[i];
        }
        for (int i=ratings.length-2; i>=0; i--){
            if (ratings[i]>ratings[i+1]){
                if (! (candies[i]>candies[i+1])) {
                    int old = candies[i];   //TODO 易错(用例[5,3,1]),并非新增值都是1,应存储原值,用以计算新增值
                    candies[i] = candies[i+1]+1;
                    total += candies[i]-old;
                }
            }
        }
        return total;
    }

}
