class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), i = 0;
        sort(strs.begin(), strs.end());
        
        while(i < min(strs[0].size(), strs[n-1].size())){
            if(strs[0][i] != strs[n-1][i])
                break;
            i++;
        }

        return strs[0].substr(0, i);
    }
};