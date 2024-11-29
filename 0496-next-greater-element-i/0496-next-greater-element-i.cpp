class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int> st;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--)
        {
            int el = nums2[i];
            while(!st.empty() && st.top()<=el)
            {
                st.pop();
            }
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        vector<int> res(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            res[i] = mpp[nums1[i]];
        }

        return res;

    }
};