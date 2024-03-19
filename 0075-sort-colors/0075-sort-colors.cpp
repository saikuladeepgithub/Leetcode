#include <bits/stdc++.h>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i;j<nums.size();j++)
        //     {
        //         if(nums[i]>nums[j])
        //         {
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // // }
        // int count0=0;
        // int count1=0;
        // int count2=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==0)
        //     {
        //         count0=count0+1;
        //     }
        //     else if(nums[i]==1)
        //     {
        //         count1=count1+1;
        //     }
        //     else
        //     {
        //         count2=count2+1;
        //     }
        // }
        // for(int i=0;i<count0;i++)
        // {
        //     nums[i]=0;
        // }
        // for(int i=count0;i<count0+count1;i++)
        // {
        //     nums[i]=1;
        // }
        // for(int i=count0+count1;i<nums.size();i++)
        // {
        //     nums[i]=2;
        // }
        // Dutch national flag algorithm
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low=low+1;
                mid=mid+1;
            }
            else if(nums[mid]==1)
            {
                mid=mid+1;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high=high-1;
            }
        }
    }
};