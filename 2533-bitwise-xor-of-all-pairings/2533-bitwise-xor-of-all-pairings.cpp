class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        // int res = 0;
        // for(int i=0;i<nums1.size();i++)
        // {
        //     int num = nums1[i];
        //     for(int j=0;j<nums2.size();j++)
        //     {
        //         res = res ^ (nums2[j] ^ num);
        //     }
        // }
        // cout << (10 ^ 2 ^ 5 ^ 0);
        // return res;


        // optimised way
        int res = 0;

       if(nums1.size()%2)
       {
         for(int i=0;i<nums2.size();i++)
        {
            res = res ^ nums2[i];
        }
        
       }
        if(nums2.size()%2)
        {
            for(int i=0;i<nums1.size();i++)
            {
                res = res ^ nums1[i];
            }
        }

        return res;

    }
};