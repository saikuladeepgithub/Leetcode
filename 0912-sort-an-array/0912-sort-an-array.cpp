class Solution {
public:
    // void heapify(vector<int> & nums,int n,int i)
    // {
    //     int largest=i;
    //     int left=2*i+1;
    //     int right=2*i+2;
    //     if(left<n && nums[left]>nums[largest])
    //     {
    //         largest=left;
    //     }
    //     if(right<n && nums[right]>nums[largest])
    //     {
    //         largest=right;
    //     }
    //     if(largest!=i)
    //     {
    //         swap(nums[largest],nums[i]);
    //         heapify(nums,n,largest);
    //     }
    // }
    // void heapsort(vector<int> & nums,int n)
    // {
    //     for(int i=(n/2)-1;i>=0;i--)
    //     {
    //         heapify(nums,n,i);
    //     }
    //     for(int i=n-1;i>0;i--)
    //     {
    //         swap(nums[i],nums[0]);
    //         heapify(nums,i,0);
    //     }
    // }
    void mergesort(vector<int> & nums,int low,int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    void merge(vector<int> & nums,int low,int mid,int high)
    {
        int n1=mid-low+1;
        int n2=high-mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=low;i<=mid;i++)
        {
            left[i-low]=nums[i];
        }
        for(int i=mid+1;i<=high;i++)
        {
            right[i-(mid+1)]=nums[i];
        }
        int i=0;
        int j=0;
        int k=low;
        while(i<n1 && j<n2)
        {
            if(left[i]<right[j])
            {
                nums[k++]=left[i++];
            }
            else
            {
                nums[k++]=right[j++];
            }
        }
        while(i<n1)
        {
            nums[k++]=left[i++];
        }
        while(j<n2)
        {
            nums[k++]=right[j++];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // heapsort(nums,nums.size());
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};