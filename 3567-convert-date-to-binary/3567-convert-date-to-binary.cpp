
class Solution {
public:
    string convertDateToBinary(string date) {
        int year,month,day;
        int n=date.size();
        year=stoi(date.substr(0,4));
        month=stoi(date.substr(5,2));
        day=stoi(date.substr(8,2));
        string yearbin=bitset<32>(year).to_string();
        string monthbin=bitset<32>(month).to_string();
        string daybin=bitset<32>(day).to_string();
        yearbin=yearbin.substr(yearbin.find('1'));
        monthbin=monthbin.substr(monthbin.find('1'));
        daybin=daybin.substr(daybin.find('1'));
        return yearbin+"-"+monthbin+"-"+daybin;
    }
};