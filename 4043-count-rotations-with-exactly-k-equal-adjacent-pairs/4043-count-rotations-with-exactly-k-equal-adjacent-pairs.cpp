class Solution {
public:
    string reverse(string a){
        char b = a[a.size() - 1];
        a.pop_back();

        return b + a;
    }
    
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        string dup = "", a = "";
        
        for(int i = 0; i < n; i++){
            a = reverse(s);
            if(i)
                a = reverse(dup);
            int res = 0;
            for(int i = 0; i < n-1; i++){
                if(a[i] == a[i+1])
                    res++;
            }

            if(res == k)
                cnt++;

            dup = a;
        }    

        return cnt;
    }
};