//cleaner hash method

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mpp1(256, 0);
        vector<int> mpp2(256, 0);

        if(s.size() != t.size())    return false;

        for(int i = 0; i < s.size(); i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }       

        //return true if both hash table are equal
        return mpp1 == mpp2;
    }
};