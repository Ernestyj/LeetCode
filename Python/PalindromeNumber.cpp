using namespace std;

/**Determine whether an integer is a palindrome. Do this without extra space.
 * Coud you solve it without converting the integer to a string?
 * Created by eugene on 16/5/31.
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        else if(x<0) return false;
        else{
            return x==reverse(x);
        }
    }

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
