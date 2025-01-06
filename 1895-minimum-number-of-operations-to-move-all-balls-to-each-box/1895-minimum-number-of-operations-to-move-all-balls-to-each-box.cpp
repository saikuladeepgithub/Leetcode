class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        map<int,bool> mpp;
        int n = boxes.size();
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='0') mpp[i] = false;
            else mpp[i] = true;
        }

        vector<int> res(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mpp[j])
                {
                    res[i] += abs(i-j);
                }
            }
        }

        return res;
        
    }
};