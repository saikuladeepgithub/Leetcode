class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {

        int sum = 0;
        int lsum = 0;
        int rsum = 0;
        int r = cardPoints.size()-1;
        int l = 0;
        for(l=0;l<k;l++)
        {
            lsum += cardPoints[l];
        }
        sum = lsum;
        l = k-1;
        for(int i=0;i<k;i++)
        {
            lsum -= cardPoints[l--];
            rsum += cardPoints[r--];
            sum = max(sum,lsum+rsum);
        }
        return sum;
    }
};