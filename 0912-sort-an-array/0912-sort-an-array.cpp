class Solution {
public:
    void heapify(vector<int> & nums,int n,int i)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[left]>nums[largest])
        {
            largest=left;
        }
        if(right<n && nums[right]>nums[largest])
        {
            largest=right;
        }
        if(largest!=i)
        {
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
    void heapsort(vector<int> & nums,int n)
    {
        for(int i=(n/2)-1;i>=0;i--)
        {
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums,nums.size());
        return nums;
    }
};