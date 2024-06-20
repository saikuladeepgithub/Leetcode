class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int low=1;
        sort(position.begin(),position.end());
        int high=position[position.size()-1]-position[0];
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int lastball=position[0];
            int balls=1;
            for(int i=1;i<position.size();i++)
            {
                if(position[i]-lastball>=mid)
                {
                    lastball=position[i];
                    balls=balls+1;
                }
            }
            if(balls>=m)
            {
                res=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
};