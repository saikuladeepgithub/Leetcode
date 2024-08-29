class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;
        int twenties=0;
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5) fives+=1;
            else if(bills[i]==10)
            {
            
                if(fives>0)
                {
                    tens+=1;
                    fives-=1;
                }
                else return false;
            }
            else
            {
                if(fives>0 && tens>0)
                {
                    fives-=1;
                    tens-=1;
                    twenties+=1;
                }
                else if(fives>=3)
                {
                    fives-=3;
                    twenties+=1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};