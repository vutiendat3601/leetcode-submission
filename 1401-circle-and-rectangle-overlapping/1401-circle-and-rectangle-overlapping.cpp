class Solution {
public:
    int sqr(int x) { return x * x; }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int dx = max(max(x1 - xCenter, 0), xCenter - x2),
            dy = max(max(y1 - yCenter, 0), yCenter - y2);
        return sqr(radius) >= sqr(dx) + sqr(dy);
    }
};