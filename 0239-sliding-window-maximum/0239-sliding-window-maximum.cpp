class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int n = nums.size();

        // vector<int> res;
        // int maxi = INT_MIN;
        // for(int i=0;i<k;i++)
        // {
        //     maxi = max(maxi,nums[i]);
        // }
        // res.push_back(maxi);
        // for(int i=1;i<=n-k;i++)
        // {
        //     int count = k;
        //     int j = i;
        //     maxi = nums[i];
        //     while(count)
        //     {
        //         maxi = max(nums[j++],maxi);
        //         count--;
        //     }
        //     res.push_back(maxi);
        // }

        // return res;


        int n = nums.size();

        vector<int> res;
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }

        return res;

    }
};