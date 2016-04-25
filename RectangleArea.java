package leetcode221_230;

import java.util.Arrays;

/**Find the total area covered by two rectilinear rectangles in a 2D plane.
 https://leetcode.com/problems/rectangle-area/
 * Created by eugene on 16/4/17.
 */
public class RectangleArea {

    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C-A)*(D-B);
        int s2 = (G-E)*(H-F);
        if (C<=E || G<=A || H<=B || D<=F) return s1+s2;
        int[] xs = {A, C, E, G};
        int[] ys = {B, D, F, H};
        Arrays.sort(xs);
        Arrays.sort(ys);
        int w = xs[2]-xs[1];
        int h = ys[2]-ys[1];
        return s1+s2-w*h;
    }

}
