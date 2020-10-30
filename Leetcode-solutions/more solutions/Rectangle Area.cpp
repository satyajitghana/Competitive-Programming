/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45

Note:

Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F); 
    if (A >= G || C <= E || D <= F || B >= H)
        return s1 + s2; 
    return s1 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)) + s2;
}
};