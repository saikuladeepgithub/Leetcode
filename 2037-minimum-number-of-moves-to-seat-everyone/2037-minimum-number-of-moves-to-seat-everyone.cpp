class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int moves=0;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]>students[i]) moves=moves+(seats[i]-students[i]);
            else moves=moves+(students[i]-seats[i]);
        }
        return moves;
    }
};