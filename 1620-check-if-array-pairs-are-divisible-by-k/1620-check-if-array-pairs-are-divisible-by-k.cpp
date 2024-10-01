class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
           int remainder = ((arr[i]%k)+k)%k;
           mpp[remainder]+=1;
        }
        if(mpp[0]%2!=0) return false;
        for(int i=1;i<k;i++)
        {
            int comp = k-i;
            if(mpp[i]!=mpp[comp]) return false;
        }
        return true;

    }
};