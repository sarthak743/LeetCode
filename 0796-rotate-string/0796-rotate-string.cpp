//if goal is rotation of s
//then it must exist in s + s

//js like mp.find() != mp.end()
//here we have
//s.find(goal) != string::npos

//npos    -->   no position found

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        string a = s + s;

        //return bool value
        return (a.find(goal) != string::npos);
    }
};