class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=INT_MIN,el2=INT_MIN;
        int cnt1=0,cnt2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=el2)
            {
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1)
            {
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(el1==nums[i]) cnt1++;
            if(el2==nums[i]) cnt2++;
        }
        vector <int> res;
        if(cnt1>n/3) res.push_back(el1);
        if(cnt2>n/3) res.push_back(el2);
        return res;
    }
};