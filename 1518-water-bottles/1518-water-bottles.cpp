class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=numBottles;
        while(numBottles>=numExchange)
        {
            res+=numBottles/numExchange;
            int extraempty=numBottles%numExchange;
            numBottles=(numBottles/numExchange)+extraempty;
        }
        return res;
    }
};