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

        stack<char> st;
        int ans = 0;
        for(int i=0; i<res.size(); i++){
            if(res[i] == '(')
                st.push(res[i]);

            else if(res[i] == 'x'){
                if(!st.empty())
                    st.pop();

                else
                    ans++;
            }

            else{
                if(!st.empty()){
                    st.pop();
                    ans++;
                }

                else
                    ans += 2;
            }
        }        

        return ans + st.size() * 2;
    }
};