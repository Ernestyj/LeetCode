
/**You are a product manager and currently leading a team to develop a new product.
 Unfortunately, the latest version of your product fails the quality check. Since each version
 is developed based on the previous version, all the versions after a bad version are also bad.
 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
 which causes all the following ones to be bad.

 You are given an API bool isBadVersion(version) which will return whether version is bad.
 Implement a function to find the first bad version. You should minimize the number of calls to the API.
 * Created by eugene on 16/5/19.
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m = 0;
        while (l+1<r){
            m = l+(r-l)/2;
            if(isBadVersion(m)) r = m;
            else l = m;
        }
        if(isBadVersion(l)) return l;
        if(isBadVersion(r)) return r;
        return -1;
    }

    int firstBadVersion(int n) {
        int l = 1, r = n, m;
        while (l<=r){
            m = l+(r-l)/2;
            if(isBadVersion(m)) r = m-1;
            else l = m+1;
        }
        return l;
    }
};
//public class FirstBadVersion {
//
//    /* The isBadVersion API is defined in the parent class VersionControl.
//      boolean isBadVersion(int version); */
//    private class VersionControl {
//        boolean isBadVersion(int version){
//            return false;
//        }
//    }
//
//
//    /**
//     * 注意m = (l+r)/2与m = l+(r-l)/2的区别,后者可以避免溢出
//     */
//    public class Solution extends VersionControl {
//        //简洁
//        public int firstBadVersion1(int n) {
//            int l = 1, r = n;
//            int m = 0;
//            while (l<r){    //TODO 注意不是l<=r
//                m = l+(r-l)/2;
//                if (isBadVersion(m)){
//                    r = m;
//                } else
//                    l = m+1;
//            }
//            return l;
//        }
//
//        public int firstBadVersion(int n) {
//            int l = 1, r = n;
//            int m = 0;
//            int result = n;
//            while (l<=r){
//                m = l+(r-l)/2;    //TODO 不能使用m = (l+r)/2, 否则会溢出
//                if (isBadVersion(m)){
//                    if (result>m) result = m;
//                    r = m-1;
//                } else
//                    l = m+1;
//            }
//            return result;
//        }
//    }
//
//
//
//}
