class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        while(time>0)
        {
            while(i<n && time>0)
            {
                time--;
                i++;
            }
            while(i>1 && time>0)
            {
                time--;
                i--;
            }
        }
        return i;
    }
};