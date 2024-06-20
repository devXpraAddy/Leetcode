// https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20

class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();
        while (l < r)
        {
            int mid = r - (r - l) / 2;
            if (count(position, mid) >= m)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

private:
    int count(vector<int> &position, int d)
    {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i)
        {
            if (position[i] - cur >= d)
            {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
};

// Alternate solution

class Solution
{
public:
    bool check(int x, vector<int> &A, int m)
    {
        int m_placed = 1, last_pos = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            if ((A[i] - last_pos) >= x)
            {
                if (++m_placed == m)

                    return true;
                last_pos = A[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int> &A, int m)
    {
        sort(A.begin(), A.end());
        long long low = 1, high = *max_element(A.begin(), A.end()), mid, ans = 0;
        while (high >= low)
        {
            mid = (high + low) / 2;
            if (check(mid, A, m))
            {
                low = mid + 1;
                ans = mid;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};