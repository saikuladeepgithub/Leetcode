class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        sort(nums.begin(),nums.end(),[&](int a,int b)
        {
            return mpp[a]>mpp[b];
        });
        set<int> st;

        for(int i=0;i<nums.size();i++)
        {
            
                st.insert(nums[i]);
                if(st.size()==k)
                    break;
    
        }
        vector<int> res(st.begin(),st.end());
        return res;


        
        
    }
};