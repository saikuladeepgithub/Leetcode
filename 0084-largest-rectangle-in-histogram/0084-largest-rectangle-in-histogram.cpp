class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            // if(!st.empty() && arr[i]>=arr[st.top()])
            // {
            //     st.push(i);
            //     continue;
            // }
            
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                int r = i;
                int el = arr[st.top()];
                st.pop();
                int l;
                if(st.empty()) l = -1;
                else l = st.top();
                res = max(res,((r-l-1)*el));
            }
            st.push(i);
           
        }
        while(!st.empty())
            {
                int r = n;
                int el = arr[st.top()];
                st.pop();
                int l;
                if(st.empty()) l = -1;
                else l = st.top();
                res = max(res,((r-l-1)*el));
            }

            return res;
    }
};