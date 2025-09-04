class Solution {
public:
    int findClosest(int x, int y, int z) {
        int timeTakenX = 0; int timeTakenY = 0;
        timeTakenX = abs(z - x);
        timeTakenY = abs(z - y);

        if (timeTakenX < timeTakenY) return 1;
        else if (timeTakenX > timeTakenY) return 2;
        else return 0;
    }
};