class Solution {
public:
    int func(vector<int>& weights,int capacity)
    {
        int n=weights.size();
        int days=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count=count+weights[i];
            if(count==capacity)
            {
                days=days+1;
                count=0;
            }
            else if(count>capacity)
            {
                days=days+1;
                count=weights[i];
            }
        }
        if(count!=0)
        {
        days=days+1;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxi=weights[0];
        for(int i=0;i<n;i++)
        {
            sum=sum+weights[i];
            if(weights[i]>=maxi)
            {
                maxi=weights[i];
            }
        }
        if(days==1) return sum;
        int low=maxi;
        int high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int res=func(weights,mid);
            if(res<=days)
            {
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