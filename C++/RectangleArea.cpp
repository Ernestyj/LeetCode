
/**Find the total area covered by two rectilinear rectangles in a 2D plane.
 https://leetcode.com/problems/rectangle-area/
 * Created by eugene on 16/4/17.
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long areaA = (C-A)*(D-B);
        long long areaB = (G-E)*(H-F);
        long long areaOverlap = 0;
        int l = max(A,E); //overlap boundary
        int r = min(C,G);
        int t = min(D,H);
        int b = max(B,F);
        if(r>l && t>b) areaOverlap = (r-l)*(t-b);
        return areaA+areaB-areaOverlap;
    }
};
//public class RectangleArea {
//    //简洁
//    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
//        int areaA = (C-A) * (D-B);
//        int areaB = (G-E) * (H-F);
//        int l = Math.max(A, E);
//        int r = Math.min(G, C);
//        int b = Math.max(F, B);
//        int t = Math.min(D, H);
//        //If overlap
//        int overlap = 0;
//        if(r > l && t > b)
//            overlap = (r - l) * (t - b);
//        return areaA + areaB - overlap;
//    }
//
//    public int computeArea1(int A, int B, int C, int D, int E, int F, int G, int H) {
//        int s1 = (C-A)*(D-B);
//        int s2 = (G-E)*(H-F);
//        if (C<=E || G<=A || H<=B || D<=F) return s1+s2;
//        int[] xs = {A, C, E, G};
//        int[] ys = {B, D, F, H};
//        Arrays.sort(xs);
//        Arrays.sort(ys);
//        int w = xs[2]-xs[1];
//        int h = ys[2]-ys[1];
//        return s1+s2-w*h;
//    }
//
//}
