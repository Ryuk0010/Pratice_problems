class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dx, dy;
        if(xCenter < x1) dx = x1;
        else if(xCenter > x2) dx = x2;
        else dx = xCenter;

        if(yCenter < y1) dy = y1;
        else if(yCenter > y2) dy = y2;
        else dy = yCenter;

        return ((xCenter - dx)*(xCenter - dx) +((yCenter - dy)*(yCenter - dy)) <= radius*radius)? true: false; 
    }
};