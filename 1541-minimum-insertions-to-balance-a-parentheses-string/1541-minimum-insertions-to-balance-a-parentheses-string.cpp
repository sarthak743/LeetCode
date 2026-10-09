class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int i = 0;
        string res = "";

        while(i<n-1){
            if(s[i] == '('){
                res += s[i];
                i++;
            }
            else if(s[i] == ')' && s[i]==s[i+1]){
                res += 'x';
                i = i + 2;
            }
                
            else{
                res += 'y';
                i++;
            }                
        }

        if(i<n){
            if(s[i] == '(')
                res += s[i];
            else
                res += 'y';
        }

        int open = 0, ans = 0;
        for(int i=0; i<res.size(); i++){
            if(res[i] == '(')
                open++;

            else if(res[i] == 'x'){
                if(open)
                    open--;

                else
                    ans++;
            }

            else{
                if(open){
                    open--;
                    ans++;
                }

                else
                    ans += 2;
            }
        }        

        return ans + open * 2;
    }
};