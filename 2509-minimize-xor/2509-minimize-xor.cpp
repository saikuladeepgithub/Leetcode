class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int cnt = __builtin_popcount(num2);

        int bit = 31;
        int res = 0;
        while(bit>0 && cnt>0)
        {
            if((num1 & (1<<bit))!=0)
            {
                res = res | (1<<bit);
                cnt--;
            }
            bit--;
        }

        bit = 0;
        while(cnt>0)
        {
            if((res & (1<<bit)) == 0)
            {
                res = res | (1<<bit);
                cnt--;
            }
            bit++;
        }

        return res;
    }
};