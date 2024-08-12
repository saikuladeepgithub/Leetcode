class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto ele:nums)
        {
           add(ele);
        }
    }
    
    int add(int val) {
       if(minHeap.size()<k)
       {
           minHeap.push(val);
       }
        else if(val>minHeap.top())
        {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */