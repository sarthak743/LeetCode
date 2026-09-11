//BRUTE

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();

        for(int i=0; i < n; i++){
            if(!digits[i])
                continue;
            for(int j = 0; j < n; j++){
                if(j == i)
                    continue;
                for(int k=0; k < n; k++){
                    //can use each element once
                    //k denotes units place
                    //which cant be odd
                    if(k == i || k == j || digits[k] % 2 != 0)
                        continue;
                    int res = digits[i] * 100 + digits[j] * 10 + digits[k];
                    st.insert(res);
                }
            }
        }

        return st.size();
    }
};