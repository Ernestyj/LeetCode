

/**You are playing the following Nim Game with your friend: There is a heap of stones on the table,
 each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone
 will be the winner. You will take the first turn to remove the stones.

 Both of you are very clever and have optimal strategies for the game.
 Write a function to determine whether you can win the game given the number of stones in the heap.

 For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2,
 or 3 stones you remove, the last stone will always be removed by your friend.
 Hint:
 If there are 5 stones in the heap, could you figure out a way to remove the stones such that
 you will always be the winner?
 * Created by eugene on 16/5/28.
 */
class Solution {
public:
    //我们来generalize一下这道题，当可以拿1～n个石子时，那么个数为(n+1)的整数倍时一定会输，我们试着证明一下这个结论，若当前共有m*(n+1)个石子，那么：
    //当m=1时，即剩n+1个的时候，肯定会输，因为不管你取1～n中的任何一个数字，另一个人都可以取完。
    //当m>1时，即有m*(n+1)的时候，不管你先取1～n中的任何一个数字x，另外一个人一定会取n+1-x个，这样总数就变成了(m-1)*(n+1)，
    //第二个人就一直按这个策略取，那么直到剩n+1个的时候，就便变成m=1的情况，一定会输。
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};
//public class NimGame {
//
//    //从1~7,8,9出发,找到规律:4的倍数个一定输
//    public boolean canWinNim(int n) {
//        return n%4 != 0;
//    }
//
//}
