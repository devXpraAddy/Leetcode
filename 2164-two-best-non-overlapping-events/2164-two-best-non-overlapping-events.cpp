class Solution {
public:
    //TC O(nlogn)
    //SC O(n)
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0;int n=events.size();
        //increasing order of startime
        sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])
            {
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });

        vector<int> mxright(n);
        mxright[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
            mxright[i] = max(events[i][2],mxright[i+1]);
        }
       
        for(int i=0;i<n;i++)
        {
            int endTime = events[i][1];
            int l = i+1,r=n-1;
            int p=-1;
            while(l<=r)
            {
                int m = l+(r-l)/2; //m=(l+r)/2
                if(events[m][0]>endTime)
                {
                    p = m;
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            if(p!=-1)
            {
                ans = max(ans,events[i][2]+mxright[p]);
            }
            ans = max(ans,events[i][2]);
        }
        return ans;
    }
};
