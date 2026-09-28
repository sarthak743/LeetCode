class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), res = 0;

        for(int i=0; i < n; i++){
            vector<int> hash(26, 0);

            for(int j=i; j < n; j++){
                hash[s[j] - 'a']++;
                
                int maxx = INT_MIN, minn = INT_MAX;
                for(int i=0; i < 26; i++){
                    if(hash[i]){
                        maxx = max(maxx, hash[i]);
                        minn = min(minn, hash[i]);
                    }
                }

                res += (maxx - minn);
            }
        }
        
        return res;
    }
};