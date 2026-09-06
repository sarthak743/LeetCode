class Solution {
public:
    string rotate(string a){
        reverse(a.begin(), a.end());
        reverse(a.begin() + 1, a.end());
        return a;
    }
    
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        string a = s;
        
        for(int i = 0; i < n; i++){
            int res = 0;
            for(int i = 0; i < n-1; i++){
                if(a[i] == a[i+1])
                    res++;
            }

            if(res == k)
                cnt++;

            a = rotate(a);
        }    

        return cnt;
    }
};