
/**
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's
 * in their binary representation and return them as an array.
Example 1:
Input: 2
Output: [0,1,1]
Example 2:
Input: 5
Output: [0,1,1,2,1,2]
Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n)
 /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */

class Solution {
public:
    /**规律: 每个i值都是 i&(i-1) 对应的值加1 (i>=1)
i    binary '1'  i&(i-1)
0    0000    0
-----------------------
1    0001    1    0000
-----------------------
2    0010    1    0000
3    0011    2    0010
-----------------------
4    0100    1    0000
5    0101    2    0100
6    0110    2    0100
7    0111    3    0110
-----------------------
8    1000    1    0000
9    1001    2    1000
10   1010    2    1000
11   1011    3    1010
12   1100    2    1000
13   1101    3    1100
14   1110    3    1100
15   1111    4    1110
     */
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i=1; i<=num; ++i){  //TODO 注意一定从i=1开始
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }

    vector<int> countBits(int num) {//built-in 作弊
        vector<int> res;
        for (int i = 0; i <= num; ++i) {
            res.push_back(bitset<32>(i).count());
        }
        return res;
    }
};