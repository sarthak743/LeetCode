//BRUTE FORCE
//since distinct is asked we use set
//our sliding window technique wont work since it count same subarrays too

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n =nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++){ 
            int cnt = 0;
            vector<int> temp;
            for(int j = i; j < n; j++){
                if(nums[j] % p == 0)    
                    cnt++;

                temp.push_back(nums[j]);

                if(cnt <= k)
                    st.insert(temp);
            }
        }

        return st.size();
    }
};