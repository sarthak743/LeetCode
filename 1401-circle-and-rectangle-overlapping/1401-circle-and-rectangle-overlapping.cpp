//get point on rectangle closest to circle
//if its distance from center is lesser than equal to radius then true

//if center is between x1 and x2 take coord of center
//if center is on right of both take x2
//else take x1

//same for y

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //coord of closest point
        int x = -1, y = -1;

        if(x1 <= xCenter && xCenter <= x2)
            x = xCenter;
        else if(x1 <= x2 && x2 <= xCenter)
            x = x2;
        else
            x = x1;

        if(y1 <= yCenter && yCenter <= y2)
            y = yCenter;
        else if(y1 <= y2 && y2 <= yCenter)
            y = y2;
        else
            y = y1;

        int dist = (x-xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter); 
        return dist <= radius * radius;
    }
};