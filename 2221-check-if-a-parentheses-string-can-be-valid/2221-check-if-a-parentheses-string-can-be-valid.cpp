class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        stack<int> lockedopen;
        stack<int> unlocked;

        int n = s.size();
        if(n%2)
            return false;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
                unlocked.push(i);
            else if(s[i]=='(')
                lockedopen.push(i);
            else
            {
                // locked and closing

                if(!lockedopen.empty())
                    lockedopen.pop();
                else
                {
                    if(!unlocked.empty())
                        unlocked.pop();
                    else
                        return false;
                }
            }
        }

        while(!lockedopen.empty() && !unlocked.empty() && lockedopen.top() < unlocked.top())
        {
            lockedopen.pop();
            unlocked.pop();
        }

        return lockedopen.empty();


    }
};