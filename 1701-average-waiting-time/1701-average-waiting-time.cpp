class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int sum=customers[0][0];
        double ressum=0;
        int n=customers.size();
        for(int i=0;i<n;i++)
        {
            if(customers[i][0]<=sum)
            {
                sum+=customers[i][1];
            }
            else
            {
                sum=customers[i][0]+customers[i][1];
            }
            ressum+=sum-customers[i][0];
        }
        return ressum/n;
    }
};