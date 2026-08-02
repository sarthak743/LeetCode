class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);          //convert num into string
        for(int i = 0; i < s.size(); i++){      //replace the very first occurence of 6 with 9 and return
            if(s[i] == '6'){
                s[i] = '9';
                return stoi(s);
            }
        }
        return stoi(s);
    }
};