class Solution {
public:
    long long func(vector<int>& piles, long long k)
    {
        long long th=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            th=th+ceil((double)piles[i]/(double)k);
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=piles[0];
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            if(piles[i]>maxi)
            {
                maxi=piles[i];
            }
        }
        int low=1;
        int high=maxi;
        int ans;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(func(piles,mid)<=h)
            {
                ans=mid;
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