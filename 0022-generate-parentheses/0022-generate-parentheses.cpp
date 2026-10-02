//we got two options at each position
//append '(' and open++
//other append ')' and close++
//then check string at each step and append like wise
//we stop the moment open and close exceeds n

class Solution {
public:
    //valid parenthesis
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            else if(!st.empty()){
                if(s[i] == ')' && st.top() != '(')
                    return false;
                if(s[i] == '}' && st.top() != '{')
                    return false;
                if(s[i] == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
            else
                return false;
        }

        if(st.empty())
            return true;
        return false;
    }

    void recursion(int open, int close, int k, vector<string>& res, string b){
        //check string at each step
        //if its valid and has k open brackets then append
        if(isValid(b) && open == k)
                res.push_back(b);

        //we dont want more k open or close brackets
        if(open > k || close > k){
            return;
        }

        //append '(' 
        //and do recursive call
        b += '(';
        recursion(open + 1, close, k , res, b);

        //backtracking 
        //remove '(' and append ')'
        //then do recursive call
        b.pop_back();
        b += ')';
        recursion(open, close + 1, k, res, b);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string a = "(";     

        recursion(1, 0, n, res, a);                          

        return res;
    }
};