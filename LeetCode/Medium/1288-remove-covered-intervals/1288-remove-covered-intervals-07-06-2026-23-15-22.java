import java.util.*;

class Solution {

    public boolean isOverlap(int[] i1, int[] i2) {
        if (i2[1] <= i1[1] && i2[0] >= i1[0]) {
            return true;
        } else {
            return false;
        }
    }

    public int removeCoveredIntervals(int[][] intervals) {

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1];  // bigger end first
            } else {
                return a[0] - b[0];  // smaller start first
            }
        });

        int[] prev = intervals[0];
        int count = 1;

        for (int i = 1; i < intervals.length; i++) {
            int[] curr = intervals[i];

            if (!isOverlap(prev, curr)) {
                count++;
                prev = curr;
            }
        }

        return count;
    }
}