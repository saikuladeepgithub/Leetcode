class Solution {
public:
    long long maximum(vector<int>&nums,int n)
    {
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
            {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            long long l = i - pse[i];
            long long r = nse[i] - i;
            res = res + (l*r*1LL*nums[i]);
        }

        return res;
    }
    long long minimum(vector<int>&nums,int n)
    {
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            long long l = i - pse[i];
            long long r = nse[i] - i;
            res = res + (l*r*1LL*nums[i]);
        }

        return res;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long res;
        long long n = nums.size();
        long long maxi = maximum(nums,n);
        long long mini = minimum(nums,n);

        return res = maxi - mini;
    }
};