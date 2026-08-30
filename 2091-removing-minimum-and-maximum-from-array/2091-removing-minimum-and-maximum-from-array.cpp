//here only 3 cases r possible
//1. removing both from front 
//2. removing both from end
//3. removing one from front other from end

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        //large and small
        int l = -1, s = -1;
        int n = nums.size();
        int lar = INT_MIN, smal = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums[i] > lar){
                lar = nums[i];
                l = i;
            }
            
            if(nums[i] < smal){
                smal = nums[i];
                s = i;
            }
        }

        int res = -1;
        //3 cases
        int t1 = min(((l+1) + (n-s)), ((s+1) + (n-l)));     //3rd case
        int t2 = max(l+1, s+1);     //1st case
        int t3 = max(n-l, n-s);     //2nd case

        //return the minimum of all
        res = min({t1, t2, t3});
        return res;
    }
};