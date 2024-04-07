class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int m=nums.size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=i;j<m;j++)
            {
                sum=sum+nums[j];
                if(sum==k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};