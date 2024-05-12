class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=m*1LL*k*1LL;
        if((val)>n) return -1;
        int mini=bloomDay[0];
        int maxi=bloomDay[0];
        int res=-1;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mini)
            {
                mini=bloomDay[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]>=maxi)
            {
                maxi=bloomDay[i];
            }
        }
        int low=mini;
        int high=maxi;
        while(low<=high)
        {
            
            int mid=(low+high)/2;
            int count=0;
            int bqs=0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid)
                {
                    count=count+1;
                    // if(count==k)
                    // {
                    //     bqs=bqs+1;
                    //     count=0;
                    // }
                }
                else
                {
                    bqs=bqs+(count/k);
                    count=0;
                }
            }
            bqs=bqs+(count/k);
            if(bqs>=m)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};