//similar to binary subarray with sum
//get count of subarray with atmost 3 char
//get count of subarray with atmost 2 char
//their difference is result

class Solution {
public:
    int maxcount(string a, int k){
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<char, int> mpp;
        
        while(r < a.size()){
            mpp[a[r]]++;
            
            while(mpp.size() > k){
                mpp[a[l]]--;
                if(mpp[a[l]] == 0)
                    mpp.erase(a[l]);
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) {
        return maxcount(s, 3) - maxcount(s, 2);
    }
};