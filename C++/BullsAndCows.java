package leetcode291_300;

import java.util.HashMap;

/**You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to
 guess what the number is. Each time your friend makes a guess, you provide a hint that indicates
 how many digits in said guess match your secret number exactly in both digit and position (called "bulls")
 and how many digits match the secret number but locate in the wrong position (called "cows").
 Your friend will use successive guesses and hints to eventually derive the secret number.
 For example:
 Secret number:  "1807"
 Friend's guess: "7810"
 Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 Write a function to return a hint according to the secret number and friend's guess, use A to
 indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

 Please note that both secret number and friend's guess may contain duplicate digits, for example:
 Secret number:  "1123"
 Friend's guess: "0111"
 In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
 You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
 * Created by eugene on 16/5/31.
 */
public class BullsAndCows {

    /**https://leetcode.com/discuss/67031/one-pass-java-solution
     * tricky方法: 一次遍历, bull直接统计,同时用一个数组记录数字出现频数,secret中的出现+1,guess中的出现-1.
     * @param secret
     * @param guess
     * @return
     */
    public String getHint(String secret, String guess) {
        int bull = 0, cow = 0;
        int[] counts = new int[10];
        for (int i=0; i<secret.length(); i++){
            int s = Character.getNumericValue(secret.charAt(i));
            int g = Character.getNumericValue(guess.charAt(i));
            if (s==g) bull++;
            else {  //TODO 注意此处tricky方法
                if (counts[s]<0) cow++;
                if (counts[g]>0) cow++;
                counts[s]++;
                counts[g]--;
            }
        }
        return bull+"A"+cow+"B";
    }

    //两次遍历, 第一遍统计bull及secret出现字符频数,第二遍统计cow.
    public String getHint2(String secret, String guess) {
        int bull = 0, cow = 0;
        HashMap<Character, Integer> cToCount = new HashMap<>();
        for (int i=0; i<secret.length(); i++){
            char c = secret.charAt(i), g = guess.charAt(i);
            if (c==g) bull++;
            else {
                if (!cToCount.containsKey(c)) cToCount.put(c, 1);
                else cToCount.put(c, cToCount.get(c)+1);
            }
        }
        for (int i=0; i<secret.length(); i++){
            char c = secret.charAt(i), g = guess.charAt(i);
            if (c!=g){
                if (cToCount.containsKey(g)){
                    cow++;
                    int temp = cToCount.get(g);
                    if (temp==1) cToCount.remove(g);
                    else cToCount.put(g, temp-1);
                }
            }
        }
        return bull+"A"+cow+"B";
    }

}
