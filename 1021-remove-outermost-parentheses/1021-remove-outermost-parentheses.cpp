//we will have variable "sum" which will act as depth of paranthesis
//while iterating
//if we get "(" we check the sum if its positive then add it into answer and sum++
//if we get ")" we sum-- then check if sum is positive if yes then add it else no

class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum = 0, i = 0;
        string result = "";

        while (i < s.size()) {
            if (s[i] == '(') {
                if (sum > 0)
                    result += s[i];
                sum++;
            }

            else {
                sum--;
                if (sum > 0)
                    result += s[i];
            }

            i++;
        }

        return result;
    }
};