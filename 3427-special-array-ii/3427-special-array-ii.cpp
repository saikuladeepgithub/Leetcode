class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int> count;
        count.push_back(0);
        for(int i=1;i<n;i++)
        {
            count.push_back(count[i-1]+(nums[i]%2==nums[i-1]%2));
        }
        int m = queries.size();
        vector<bool> res(m,0);

        for(int i=0;i<m;i++)
        {
            res[i] = (count[queries[i][1]]-count[queries[i][0]]) ?  false : true;
        }

        return res;
    }
};