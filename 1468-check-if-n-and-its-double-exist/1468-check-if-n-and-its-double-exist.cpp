class Solution {
public:
    bool bs(vector<int> & arr,int el,int ind)
    {
        int i = 0;
        int j = arr.size() - 1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(el==arr[mid] && ind!=mid) return true;
            if(el<arr[mid]) j = mid-1;
            else i = mid+1; 
        }

        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(bs(arr,2*arr[i],i)) return true;
        }

        return false;
    }

  
};