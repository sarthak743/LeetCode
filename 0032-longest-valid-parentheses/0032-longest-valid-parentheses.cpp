//two pointers approach

//iterate from left to right
//inc open for (
//inc close for )
//when open == close update res with 2*open
//when close > open reset both 

//do same from right to left
//but reset when open > close

//we need to do two passes
//coz by one pass it might miss valid parenthesis
//which can be covered by other pass

//reset open and close 
//prevents invalid parenthesis (just like how we did in generate parenthesis)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), open = 0, close = 0, res = 0;

        //LEFT  -->  RIGHT
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                open++;
            else
                close++;

            if(open == close)
                res = max(res, open*2);
            
            if(close > open)
                open = 0, close = 0;
        }

        //RIGHT  -->  LEFT
        open = 0, close = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(')
                open++;
            else
                close++;    

            if(open == close)
                res = max(res, open*2);

            if(open > close)
                open = 0, close = 0;
        }

        return res;
    }
};