class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        long nn=n;
        if(nn<0) 
        {
            nn*=-1;
        }
        while(nn>0)
        {
            if(nn%2==0)
            {
                x=x*x;
                nn/=2;
            }
            else
            {
                res=res*x;
                nn-=1;
            }
        }
        if(n<0) return (double) 1.0/res;
        return res;
    }
};