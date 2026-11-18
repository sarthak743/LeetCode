class Solution {
public:
    int minChanges(string s) {
        int i = 0, n = s.size(), res = 0;
        while(i<n){
            if(s[i] != s[i+1])
                res++;
            i = i + 2;
        }
        return res;
    }
};