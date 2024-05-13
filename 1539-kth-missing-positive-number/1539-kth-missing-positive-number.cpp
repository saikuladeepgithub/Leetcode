#include <bits/stdc++.h>
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi=arr[0];
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                k=k+1;
            }
            else
            {
                break;
            }
        }
        return k;
    }
};