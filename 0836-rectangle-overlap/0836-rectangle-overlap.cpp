class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11 = rec1[0], y11 = rec1[1];
        int x12 = rec1[2], y12 = rec1[3];
        int x21 = rec2[0], y21 = rec2[1];
        int x22 = rec2[2], y22 = rec2[3];

        if(y12 <= y21 || y22 <= y11)
            return false;

        if(x12 <= x21 || x22 <= x11)
            return false;

        return true;
    }
};