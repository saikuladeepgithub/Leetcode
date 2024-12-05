class Solution {
public:
    bool canChange(string start, string target) {
        
        int i = 0;
        int j = 0;

        int n = start.size();

        while(i<n || j<n)
        {
            while(i<n && start[i]=='_') i = i + 1;
            while(j<n && target[j] == '_') j = j + 1;

            if(start[i]!=target[j]) return false;
            if(start[i]=='L' && i<j) return false;
            if(start[i]=='R' && i>j) return false;

            i = i + 1;
            j = j + 1;
        }

        return true;
    }
};