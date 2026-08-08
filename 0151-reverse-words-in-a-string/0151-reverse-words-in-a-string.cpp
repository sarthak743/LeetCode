//iterate from back
//store the word (string until we get " ") in dummy
//reverse dummy and append it to result with " "
//lastly remove last " " from result

class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string result = "";

        while(i >= 0){
            while(i >= 0 && s[i] == ' ')  
            i--;

            string dummy = "";
            while(i >= 0 && s[i] != ' '){
                dummy += s[i];
                i--;
            }

            reverse(dummy.begin(), dummy.end());
            if(!dummy.empty()){
                result += dummy;
                result += " ";
            }
        }

        if(!result.empty())  result.pop_back();
        return result;
    }
};