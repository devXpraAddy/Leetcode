// https://leetcode.com/problems/hand-of-straights/description/

// T.C  : O(nlogn) + O(n*groupSize)
// S.C  : O(n)
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();

        if (n % groupSize)
        {
            return false;
        }

        map<int, int> mp; // we are using ordered map to store the element in sorted ordere
        for (int &handNumber : hand)
        {
            mp[handNumber]++; // O(nlogn)
        }

        while (!mp.empty())
        { // O(n*groupSize)

            int curr = mp.begin()->first; //->second : frequency
                                          // next elements -> curr+1, curr+2, curr+3 .....
            for (int i = 0; i < groupSize; i++)
            {
                if (mp[curr + i] == 0)
                {
                    return false;
                }

                mp[curr + i]--;
                if (mp[curr + i] < 1)
                { // if the frequency has become zero we will erase it
                    mp.erase(curr + i);
                }
            }
        }

        return true;
    }
};