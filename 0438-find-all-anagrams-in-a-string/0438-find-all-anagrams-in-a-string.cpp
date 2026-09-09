//take map for p and window
//update map for window at each step
//compare the maps and append the starting point likewise

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mpp;
        unordered_map<char, int> temp;
        for(int i = 0; i < p.size(); i++)   
            mpp[p[i]]++;

        vector<int> res;
        int l = 0, r = 0;
        int cnt = 0, k = p.size();

        while(r < k){
            temp[s[r]]++;
            r++;
        }

        if(temp == mpp)
            res.push_back(l);
        
        while(r < s.size()){
            temp[s[r]]++;
            temp[s[l]]--;

            if(temp[s[l]] == 0)
                temp.erase(s[l]);

            if(temp == mpp)
                res.push_back(l+1);

            r++;
            l++;
        }

        return res;
    }
};