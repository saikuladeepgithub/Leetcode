class Solution {
public:
    vector<string>result;
    void backtrack(int left,int right,string output,int n)
    {
        if(left==right && right==n)
        {
            result.push_back(output);
            return;
        }
        if(left<n)
        {
            backtrack(left+1,right,output+'(',n);
        }
        if(right<left)
        {
            backtrack(left,right+1,output+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,"",n);
        return result;
    }
};