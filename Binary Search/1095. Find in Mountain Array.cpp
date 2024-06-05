// https://leetcode.com/problems/find-in-mountain-array/description/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// Brute Forece

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        for (int i = 0; i < n; i++)
        {
            if (mountainArr.get(i) == target)
            {
                return i;
            }
        }
        return -1;
    }
};

// Approach - Solving using Binary Search
// T.C : log(n)
// S.C : O(1)
class Solution
{
public:
    // This function is already taught in my YouTube Video - https://www.youtube.com/watch?v=Op07kT-LoH8 ("Peak Index in a Mountain Array")
    int peakIndexInMountainArray(MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int l = 0;
        int r = n - 1;

        while (l < r)
        {

            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int binarySearch(MountainArray &mountainArr, int l, int r, int target)
    {

        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }

    int reverseBinarySearch(MountainArray &mountainArr, int l, int r, int target)
    {
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            { // Because the array in right side of peak is in descending order
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int peakIndex = peakIndexInMountainArray(mountainArr);

        int idx = binarySearch(mountainArr, 0, peakIndex, target);

        if (idx == -1)
        {
            return reverseBinarySearch(mountainArr, peakIndex, n - 1, target);
        }

        return idx;
    }
};
