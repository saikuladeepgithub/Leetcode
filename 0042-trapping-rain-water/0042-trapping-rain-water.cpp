class Solution {
public:
    int trap(vector<int>& height) {
        
        // int n = height.size();
        // vector<int> prefix(n);
        // vector<int> suffix(n);
        // prefix[0] = height[0];
        // for(int i=1;i<n;i++)
        // {
        //     prefix[i] = max(prefix[i-1],height[i]);
        // }

        // suffix[n-1] = height[n-1];

        // for(int i=n-2;i>=0;i--)
        // {
        //     suffix[i] = max(suffix[i+1],height[i]);
        // }

        // int total = 0;
        // for(int i=0;i<n;i++)
        // {
        //     total += min(prefix[i],suffix[i])-height[i];
        // }

        // return total;




        // optimal approach

        int l = 0, r = height.size()-1;
        int lmax=0,rmax = 0;
        int total = 0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=lmax) lmax = height[l];
                else total += lmax - height[l];
                l = l + 1;
            }
            else
            {
                if(height[r]>=rmax) rmax = height[r];
                else total += rmax - height[r];
                r = r - 1;
            }
        }

        return total;
    }
};