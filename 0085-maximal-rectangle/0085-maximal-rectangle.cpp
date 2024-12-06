class Solution {
public:
        int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && arr[i]>=arr[st.top()])
            {
                st.push(i);
                continue;
            }
            
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int res = 0;
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i>=1)prefix[i][j] = prefix[i-1][j] + 1;
                    else prefix[i][j] = 1;
                }
                else prefix[i][j] = 0;
            }
        }

        for(int i=0;i<n;i++)
        {
            res = max(res,largestRectangleArea(prefix[i]));
        }

        return res;
    }
};