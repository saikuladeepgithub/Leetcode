class Solution {
public:
    int numberOfChild(int n, int k) {
        int i=0;
        while(k>0)
        {
            while(k>0 && i<n-1)
            {
                i++;
                k--;
            }
            if(k==0) return i;
            while(k>0 && i>0)
            {
                i--;
                k--;
            }
            if(k==0) return i;
        }
        return 0;
    }
};