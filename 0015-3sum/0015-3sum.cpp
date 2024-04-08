class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector <int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
            }
        }
        return ans;
        // better solution
        // set<vector<int>> ans;
        // for(int i=0;i<nums.size();i++)
        // {
        //     set <int> hashset;
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         int third=-(nums[i]+nums[j]);
        //         if(hashset.find(third)!=hashset.end())
        //         {
        //             vector <int> temp={nums[i],nums[j],third};
        //             sort(temp.begin(),temp.end());
        //             ans.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector <vector<int>> res(ans.begin(),ans.end());
        // return res;
    }
};