//took a bit help from gpt

//count minimum number of removals from string

//at each parenthese two options of take or dont
//when we take inc open or close and make recursive call

//when we dont take that means we remove that elemnet
//there dec min_rem and do further recursion

//after whole string is scanned i.e at lowest level of recursion
//if min_rem is 0 for string we will add it 

//if for strings close > open OR min_rem gets negative
//end the recursive call there no need to move ahead from there

//edge case
//suppose "(()"
//here removing first or second "(" individually results in same valid parenthesis = "()"
//so we need to handle duplicates which are consecutive
//(we somehow handled duplicates idk how T-T)

class Solution {
public:
    void recursion(int i, int open, int close, int min_rem, string&curr, vector<string>&r, string&arr, bool lastnottaken){
        if(i == arr.size() && min_rem == 0 && open == close)
            r.push_back(curr);

        if(i >= arr.size() || close > open || min_rem < 0)
            return;

        curr += arr[i];
        if(arr[i] == '('){
            recursion(i+1, open+1, close, min_rem, curr, r, arr, false);

            curr.pop_back();
            // duplicate handling
            if(i == 0 || arr[i] != arr[i-1] || lastnottaken)
                recursion(i+1, open, close, min_rem - 1, curr, r, arr, true);
        }

        else if(arr[i] == ')'){
            recursion(i+1, open, close+1, min_rem, curr, r, arr, false);

            curr.pop_back();
            // duplicate handling
            if(i == 0 || arr[i] != arr[i-1] || lastnottaken)
                recursion(i+1, open, close, min_rem - 1, curr, r, arr, true);
        }

        else{
            recursion(i+1, open, close, min_rem, curr, r, arr, false);
            curr.pop_back();
        }
            
    }

    vector<string> removeInvalidParentheses(string s) {
        int a = 0, mini = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')
                a++;
            else if(s[i] == ')'){
                if(a)
                    a--;
                else
                    mini++;
            }
        }

        mini += a;      //this have minimum number of removals to get valid parenthesis

        vector<string> res;
        string temp = "";

        recursion(0, 0, 0, mini, temp, res, s, false);

        return res;    
    }
};