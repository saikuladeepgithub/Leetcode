class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count=0;
        int n=rating.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    if(rating[i]<rating[j] && rating[j]<rating[k])
                    {
                        count+=1;
                    }
                    if(rating[i]>rating[j] && rating[j]>rating[k])
                    {
                        count+=1;
                    }
                }
            }
        }
        return count;
    }
};