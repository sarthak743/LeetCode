//just like for longest valid parenthesis
//we will do two passes

//doing one pass misses some bracket pairs

//from left to right, at end we check if we hv more aste than open
//if not false else check next condition

//from right to left, same condition js check for close 
//if not false else true

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        stack<int> st1;
        int cnt1 = 0;       //count of aste from left to right

        for(int i=0; i<n; i++){
            if(s[i] == '*')
                cnt1++;

            else if(s[i] == '(')
                st1.push(s[i]);

            else{
                if(!st1.empty())
                    st1.pop();
                else if(cnt1)
                    cnt1--;
                else 
                    return false;
            }
        }

        stack<int> st2;
        int cnt2 = 0;       //count of aste from right to left

        for(int i=n-1; i>=0; i--){
            if(s[i] == '*')
                cnt2++;

            else if(s[i] == ')')
                st2.push(s[i]);

            else{
                if(!st2.empty())
                    st2.pop();
                else if(cnt2)
                    cnt2--;
                else
                    return false;
            }
        }
        
        //if there are less * than remaining unmatched open then false
        //same for closing 
        if(cnt1 < st1.size() || cnt2 < st2.size())
            return false;

        return true;
    }
};