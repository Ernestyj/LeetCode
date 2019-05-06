#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

/**Reverse digits of an integer.
 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * Created by eugene on 16/4/20.
 */
class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while(x!=0){
            rev = rev*10 + x%10;
            x = x/10;
            if(rev>INT_MAX || rev<INT_MIN){
                return 0;
            }
        }
        return static_cast<int>(rev);
    }
};

//int main(){
//    Solution s;
//    cout<< s.reverse(123)<<endl;
//    cout<< pow(2,31)<<endl;
//    cout<< INT_MAX;
//}