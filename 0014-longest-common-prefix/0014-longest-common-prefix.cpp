//cleaner version

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
        
            while (j < prefix.size() &&
                   j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {
                j++;
            }

            //now prefix will have substring of prefix
            //starting from index 0
            //will have in total j characters
            prefix = prefix.substr(0, j);

            //this cancel out edge case
            if (prefix.empty())
                return "";
        }

        return prefix;
    }
};