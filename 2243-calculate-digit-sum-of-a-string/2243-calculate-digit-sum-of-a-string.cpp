class Solution {
public:
    string digitSum(string s, int k) {
        string res = s, ans = "";

        while(res.size() > k){
            vector<int> arr;
            for(int i=0; i<res.size(); i++)
                arr.push_back(res[i] - '0');

            vector<int> temp;
            int n = arr.size(), i = 0, sum = 0;

            while(i<n){
                int a = k;
                while(i<n && a--){
                    sum += arr[i];
                    i++;
                }
                temp.push_back(sum);
                sum = 0;                
            }

            arr = temp;

            string ans = "";
            for(int i=0; i<arr.size(); i++)
                ans += to_string(arr[i]);

            res = ans;
        }        

        return res;
    }
};