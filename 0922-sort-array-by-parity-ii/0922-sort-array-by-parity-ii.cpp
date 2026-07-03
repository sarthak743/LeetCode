//brute force
//put number in even places if its even otherwise at odd places

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);       //to make vector of n zeroes first declare size then value (0) in brackets
        int i = 0, j = 0, k = 1;

        while(i < n){
            if(nums[i] % 2 == 0){
                result[j] = nums[i];
                j = j + 2;
            }

            else{
                result[k] = nums[i];
                k = k + 2;
            }

            i++;
        }

        return result;
    }
};