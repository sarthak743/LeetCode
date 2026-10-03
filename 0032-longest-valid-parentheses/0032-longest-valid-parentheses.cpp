//used editorial
//stack of indices

//initialise stack with -1
//1. if open bracket then push its index
//2. if close bracket pop
//2a. if stack becomes empty push that index

//if close bracket after poping
//update result with (i - top)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        stack<int> st;
        st.push(-1);

        for(int i=0; i<n; i++){
            if(s[i] == '(')
                st.push(i);

            else{
                st.pop();
                if(st.empty())
                    st.push(i);

                res = max(res, i - st.top());
            }
        }

        return res;
    }
};