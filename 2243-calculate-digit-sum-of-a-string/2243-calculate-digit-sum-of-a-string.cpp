class Solution {
public:
    string digitSum(string s, int k) {
        string res = s;

        while(res.size() > k){
            string ans = "";
            int sum = 0, i = 0, n = res.size();

            while(i<n){
                int a = k;
                while(i<n && a--){
                    sum += res[i] - '0';
                    i++;
                }
                ans += to_string(sum);
                sum = 0;
            }

            res = ans;
        }        

        return res;
    }
};