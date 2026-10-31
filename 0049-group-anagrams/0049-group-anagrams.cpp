class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;

        for(int i=0; i<strs.size(); i++){
            string a = strs[i];
            sort(a.begin(), a.end());

            mpp[a].push_back(strs[i]);            
        }

        for(auto i : mpp)
            res.push_back(i.second);

        return res;
    }
};