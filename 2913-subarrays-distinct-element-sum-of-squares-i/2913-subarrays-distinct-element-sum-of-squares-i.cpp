class Solution {
public:
    int distinct(int a, int b, vector<int> arr){
        unordered_map<int, int> mpp;
        for(int i=a; i<=b; i++)
            mpp[arr[i]]++;

        return mpp.size();
    }

    int sumCounts(vector<int>& nums) {
        int res = 0;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                res += (distinct(i, j, nums)) * (distinct(i, j, nums));
            }
        }

        return res;
    }
};