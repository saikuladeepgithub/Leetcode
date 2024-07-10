class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(auto log : logs)
        {
            if(log=="../")
            {
               if(count>0) count-=1;
            }
            else if(log=="./")
            {
                continue;
            }
            else
            {
                count+=1;
            }
        }
        return count;
    }
};