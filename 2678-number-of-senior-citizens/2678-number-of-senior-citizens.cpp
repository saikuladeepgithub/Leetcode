class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int count=0;
        for(auto detail : details)
        {
            int tens=detail[11]-'0';
            int ones=detail[12]-'0';
            int age=(tens*10)+ones;
            if(age>60) count+=1;
        }
        return count;
    }
};