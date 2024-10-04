class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long prod = 0;

        int n = skill.size();

        sort(skill.begin(),skill.end());
        int sum = skill[0] + skill[n-1];
        for(int i=0;i<n/2;i++)
        {
            if(skill[i]+skill[n-i-1]!=sum) return -1;
            prod = prod + (long long) skill[i]*skill[n-i-1];
        }

        return prod;
    }
};