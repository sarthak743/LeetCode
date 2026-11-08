class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> res;
        int l = 0, r = 0, n = s1.size();

        while(l < n && r < n){
            if(s1[r] == s2[r]){
                if(l != r)
                    res.push_back({s1.substr(l, r-l), s2.substr(l, r-l)});

                r++;
                l = r;
            }

            else
                r++;
        }

        if(l != r)
            res.push_back({s1.substr(l, r-l), s2.substr(l, r-l)});

        return res;
    }
};