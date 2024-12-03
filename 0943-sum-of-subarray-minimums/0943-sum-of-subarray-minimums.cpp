class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // int sum = 0;
        // int n = arr.size();
        // for(int i=0;i<arr.size();i++)
        // {
        //     for(int j = i;j<n;j++)
        //     {
        //         int mini = arr[j];
        //         for(int k=i;k<=j;k++)
        //         {
        //             mini = min(mini,arr[k]);
        //         }
        //         sum = (mini + sum)%(1000000007);
        //     }
        // }

        // return sum;

        int sum = 0;

        // finding nse

        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> prev(n);
        stack<int> stt;
        for(int i=0;i<n;i++)
        {
            while(!stt.empty() && arr[stt.top()]>arr[i])
                stt.pop();
            prev[i] = stt.empty() ? -1 : stt.top();
            stt.push(i);
        }
        int mod = (int)(1e9+7);
        for(int i=0;i<n;i++)
        {
            int l = i - prev[i];
            int r = nse[i] - i;
            sum = (sum + (l*r*1LL*arr[i])%mod)%mod;
        }

        return sum;
    }
};