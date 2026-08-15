//sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, 0);
        if(s.size() == 0 || s.size() == 1)  return s.size();

        int l = 0, r = 0;
        int result = 0;
        while(r < s.size()){
            mpp[s[r]]++;

            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }

            r++;

            //since we increment r before this line
            //we update result as  (r - l)
            result = max(result, r - l);    
        }

        return result;
    }
};