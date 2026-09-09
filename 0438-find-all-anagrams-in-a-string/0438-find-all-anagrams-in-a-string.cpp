//take map for p and window
//update map for window at each step
//compare the maps and append the starting point likewise

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int l = 0, r = 0;
        vector<int> res;
        vector<int> hashs (26, 0);
        vector<int> hashp (26, 0);

        for(int i=0; i < k; i++)
            hashp[p[i] - 'a']++;

        while(r < s.size()){
            hashs[s[r] - 'a']++;

            if((r - l + 1) > k){
                hashs[s[l] - 'a']--;
                l++;
            }

            if(hashs == hashp)
                res.push_back(l);

            r++;
        }

        return res;
    }
};