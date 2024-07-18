// https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150
/*
    The widest container (using first and last line) is a good candidate, because of its width.
    Its water level is the height of the smaller one of first and last line. All other containers
    are less wide and thus would need a higher water level in order to hold more water. The smaller
    one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
*/

// Approach-1 (Two pointer Greedy (O(N))
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0, j = n - 1;

        int water = 0;
        while (i < j)
        {

            // start from the smallest one and calculate water
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            water = max(water, area);

            if (height[i] < height[j])
                i++; // if the height is less then we will increase that
            else
                j--;
        }

        return water;
    }
};
