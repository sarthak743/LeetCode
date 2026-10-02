//cleaner version

class Solution {
public:
    void recursion(int open, int close, int k, vector<string>& res, string b){
        //if string has equal open and close
        //also they r equal to k then append
        if(open == k && close == k){
            res.push_back(b);
            return;
        }

        //append opening brackets 
        //until we get k open brackets
        if(open < k)
            recursion(open+1, close, k, res, b + '(');

        //this PREVENTS invlaid parentheses
        //moment we get more or equal close than open even we stop 
        //more precisely we dont do further recursion call
        if(close < open)
            recursion(open, close+1, k, res, b + ')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string a = "";

        recursion(0, 0, n, res, a);                          

        return res;
    }
};