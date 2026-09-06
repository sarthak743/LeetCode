class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        int n = words.size();
        unordered_map<char, int> mpp;
        vector<string> result;

        string row0 = "qwertyuiopQWERTYUIOP";
        string row1 = "asdfghjklASDFGHJKL";
        string row2 = "zxcvbnmZXCVBNM";

        // Map all chars from row0 -> 0
        for (char c : row0) mpp[c] = 0;

        // Map all chars from row1 -> 1
        for (char c : row1) mpp[c] = 1;

        // Map all chars from row2 -> 2
        for (char c : row2) mpp[c] = 2;

        for(int i=0; i<n; i++)
        {
           int dup = i;
           bool erase = false;

           for(int j=0; j < words[i].size() - 1; j++)
           {
                if(mpp[words[i][j]] != mpp[words[i][j+1]])
                {
                    erase = true;
                    break;
                }
           }    

           if(erase == false)
           {
                result.push_back(words[i]);
           }                    
        }

        return result;
    }
};